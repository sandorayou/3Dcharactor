#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <CoreImage/CoreImage.h>
#import "UnityInterface.h"
#import <MediaPipeTasksVision/MediaPipeTasksVision.h>

#include "PrivacyMosaicCore.h"
#include <atomic>
#include <cmath>
#include <cstdint>
#include <map>
#include <mutex>
#include <vector>
#include <algorithm>
#include <limits>
static constexpr int kInferenceSize = 256;
struct LetterboxGeometry {
    int sourceWidth;
    int sourceHeight;
    int left;
    int top;
    double scale;
    int frameNumber;
};
static std::mutex s_geometryMutex;
static std::map<long long, LetterboxGeometry> s_frameGeometry;
static std::atomic<long long> s_orientationReadyTimestamp{0};
static AVCaptureSession *s_session;
static AVCaptureVideoDataOutput *s_output;
static dispatch_queue_t s_queue;
static PrivacyMosaic::SkinClassifier s_skinClassifier(107.f,157.f,6.f,7.f);
static std::atomic<bool> s_captureStopping{false};
static MPPPoseLandmarker *s_landmarker;
static MPPHandLandmarker *s_handLandmarker;
static MPPFaceLandmarker *s_faceLandmarker;
static NSString *s_unityObject;
static long long s_frame;
static long long s_lastInferenceTimestamp;
static BOOL s_useFrontCamera = YES;
static CGFloat s_mosaicScale = 48.0;
static CALayer *s_backgroundLayer;
static CIContext *s_ciContext;
static CFTimeInterval s_lastBackgroundFrame;
// Keep the last frame that was successfully privacy-masked. A detector can
// miss a frame without making the previously safe camera image unsafe.
static UIImage *s_lastSafeBackgroundImage;
static NSArray<NSValue *> *s_posePrivacyPoints;
static NSArray<NSValue *> *s_handPrivacyPoints;
static NSArray<NSValue *> *s_facePrivacyPoints;
static NSInteger s_handPrivacyTimestamp, s_facePrivacyTimestamp;
static NSInteger s_posePrivacyTimestamp;
static UIInterfaceOrientation s_lastVideoOrientation = UIInterfaceOrientationUnknown;
static void UpdateVideoOrientation(void);
static NSMutableDictionary<NSNumber *, NSMutableDictionary *> *s_pendingFramePackets;
static NSMutableDictionary<NSNumber *, NSDictionary *> *s_poseWristsByTimestamp;
static NSMutableDictionary<NSNumber *, MPPHandLandmarkerResult *> *s_pendingHandResults;
static NSMutableDictionary<NSString *, NSDictionary *> *s_handTrackState;

// Match python-tracker/pose_estimator.py: resize to the fit size with area
// filtering, center on a black square, and put any odd extra pixel on the
// bottom/right. Keep geometry per timestamp so all three results use the same
// source dimensions and capture rotation cannot mix coordinate systems.
static bool MakeSquareInferenceBuffer(CVPixelBufferRef source,
                                      CVPixelBufferRef *squareBuffer,
                                      LetterboxGeometry *geometry) {
    if (source == nullptr || squareBuffer == nullptr || geometry == nullptr) return false;
    const int width = (int)CVPixelBufferGetWidth(source);
    const int height = (int)CVPixelBufferGetHeight(source);
    if (width <= 0 || height <= 0 ||
        CVPixelBufferGetPixelFormatType(source) != kCVPixelFormatType_32BGRA) return false;

    const double scale = std::min((double)kInferenceSize / width,
                                  (double)kInferenceSize / height);
    const int scaledWidth = std::max(1, std::min(kInferenceSize,
        (int)std::nearbyint(width * scale)));
    const int scaledHeight = std::max(1, std::min(kInferenceSize,
        (int)std::nearbyint(height * scale)));
    const int left = (kInferenceSize - scaledWidth) / 2;
    const int top = (kInferenceSize - scaledHeight) / 2;

    NSDictionary *attributes = @{
        (id)kCVPixelBufferIOSurfacePropertiesKey: @{},
        (id)kCVPixelBufferMetalCompatibilityKey: @YES
    };
    CVPixelBufferRef output = nullptr;
    if (CVPixelBufferCreate(kCFAllocatorDefault, kInferenceSize, kInferenceSize,
                            kCVPixelFormatType_32BGRA,
                            (__bridge CFDictionaryRef)attributes, &output) != kCVReturnSuccess)
        return false;
    if (CVPixelBufferLockBaseAddress(source, kCVPixelBufferLock_ReadOnly) != kCVReturnSuccess) {
        CVPixelBufferRelease(output);
        return false;
    }
    if (CVPixelBufferLockBaseAddress(output, 0) != kCVReturnSuccess) {
        CVPixelBufferUnlockBaseAddress(source, kCVPixelBufferLock_ReadOnly);
        CVPixelBufferRelease(output);
        return false;
    }

    const uint8_t *input = static_cast<const uint8_t *>(CVPixelBufferGetBaseAddress(source));
    uint8_t *pixels = static_cast<uint8_t *>(CVPixelBufferGetBaseAddress(output));
    const size_t inputStride = CVPixelBufferGetBytesPerRow(source);
    const size_t outputStride = CVPixelBufferGetBytesPerRow(output);
    if (input == nullptr || pixels == nullptr || inputStride < (size_t)width * 4 ||
        outputStride < (size_t)kInferenceSize * 4) {
        CVPixelBufferUnlockBaseAddress(output, 0);
        CVPixelBufferUnlockBaseAddress(source, kCVPixelBufferLock_ReadOnly);
        CVPixelBufferRelease(output);
        return false;
    }

    // OpenCV's three-channel zero border corresponds to opaque black in BGRA.
    for (int y = 0; y < kInferenceSize; ++y) {
        uint8_t *row = pixels + (size_t)y * outputStride;
        for (int x = 0; x < kInferenceSize; ++x) {
            row[x * 4 + 0] = row[x * 4 + 1] = row[x * 4 + 2] = 0;
            row[x * 4 + 3] = 255;
        }
    }

    // Pixel-area integration matches INTER_AREA for this downscale while
    // avoiding a second image-processing runtime in the iOS build.
    const double scaleX = (double)width / scaledWidth;
    const double scaleY = (double)height / scaledHeight;
    for (int y = 0; y < scaledHeight; ++y) {
        const double y0 = y * scaleY, y1 = (y + 1) * scaleY;
        const int sourceY0 = (int)std::floor(y0);
        const int sourceY1 = std::min(height, (int)std::ceil(y1));
        for (int x = 0; x < scaledWidth; ++x) {
            const double x0 = x * scaleX, x1 = (x + 1) * scaleX;
            const int sourceX0 = (int)std::floor(x0);
            const int sourceX1 = std::min(width, (int)std::ceil(x1));
            double sums[3] = {0.0, 0.0, 0.0};
            for (int sourceY = sourceY0; sourceY < sourceY1; ++sourceY) {
                const double weightY = std::min(y1, sourceY + 1.0) - std::max(y0, (double)sourceY);
                const uint8_t *inputRow = input + (size_t)sourceY * inputStride;
                for (int sourceX = sourceX0; sourceX < sourceX1; ++sourceX) {
                    const double weightX = std::min(x1, sourceX + 1.0) - std::max(x0, (double)sourceX);
                    const double weight = weightX * weightY;
                    const uint8_t *pixel = inputRow + (size_t)sourceX * 4;
                    for (int channel = 0; channel < 3; ++channel)
                        sums[channel] += pixel[channel] * weight;
                }
            }
            uint8_t *destination = pixels + (size_t)(top + y) * outputStride + (size_t)(left + x) * 4;
            const double area = scaleX * scaleY;
            for (int channel = 0; channel < 3; ++channel)
                destination[channel] = (uint8_t)std::max(0.0, std::min(255.0,
                    std::nearbyint(sums[channel] / area)));
            destination[3] = 255;
        }
    }

    CVPixelBufferUnlockBaseAddress(output, 0);
    CVPixelBufferUnlockBaseAddress(source, kCVPixelBufferLock_ReadOnly);
    *squareBuffer = output;
    *geometry = {width, height, left, top, scale, 0};
    return true;
}

static void RememberFrameGeometry(long long timestamp, const LetterboxGeometry &geometry) {
    std::lock_guard<std::mutex> lock(s_geometryMutex);
    s_frameGeometry[timestamp] = geometry;
    while (s_frameGeometry.size() > 64) s_frameGeometry.erase(s_frameGeometry.begin());
}

static bool GeometryForFrame(long long timestamp, LetterboxGeometry *geometry) {
    std::lock_guard<std::mutex> lock(s_geometryMutex);
    auto found = s_frameGeometry.find(timestamp);
    if (found == s_frameGeometry.end()) return false;
    *geometry = found->second;
    return true;
}

static CGPoint RestoreOriginalImagePoint(CGFloat x, CGFloat y, const LetterboxGeometry &geometry) {
    return CGPointMake((x * kInferenceSize - geometry.left) /
                           (geometry.scale * geometry.sourceWidth),
                       (y * kInferenceSize - geometry.top) /
                           (geometry.scale * geometry.sourceHeight));
}
template<typename T> static T ClampColour(T value, T low, T high) {
    return std::max(low, std::min(high, value));
}
static NSObject *PrivacyGate() {
    static NSObject *gate;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ gate = [NSObject new]; });
    return gate;
}

static NSDictionary *HeadRotationFromFaceMatrix(MPPTransformMatrix *matrix) {
    if (matrix == nil || matrix.rows < 3 || matrix.columns < 3) return nil;
    double r[3][3];
    for (NSUInteger row = 0; row < 3; ++row)
        for (NSUInteger column = 0; column < 3; ++column)
            r[row][column] = [matrix valueAtRow:row column:column];
    // Newton polar decomposition produces the same nearest orthogonal matrix as
    // Windows' U @ Vh SVD scale removal, without adding another native library.
    for (NSUInteger iteration = 0; iteration < 12; ++iteration) {
        double determinant =
            r[0][0] * (r[1][1] * r[2][2] - r[1][2] * r[2][1]) -
            r[0][1] * (r[1][0] * r[2][2] - r[1][2] * r[2][0]) +
            r[0][2] * (r[1][0] * r[2][1] - r[1][1] * r[2][0]);
        if (std::fabs(determinant) < 1e-12) return nil;
        double inverseTranspose[3][3] = {
            {(r[1][1]*r[2][2]-r[1][2]*r[2][1])/determinant, (r[1][2]*r[2][0]-r[1][0]*r[2][2])/determinant, (r[1][0]*r[2][1]-r[1][1]*r[2][0])/determinant},
            {(r[0][2]*r[2][1]-r[0][1]*r[2][2])/determinant, (r[0][0]*r[2][2]-r[0][2]*r[2][0])/determinant, (r[0][1]*r[2][0]-r[0][0]*r[2][1])/determinant},
            {(r[0][1]*r[1][2]-r[0][2]*r[1][1])/determinant, (r[0][2]*r[1][0]-r[0][0]*r[1][2])/determinant, (r[0][0]*r[1][1]-r[0][1]*r[1][0])/determinant}
        };
        double maximumDelta = 0;
        for (NSUInteger row = 0; row < 3; ++row)
            for (NSUInteger column = 0; column < 3; ++column) {
                const double next = .5 * (r[row][column] + inverseTranspose[row][column]);
                maximumDelta = std::max(maximumDelta, std::fabs(next - r[row][column]));
                r[row][column] = next;
            }
        if (maximumDelta < 1e-12) break;
    }
    const double axis[3] = {1, -1, -1};
    for (NSUInteger row = 0; row < 3; ++row)
        for (NSUInteger column = 0; column < 3; ++column)
            r[row][column] *= axis[row] * axis[column];
    double x, y, z, w;
    double trace = r[0][0] + r[1][1] + r[2][2];
    if (trace > 0) {
        double scale = std::sqrt(trace + 1) * 2;
        w = .25 * scale; x = (r[2][1] - r[1][2]) / scale;
        y = (r[0][2] - r[2][0]) / scale; z = (r[1][0] - r[0][1]) / scale;
    } else if (r[0][0] > r[1][1] && r[0][0] > r[2][2]) {
        double scale = std::sqrt(1 + r[0][0] - r[1][1] - r[2][2]) * 2;
        x = .25 * scale; y = (r[0][1] + r[1][0]) / scale;
        z = (r[0][2] + r[2][0]) / scale; w = (r[2][1] - r[1][2]) / scale;
    } else if (r[1][1] > r[2][2]) {
        double scale = std::sqrt(1 + r[1][1] - r[0][0] - r[2][2]) * 2;
        x = (r[0][1] + r[1][0]) / scale; y = .25 * scale;
        z = (r[1][2] + r[2][1]) / scale; w = (r[0][2] - r[2][0]) / scale;
    } else {
        double scale = std::sqrt(1 + r[2][2] - r[0][0] - r[1][1]) * 2;
        x = (r[0][2] + r[2][0]) / scale; y = (r[1][2] + r[2][1]) / scale;
        z = .25 * scale; w = (r[1][0] - r[0][1]) / scale;
    }
    double norm = std::sqrt(x*x + y*y + z*z + w*w);
    if (norm < 1e-12) return nil;
    return @{@"x": @(x/norm), @"y": @(y/norm), @"z": @(z/norm), @"w": @(w/norm)};
}

static CGColorSpaceRef PrivacySRGB() {
    static CGColorSpaceRef space;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ space=CGColorSpaceCreateWithName(kCGColorSpaceSRGB); });
    return space;
}
static CIImage *WindowsStyleMosaic(CIImage *source, CGFloat scale) {
    int w=(int)source.extent.size.width,h=(int)source.extent.size.height;
    CVPixelBufferRef pixels=nullptr;
    if(CVPixelBufferCreate(kCFAllocatorDefault,w,h,kCVPixelFormatType_32BGRA,nullptr,&pixels)!=kCVReturnSuccess) return source;
    [s_ciContext render:source toCVPixelBuffer:pixels bounds:CGRectMake(0,0,w,h) colorSpace:PrivacySRGB()];
    if(CVPixelBufferLockBaseAddress(pixels,kCVPixelBufferLock_ReadOnly)!=kCVReturnSuccess) {CVPixelBufferRelease(pixels);return source;}
    auto result=PrivacyMosaic::Pixelate(static_cast<const uint8_t *>(CVPixelBufferGetBaseAddress(pixels)),w,h,CVPixelBufferGetBytesPerRow(pixels),MAX(2,(int)scale));
    CVPixelBufferUnlockBaseAddress(pixels,kCVPixelBufferLock_ReadOnly);
    if(CVPixelBufferLockBaseAddress(pixels,0)!=kCVReturnSuccess) {CVPixelBufferRelease(pixels);return source;}
    auto *output=static_cast<uint8_t *>(CVPixelBufferGetBaseAddress(pixels));
    size_t outputStride=CVPixelBufferGetBytesPerRow(pixels);
    for(int y=0;y<h;++y) std::copy(result.begin()+y*w*4,result.begin()+(y+1)*w*4,output+y*outputStride);
    CVPixelBufferUnlockBaseAddress(pixels,0);
    CIImage *image=[CIImage imageWithCVPixelBuffer:pixels options:@{kCIImageColorSpace:(__bridge id)PrivacySRGB()}];
    CVPixelBufferRelease(pixels);
    return image;
}

static CVPixelBufferRef ColourFrame(CIImage *source) {
    size_t width = 160, height = MAX(1, (size_t)std::lround(160 * source.extent.size.height / source.extent.size.width));
    CVPixelBufferRef buffer = nullptr;
    if (CVPixelBufferCreate(kCFAllocatorDefault, width, height, kCVPixelFormatType_32BGRA,
                           nullptr, &buffer) != kCVReturnSuccess) return nullptr;
    CIImage *small = [[source imageBySamplingLinear] imageByApplyingTransform:CGAffineTransformMakeScale(
        width / source.extent.size.width, height / source.extent.size.height)];
    [s_ciContext render:small toCVPixelBuffer:buffer bounds:CGRectMake(0,0,width,height) colorSpace:PrivacySRGB()];
    return buffer;
}

static CIImage *AdaptiveSkinMask(CVPixelBufferRef current) {
    if (current == nullptr || CVPixelBufferLockBaseAddress(current, kCVPixelBufferLock_ReadOnly) != kCVReturnSuccess) return nil;
    const int width = (int)CVPixelBufferGetWidth(current), height = (int)CVPixelBufferGetHeight(current);
    const size_t stride = CVPixelBufferGetBytesPerRow(current);
    const auto *pixels = static_cast<const unsigned char *>(CVPixelBufferGetBaseAddress(current));
    auto mask=s_skinClassifier.Classify(pixels,width,height,stride);
    CVPixelBufferUnlockBaseAddress(current,kCVPixelBufferLock_ReadOnly);
    CVPixelBufferRef bitmap=nullptr;
    if (CVPixelBufferCreate(kCFAllocatorDefault,width,height,kCVPixelFormatType_32BGRA,nullptr,&bitmap)!=kCVReturnSuccess) return nil;
    if (CVPixelBufferLockBaseAddress(bitmap,0)!=kCVReturnSuccess) { CVPixelBufferRelease(bitmap); return nil; }
    auto *output=static_cast<unsigned char *>(CVPixelBufferGetBaseAddress(bitmap));
    const size_t outputStride=CVPixelBufferGetBytesPerRow(bitmap);
    for(int y=0;y<height;++y) for(int x=0;x<width;++x) {
        auto *p=output+y*outputStride+x*4;
        p[0]=p[1]=p[2]=mask[y*width+x];p[3]=255;
    }
    CVPixelBufferUnlockBaseAddress(bitmap,0);
    CIImage *maskImage=[CIImage imageWithCVPixelBuffer:bitmap options:@{kCIImageColorSpace:[NSNull null]}];
    CVPixelBufferRelease(bitmap);
    return maskImage;
}

// Landmark coordinates have a top-left origin; Core Image uses bottom-left.
// Cover the whole expanded head, including dark eyes and hair, without holes.
static CIImage *HeadPrivacyMask(CIImage *source, CIImage *skin, NSInteger timestamp) {
    NSArray<NSValue *> *points;
    NSInteger detectedAt;
    @synchronized(PrivacyGate()) {
        points = s_facePrivacyPoints;
        detectedAt = s_facePrivacyTimestamp;
    }
    CGRect full = source.extent;
    CIImage *white = [CIImage imageWithColor:[CIColor colorWithRed:1 green:1 blue:1 alpha:1]];
    // Without a current face, use only the existing skin mask. Never replace
    // the entire background with mosaic because a face detector missed.
    if (points.count < 100 || timestamp < detectedAt || timestamp - detectedAt > 150)
        return skin;
    CGFloat left=1, right=0, top=1, bottom=0;
    for (NSValue *value in points) {
        CGPoint p=value.CGPointValue;
        if (!std::isfinite(p.x) || !std::isfinite(p.y))
            return skin;
        left=MIN(left,p.x);right=MAX(right,p.x);top=MIN(top,p.y);bottom=MAX(bottom,p.y);
    }
    CGFloat width=right-left, height=bottom-top;
    if (width <= 0 || height <= 0) return skin;
    // Face landmarks end near the forehead. Extend above it for the crown,
    // sideways for hair and motion, and below the chin for the head boundary.
    left=MAX(0,left-width*.5); right=MIN(1,right+width*.5);
    top=MAX(0,top-height*.8); bottom=MIN(1,bottom+height*.35);
    CGRect head=CGRectMake(full.origin.x+left*full.size.width,
        full.origin.y+(1-bottom)*full.size.height,
        (right-left)*full.size.width,(bottom-top)*full.size.height);
    CIImage *headMask=[white imageByCroppingToRect:head];
    CIImage *base=skin ? [[[skin imageBySamplingNearest] imageByApplyingTransform:CGAffineTransformMakeScale(
        full.size.width/skin.extent.size.width,full.size.height/skin.extent.size.height)] imageByCroppingToRect:full]
        : [[CIImage imageWithColor:[CIColor colorWithRed:0 green:0 blue:0 alpha:1]] imageByCroppingToRect:full];
    return [[headMask imageByCompositingOverImage:base] imageByCroppingToRect:full];
}

static void DisplayLiveBackground(CIImage *source, CIImage *mask, NSInteger timestamp) {
    if (source == nil || s_backgroundLayer == nil) return;
    CIImage *processed = source;
    if (mask != nil) {
        mask = [[[mask imageBySamplingNearest] imageByApplyingTransform:CGAffineTransformMakeScale(
            source.extent.size.width / mask.extent.size.width,
            source.extent.size.height / mask.extent.size.height)] imageByCroppingToRect:source.extent];
        processed = [WindowsStyleMosaic(source, s_mosaicScale) imageByApplyingFilter:@"CIBlendWithMask"
            withInputParameters:@{kCIInputBackgroundImageKey:source, kCIInputMaskImageKey:mask}];
    }
    CGImageRef frame = [s_ciContext createCGImage:processed fromRect:source.extent format:kCIFormatRGBA8 colorSpace:PrivacySRGB()];
    if (frame == nil) return;
    UIImage *image = [UIImage imageWithCGImage:frame];
    CGImageRelease(frame);
    dispatch_async(dispatch_get_main_queue(), ^{
        if (!s_captureStopping.load() && timestamp >= s_orientationReadyTimestamp.load() && s_backgroundLayer != nil)
            s_backgroundLayer.contents = (__bridge id)image.CGImage;
    });
}

// Assemble one packet from results for the same captured frame, matching the
// Windows estimator. Never reuse a later or earlier hand/face result.
static void SubmitResult(NSString *kind, NSDictionary *packet, NSInteger timestamp) {
    if (timestamp < s_orientationReadyTimestamp.load()) return;
    NSString *json = nil;
    NSString *receiver = nil;
    @synchronized(PrivacyGate()) {
        if (s_pendingFramePackets == nil) s_pendingFramePackets = [NSMutableDictionary dictionary];
        NSNumber *key = @(timestamp);
        NSMutableDictionary *parts = s_pendingFramePackets[key];
        if (parts == nil) {
            parts = [NSMutableDictionary dictionary];
            s_pendingFramePackets[key] = parts;
        }
        parts[kind] = packet;

        if (parts[@"pose"] != nil && parts[@"hand"] != nil && parts[@"face"] != nil) {
            NSDictionary *pose = parts[@"pose"];
            NSDictionary *hand = parts[@"hand"];
            NSDictionary *face = parts[@"face"];
            NSMutableDictionary *combined = [pose mutableCopy];
            NSMutableArray *points = [combined[@"points"] mutableCopy] ?: [NSMutableArray array];
            if (hand[@"points"] != nil) [points addObjectsFromArray:hand[@"points"]];
            combined[@"points"] = points;
            combined[@"tracking"] = @(points.count > 0);
            combined[@"face_blendshapes"] = face[@"face_blendshapes"] ?: @[];
            if (face[@"head_rotation"] != nil) combined[@"head_rotation"] = face[@"head_rotation"];
            NSData *data = [NSJSONSerialization dataWithJSONObject:combined options:0 error:nil];
            json = data != nil ? [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] : nil;
            receiver = [s_unityObject copy];
            [s_pendingFramePackets removeObjectForKey:key];
        }

        // Keep an upper bound if a detector fails to call back for some frames.
        while (s_pendingFramePackets.count > 64) {
            NSNumber *oldest = nil;
            for (NSNumber *candidate in s_pendingFramePackets)
                if (oldest == nil || candidate.longLongValue < oldest.longLongValue) oldest = candidate;
            if (oldest == nil) break;
            [s_pendingFramePackets removeObjectForKey:oldest];
        }
    }
    if (json == nil) return;
    dispatch_async(dispatch_get_main_queue(), ^{
        if (timestamp >= s_orientationReadyTimestamp.load() && receiver && [receiver isEqualToString:s_unityObject])
            UnitySendMessage(receiver.UTF8String, "OnNativePoseJson", json.UTF8String);
    });
}

@interface NativePoseResultDelegate : NSObject
- (void)poseLandmarker:(MPPPoseLandmarker *)landmarker didFinishDetectionWithResult:(MPPPoseLandmarkerResult *)result timestampInMilliseconds:(NSInteger)timestamp error:(NSError *)error;
@end
@interface NativeHandResultDelegate : NSObject
- (void)handLandmarker:(MPPHandLandmarker *)landmarker didFinishDetectionWithResult:(MPPHandLandmarkerResult *)result timestampInMilliseconds:(NSInteger)timestamp error:(NSError *)error;
@end
@interface NativeFaceResultDelegate : NSObject
- (void)faceLandmarker:(MPPFaceLandmarker *)landmarker didFinishDetectionWithResult:(MPPFaceLandmarkerResult *)result timestampInMilliseconds:(NSInteger)timestamp error:(NSError *)error;
@end
static NativePoseResultDelegate *s_resultDelegate;
static NativeHandResultDelegate *s_handDelegate;
static NativeFaceResultDelegate *s_faceDelegate;

@interface NativePoseCaptureDelegate : NSObject <AVCaptureVideoDataOutputSampleBufferDelegate>
@end

@implementation NativePoseCaptureDelegate
- (void)captureOutput:(AVCaptureOutput *)output
 didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer
        fromConnection:(AVCaptureConnection *)connection {
    dispatch_async(dispatch_get_main_queue(), ^{
        UIInterfaceOrientation orientation = UIApplication.sharedApplication.statusBarOrientation;
        if (orientation != s_lastVideoOrientation) UpdateVideoOrientation();
    });
    CVPixelBufferRef pixelBuffer = CMSampleBufferGetImageBuffer(sampleBuffer);
    if (pixelBuffer == nil) return;

    if (s_landmarker == nil || s_unityObject == nil) return;
    if (s_captureStopping.load()) return;
    long long timestamp = std::max((long long)(CACurrentMediaTime() * 1000.0), s_lastInferenceTimestamp + 1);
    s_lastInferenceTimestamp = timestamp;
    if (timestamp < s_orientationReadyTimestamp.load()) return;
    CVPixelBufferRef inferenceBuffer = nullptr;
    LetterboxGeometry geometry;
    if (!MakeSquareInferenceBuffer(pixelBuffer, &inferenceBuffer, &geometry)) return;
    geometry.frameNumber = (int)++s_frame;
    RememberFrameGeometry(timestamp, geometry);
    MPPImage *image = [[MPPImage alloc] initWithPixelBuffer:inferenceBuffer error:nil];
    CVPixelBufferRelease(inferenceBuffer);
    if (image == nil) return;
    if (s_ciContext == nil) s_ciContext = [CIContext contextWithOptions:@{kCIContextUseSoftwareRenderer:@NO}];
    CIImage *source = [CIImage imageWithCVPixelBuffer:pixelBuffer];
    CVPixelBufferRef colours = ColourFrame(source);
    DisplayLiveBackground(source, HeadPrivacyMask(source, AdaptiveSkinMask(colours), timestamp), timestamp);
    if (colours != nullptr) CVPixelBufferRelease(colours);
    MPPPoseLandmarker *poseLandmarker = s_landmarker;
    MPPHandLandmarker *handLandmarker = s_handLandmarker;
    MPPFaceLandmarker *faceLandmarker = s_faceLandmarker;
    __block MPPPoseLandmarkerResult *poseResult = nil;
    __block MPPHandLandmarkerResult *handResult = nil;
    __block MPPFaceLandmarkerResult *faceResult = nil;
    dispatch_group_t group = dispatch_group_create();
    dispatch_queue_t inferenceQueue = dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0);
    dispatch_group_async(group, inferenceQueue, ^{
        poseResult = [poseLandmarker detectVideoFrame:image timestampInMilliseconds:timestamp error:nil];
    });
    dispatch_group_async(group, inferenceQueue, ^{
        handResult = [handLandmarker detectVideoFrame:image timestampInMilliseconds:timestamp error:nil];
    });
    dispatch_group_async(group, inferenceQueue, ^{
        faceResult = [faceLandmarker detectVideoFrame:image timestampInMilliseconds:timestamp error:nil];
    });
    dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
    if (s_captureStopping.load() || timestamp < s_orientationReadyTimestamp.load()) return;
    [s_resultDelegate poseLandmarker:poseLandmarker didFinishDetectionWithResult:poseResult timestampInMilliseconds:timestamp error:nil];
    [s_handDelegate handLandmarker:handLandmarker didFinishDetectionWithResult:handResult timestampInMilliseconds:timestamp error:nil];
    [s_faceDelegate faceLandmarker:faceLandmarker didFinishDetectionWithResult:faceResult timestampInMilliseconds:timestamp error:nil];
}
@end
static void ProcessHandResult(MPPHandLandmarkerResult *result, NSInteger timestamp,
                              const LetterboxGeometry &geometry, NSDictionary *poseWrists);
@implementation NativePoseResultDelegate
- (void)poseLandmarker:(MPPPoseLandmarker *)landmarker didFinishDetectionWithResult:(MPPPoseLandmarkerResult *)result timestampInMilliseconds:(NSInteger)timestamp error:(NSError *)error {
    if (s_unityObject == nil || landmarker != s_landmarker || timestamp < s_orientationReadyTimestamp.load()) return;
    if (result == nil) return;
    LetterboxGeometry geometry;
    if (!GeometryForFrame(timestamp, &geometry)) return;
    NSArray *points = result.landmarks.firstObject;
    NSArray<MPPLandmark *> *world = result.worldLandmarks.firstObject;
    NSArray *names = @[@"nose", @"left_eye", @"right_eye", @"left_ear", @"right_ear", @"left_shoulder", @"right_shoulder", @"left_elbow", @"right_elbow", @"left_wrist", @"right_wrist", @"left_pinky", @"right_pinky", @"left_index", @"right_index", @"left_thumb", @"right_thumb", @"left_hip", @"right_hip", @"left_knee", @"right_knee", @"left_ankle", @"right_ankle", @"left_heel", @"right_heel", @"left_foot_index", @"right_foot_index"];
    NSArray<NSNumber *> *indices = @[@0, @2, @5, @7, @8, @11, @12, @13, @14, @15, @16, @17, @18, @19, @20, @21, @22, @23, @24, @25, @26, @27, @28, @29, @30, @31, @32];
    NSMutableArray *jsonPoints = [NSMutableArray array];
    NSMutableArray<NSValue *> *privacyPoints = [NSMutableArray array];
    for (NSUInteger i = 0; i < names.count; ++i) {
        NSUInteger landmarkIndex = indices[i].unsignedIntegerValue;
        if (landmarkIndex >= points.count || landmarkIndex >= world.count) continue;
        MPPNormalizedLandmark *p = points[landmarkIndex];
        MPPLandmark *w = world[landmarkIndex];
        CGPoint originalPoint = RestoreOriginalImagePoint(p.x, p.y, geometry);
        [privacyPoints addObject:[NSValue valueWithCGPoint:originalPoint]];
        // Match the Windows protocol: raw MediaPipe world axes, image coordinates
        // separately, and visibility as confidence. Unity performs axis conversion.
        [jsonPoints addObject:@{@"name": names[i], @"x": @(w.x), @"y": @(w.y), @"z": @(w.z), @"confidence": p.visibility ?: @0.0, @"image_x": @(originalPoint.x), @"image_y": @(originalPoint.y), @"image_z": @(p.z)}];
    }
    @synchronized(PrivacyGate()) {
        if (timestamp < s_posePrivacyTimestamp) return;
        s_posePrivacyPoints = [privacyPoints copy];
        s_posePrivacyTimestamp = timestamp;
    }
    NSMutableDictionary *poseWrists = [NSMutableDictionary dictionary];
    poseWrists[@"has_world"] = @(world.count > 0);
    if (points.count > 15) {
        MPPNormalizedLandmark *wrist = points[15];
        if (wrist.visibility.floatValue >= .2f) poseWrists[@"left"] = @{@"x": @(wrist.x), @"y": @(wrist.y)};
    }
    if (points.count > 16) {
        MPPNormalizedLandmark *wrist = points[16];
        if (wrist.visibility.floatValue >= .2f) poseWrists[@"right"] = @{@"x": @(wrist.x), @"y": @(wrist.y)};
    }
    MPPHandLandmarkerResult *pendingHand = nil;
    @synchronized(PrivacyGate()) {
        if (s_poseWristsByTimestamp == nil) s_poseWristsByTimestamp = [NSMutableDictionary dictionary];
        if (s_pendingHandResults == nil) s_pendingHandResults = [NSMutableDictionary dictionary];
        NSNumber *key = @(timestamp);
        s_poseWristsByTimestamp[key] = poseWrists;
        pendingHand = s_pendingHandResults[key];
        [s_pendingHandResults removeObjectForKey:key];
        while (s_poseWristsByTimestamp.count > 64) {
            NSNumber *oldest = nil;
            for (NSNumber *candidate in s_poseWristsByTimestamp)
                if (oldest == nil || candidate.longLongValue < oldest.longLongValue) oldest = candidate;
            if (oldest == nil) break;
            [s_poseWristsByTimestamp removeObjectForKey:oldest];
        }
    }
    NSDictionary *packet = @{@"version": @4, @"frame": @(geometry.frameNumber), @"timestamp_ms": @(timestamp), @"source_width": @(geometry.sourceWidth), @"source_height": @(geometry.sourceHeight), @"tracking": @(jsonPoints.count > 0), @"points": jsonPoints};
    SubmitResult(@"pose", packet, timestamp);
    if (pendingHand != nil) ProcessHandResult(pendingHand, timestamp, geometry, poseWrists);
}
@end

@implementation NativeHandResultDelegate
- (void)handLandmarker:(MPPHandLandmarker *)landmarker didFinishDetectionWithResult:(MPPHandLandmarkerResult *)result timestampInMilliseconds:(NSInteger)timestamp error:(NSError *)error {
    if (!result || !s_unityObject || timestamp < s_orientationReadyTimestamp.load()) return;
    LetterboxGeometry geometry;
    if (!GeometryForFrame(timestamp, &geometry)) return;
    NSDictionary *poseWrists = nil;
    NSNumber *key = @(timestamp);
    @synchronized(PrivacyGate()) {
        poseWrists = s_poseWristsByTimestamp[key];
        if (poseWrists == nil) {
            if (s_pendingHandResults == nil) s_pendingHandResults = [NSMutableDictionary dictionary];
            s_pendingHandResults[key] = result;
            while (s_pendingHandResults.count > 64) {
                NSNumber *oldest = nil;
                for (NSNumber *candidate in s_pendingHandResults)
                    if (oldest == nil || candidate.longLongValue < oldest.longLongValue) oldest = candidate;
                if (oldest == nil) break;
                [s_pendingHandResults removeObjectForKey:oldest];
            }
        }
    }
    if (poseWrists != nil) ProcessHandResult(result, timestamp, geometry, poseWrists);
}
@end

static void ProcessHandResult(MPPHandLandmarkerResult *result, NSInteger timestamp,
                              const LetterboxGeometry &geometry, NSDictionary *poseWrists) {
    static NSArray<NSString *> *names = nil;
    static dispatch_once_t namesOnce;
    dispatch_once(&namesOnce, ^{
        names = @[@"wrist", @"thumb_cmc", @"thumb_mcp", @"thumb_ip", @"thumb", @"index_mcp", @"index_pip", @"index_dip", @"index", @"middle_mcp", @"middle_pip", @"middle_dip", @"middle", @"ring_mcp", @"ring_pip", @"ring_dip", @"ring", @"pinky_mcp", @"pinky_pip", @"pinky_dip", @"pinky"];
    });
    NSMutableArray<NSDictionary *> *candidates = [NSMutableArray array];
    for (NSUInteger index = 0; index < result.landmarks.count; ++index) {
        NSArray *image = result.landmarks[index];
        if (image.count == 0) continue;
        NSArray *world = index < result.worldLandmarks.count ? result.worldLandmarks[index] : @[];
        MPPNormalizedLandmark *wrist = image[0];
        MPPCategory *category = index < result.handedness.count ? [result.handedness[index] firstObject] : nil;
        NSString *rawLabel = category.categoryName.length > 0 ? category.categoryName : category.displayName;
        NSString *label = rawLabel.lowercaseString ?: @"";
        if (![label isEqualToString:@"left"] && ![label isEqualToString:@"right"]) label = @"";
        [candidates addObject:@{@"index": @(index), @"score": @(category ? category.score : .5f),
                                @"label": label, @"wrist_x": @(wrist.x), @"wrist_y": @(wrist.y),
                                @"image": image, @"world": world}];
    }
    [candidates sortUsingComparator:^NSComparisonResult(NSDictionary *a, NSDictionary *b) {
        double sa = [a[@"score"] doubleValue], sb = [b[@"score"] doubleValue];
        if (sa != sb) return sa > sb ? NSOrderedAscending : NSOrderedDescending;
        NSComparisonResult labelOrder = [a[@"label"] compare:b[@"label"] options:NSLiteralSearch];
        if (labelOrder != NSOrderedSame) return labelOrder == NSOrderedAscending ? NSOrderedDescending : NSOrderedAscending;
        for (NSString *key in @[@"index", @"wrist_x", @"wrist_y"]) {
            double va = [a[key] doubleValue], vb = [b[key] doubleValue];
            if (va != vb) return va > vb ? NSOrderedAscending : NSOrderedDescending;
        }
        return NSOrderedSame;
    }];
    if (candidates.count > 2) [candidates removeObjectsInRange:NSMakeRange(2, candidates.count - 2)];

    NSArray<NSArray<NSString *> *> *permutations = candidates.count == 2
        ? @[@[@"left", @"right"], @[@"right", @"left"]]
        : candidates.count == 1 ? @[@[@"left"], @[@"right"]] : @[];
    double bestCost = std::numeric_limits<double>::infinity();
    NSArray<NSString *> *bestSides = @[];
    NSDictionary<NSString *, NSDictionary *> *tracks = s_handTrackState;
    @synchronized(PrivacyGate()) {
        if (s_handTrackState == nil) s_handTrackState = [NSMutableDictionary dictionary];
        tracks = s_handTrackState;
        for (NSArray<NSString *> *sides in permutations) {
            double cost = 0;
            for (NSUInteger i = 0; i < candidates.count; ++i) {
                NSDictionary *hand = candidates[i];
                NSString *side = sides[i];
                double x = [hand[@"wrist_x"] doubleValue], y = [hand[@"wrist_y"] doubleValue];
                NSDictionary *track = tracks[side];
                int lastFrame = track != nil ? [track[@"last_frame"] intValue] : geometry.frameNumber;
                int age = geometry.frameNumber - lastFrame;
                if (track != nil && age <= 10) {
                    int predictionFrames = std::min(std::max(age, 1), 3);
                    double predictedX = [track[@"x"] doubleValue] + [track[@"vx"] doubleValue] * predictionFrames;
                    double predictedY = [track[@"y"] doubleValue] + [track[@"vy"] doubleValue] * predictionFrames;
                    double dx = x - predictedX, dy = y - predictedY;
                    cost += 5.0 * (dx * dx + dy * dy);
                } else cost += .12;

                NSString *label = hand[@"label"];
                double score = [hand[@"score"] doubleValue];
                if (score >= .7 && label.length > 0 && ![label isEqualToString:side]) cost += .10 * score;
                NSDictionary *poseWrist = poseWrists[side];
                if (poseWrist != nil) {
                    double dx = x - [poseWrist[@"x"] doubleValue];
                    double dy = y - [poseWrist[@"y"] doubleValue];
                    cost += .35 * (dx * dx + dy * dy);
                }
                NSString *screenSide = x > .5 ? @"left" : @"right"; // tracking_mirror=false, matching Unity's Windows launch defaults
                if (![screenSide isEqualToString:side]) cost += .015;
            }
            if (cost < bestCost) { bestCost = cost; bestSides = sides; }
        }

        for (NSUInteger i = 0; i < candidates.count; ++i) {
            NSDictionary *hand = candidates[i];
            NSString *side = bestSides[i];
            NSDictionary *previous = tracks[side];
            int age = previous != nil ? std::max(geometry.frameNumber - [previous[@"last_frame"] intValue], 1) : 1;
            double x = [hand[@"wrist_x"] doubleValue], y = [hand[@"wrist_y"] doubleValue];
            double vx = 0, vy = 0;
            if (previous != nil && age <= 10) {
                double measuredX = (x - [previous[@"x"] doubleValue]) / age;
                double measuredY = (y - [previous[@"y"] doubleValue]) / age;
                vx = [previous[@"vx"] doubleValue] * .45 + measuredX * .55;
                vy = [previous[@"vy"] doubleValue] * .45 + measuredY * .55;
            }
            tracks[side] = @{@"x": @(x), @"y": @(y), @"vx": @(vx), @"vy": @(vy), @"last_frame": @(geometry.frameNumber)};
        }
    }

    NSMutableArray<NSValue *> *privacyPoints = [NSMutableArray array];
    int leftCount = 0, rightCount = 0;
    if ([poseWrists[@"has_world"] boolValue]) {
        for (NSUInteger h = 0; h < candidates.count; ++h) {
            NSDictionary *candidate = candidates[h];
            NSString *side = bestSides[h];
            NSArray *image = candidate[@"image"], *world = candidate[@"world"];
            float score = [candidate[@"score"] floatValue];
            for (NSUInteger i = 0; i < image.count && i < world.count && i < names.count; ++i) {
                MPPNormalizedLandmark *p = image[i]; MPPLandmark *w = world[i];
                CGPoint originalPoint = RestoreOriginalImagePoint(p.x, p.y, geometry);
                [privacyPoints addObject:[NSValue valueWithCGPoint:originalPoint]];
                [points addObject:@{@"name": [NSString stringWithFormat:@"%@_hand_%@", side, names[i]], @"x": @(w.x), @"y": @(w.y), @"z": @(w.z), @"confidence": @(score), @"image_x": @(originalPoint.x), @"image_y": @(originalPoint.y), @"image_z": @(p.z)}];
            }
            if (image.count > 17 && world.count > 17) {
                NSArray<NSNumber *> *indices = @[@5, @9, @17];
                float ix = 0, iy = 0, iz = 0, wx = 0, wy = 0, wz = 0;
                for (NSNumber *number in indices) {
                    NSUInteger index = number.unsignedIntegerValue;
                    MPPNormalizedLandmark *p = image[index]; MPPLandmark *w = world[index];
                    ix += p.x; iy += p.y; iz += p.z; wx += w.x; wy += w.y; wz += w.z;
                }
                CGPoint originalPoint = RestoreOriginalImagePoint(ix / 3, iy / 3, geometry);
                [points addObject:@{@"name": [NSString stringWithFormat:@"%@_hand_palm", side], @"x": @(wx / 3), @"y": @(wy / 3), @"z": @(wz / 3), @"confidence": @(score), @"image_x": @(originalPoint.x), @"image_y": @(originalPoint.y), @"image_z": @(iz / 3)}];
            }
            if ([side isEqualToString:@"left"]) leftCount = (int)MIN(image.count + 1, 22);
            else rightCount = (int)MIN(image.count + 1, 22);
        }
    }
    @synchronized(PrivacyGate()) { s_handPrivacyPoints = [privacyPoints copy]; s_handPrivacyTimestamp = timestamp; }
    NSDictionary *packet = @{@"version": @4, @"frame": @(geometry.frameNumber), @"timestamp_ms": @(timestamp), @"source_width": @(geometry.sourceWidth), @"source_height": @(geometry.sourceHeight), @"tracking": @(points.count > 0), @"hand_count": @(candidates.count), @"left_hand_points": @(leftCount), @"right_hand_points": @(rightCount), @"points": points};
    @synchronized(PrivacyGate()) { [s_poseWristsByTimestamp removeObjectForKey:@(timestamp)]; }
    SubmitResult(@"hand", packet, timestamp);
}

@implementation NativeFaceResultDelegate
- (void)faceLandmarker:(MPPFaceLandmarker *)landmarker didFinishDetectionWithResult:(MPPFaceLandmarkerResult *)result timestampInMilliseconds:(NSInteger)timestamp error:(NSError *)error {
    if (!result || !s_unityObject || landmarker != s_faceLandmarker || s_captureStopping.load() || timestamp < s_orientationReadyTimestamp.load()) return;
    LetterboxGeometry geometry;
    if (!GeometryForFrame(timestamp, &geometry)) return;
    NSMutableArray *blend = [NSMutableArray array];
    NSMutableArray *points = [NSMutableArray array];
    NSSet<NSString *> *trackedShapes = [NSSet setWithArray:@[@"eyeBlinkLeft", @"eyeBlinkRight", @"jawOpen", @"mouthSmileLeft", @"mouthSmileRight"]];
    if (result.faceBlendshapes.count > 0) for (MPPCategory *c in result.faceBlendshapes.firstObject.categories)
        if ([trackedShapes containsObject:c.categoryName ?: @""])
            [blend addObject:@{@"name": c.categoryName ?: @"", @"score": @(c.score)}];
    NSMutableDictionary *packet = [@{@"version": @4, @"frame": @(geometry.frameNumber), @"timestamp_ms": @(timestamp), @"source_width": @(geometry.sourceWidth), @"source_height": @(geometry.sourceHeight), @"tracking": @(result.faceLandmarks.count > 0), @"face_blendshapes": blend, @"points": @[]} mutableCopy];
    NSDictionary *headRotation = HeadRotationFromFaceMatrix(result.facialTransformationMatrixes.firstObject);
    if (headRotation != nil) packet[@"head_rotation"] = headRotation;
    NSMutableArray<NSValue *> *privacy = [NSMutableArray array];
    for (MPPNormalizedLandmark *p in result.faceLandmarks.firstObject)
        [privacy addObject:[NSValue valueWithCGPoint:RestoreOriginalImagePoint(p.x, p.y, geometry)]];
    @synchronized(PrivacyGate()) {
        if (timestamp < s_facePrivacyTimestamp) return;
        s_facePrivacyPoints=[privacy copy]; s_facePrivacyTimestamp=timestamp;
    }
    SubmitResult(@"face", packet, timestamp);
}
@end

static NativePoseCaptureDelegate *s_delegate;
static BOOL s_paused;
static BOOL s_stopping;

static void UpdateVideoOrientation() {
    UIView *unityView = UnityGetGLViewController().view;
    s_backgroundLayer.frame = unityView.frame;
    AVCaptureVideoOrientation orientation = AVCaptureVideoOrientationPortrait;
    UIInterfaceOrientation ui = UIApplication.sharedApplication.statusBarOrientation;
    s_lastVideoOrientation = ui;
    // Ignore detections and queued Unity callbacks from the previous camera orientation.
    s_orientationReadyTimestamp = (long long)(CACurrentMediaTime() * 1000.0) + 150;
    @synchronized(PrivacyGate()) {
        s_facePrivacyPoints = nil; s_handPrivacyPoints = nil;
        s_facePrivacyTimestamp = 0; s_handPrivacyTimestamp = 0;
        [s_poseWristsByTimestamp removeAllObjects];
        [s_pendingHandResults removeAllObjects];
        [s_handTrackState removeAllObjects];
        [s_pendingFramePackets removeAllObjects];
    }
    if (s_unityObject != nil)
        UnitySendMessage(s_unityObject.UTF8String, "OnNativeCameraOrientationChanged", "");
    if (ui == UIInterfaceOrientationLandscapeLeft) orientation = AVCaptureVideoOrientationLandscapeLeft;
    else if (ui == UIInterfaceOrientationLandscapeRight) orientation = AVCaptureVideoOrientationLandscapeRight;
    AVCaptureConnection *video = [s_output connectionWithMediaType:AVMediaTypeVideo];
    if (video.isVideoOrientationSupported) video.videoOrientation = orientation;
    if (video.isVideoMirroringSupported) {
        video.automaticallyAdjustsVideoMirroring = NO;
        video.videoMirrored = NO;
    }
    s_backgroundLayer.affineTransform = s_useFrontCamera
        ? CGAffineTransformMakeScale(-1.0, 1.0)
        : CGAffineTransformIdentity;
}

static AVCaptureDevice *CameraDevice(BOOL front) {
    AVCaptureDevicePosition position = front ? AVCaptureDevicePositionFront : AVCaptureDevicePositionBack;
    AVCaptureDeviceDiscoverySession *discovery = [AVCaptureDeviceDiscoverySession
        discoverySessionWithDeviceTypes:@[AVCaptureDeviceTypeBuiltInWideAngleCamera]
        mediaType:AVMediaTypeVideo position:position];
    return discovery.devices.firstObject;
}

static void NotifyCameraState(NSString *message) {
    if (s_unityObject != nil) UnitySendMessage(s_unityObject.UTF8String, "OnNativeCameraState", message.UTF8String);
}

extern "C" void NativePoseCaptureStop();

extern "C" int NativePoseCaptureStart(const char *unityObjectName) {
    if (s_session != nil || s_stopping) return 1;
    s_captureStopping = false;
    s_skinClassifier=PrivacyMosaic::SkinClassifier(107.f,157.f,6.f,7.f);
    s_unityObject = [NSString stringWithUTF8String:unityObjectName ?: ""];
    s_lastSafeBackgroundImage = nil;
    s_frame = 0;
    @synchronized(PrivacyGate()) {
        s_poseWristsByTimestamp = [NSMutableDictionary dictionary];
        s_pendingHandResults = [NSMutableDictionary dictionary];
        s_handTrackState = [NSMutableDictionary dictionary];
        s_pendingFramePackets = [NSMutableDictionary dictionary];
        s_posePrivacyPoints = nil; s_handPrivacyPoints = nil; s_facePrivacyPoints = nil;
        s_posePrivacyTimestamp = s_handPrivacyTimestamp = s_facePrivacyTimestamp = 0;
    }
    { std::lock_guard<std::mutex> lock(s_geometryMutex); s_frameGeometry.clear(); }
    if ([AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo] == AVAuthorizationStatusNotDetermined) {
        [AVCaptureDevice requestAccessForMediaType:AVMediaTypeVideo completionHandler:^(BOOL granted) {
            dispatch_async(dispatch_get_main_queue(), ^{
                if (granted && s_unityObject != nil) UnitySendMessage(s_unityObject.UTF8String, "OnNativeCameraPermissionGranted", "");
                else NotifyCameraState(@"camera_permission_denied");
            });
        }];
        return -6;
    } else if ([AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo] != AVAuthorizationStatusAuthorized) {
        NotifyCameraState(@"camera_permission_denied");
        return -5;
    }
    NSString *modelPath = [[NSBundle mainBundle] pathForResource:@"pose_landmarker_lite" ofType:@"task" inDirectory:@"Data/Raw"];
    if (modelPath == nil) return -3;
    MPPPoseLandmarkerOptions *options = [MPPPoseLandmarkerOptions new];
    options.baseOptions.modelAssetPath = modelPath;
    options.runningMode = MPPRunningModeVideo;
    options.numPoses = 1;
    options.shouldOutputSegmentationMasks = NO;
    s_resultDelegate = [NativePoseResultDelegate new];
    s_landmarker = [[MPPPoseLandmarker alloc] initWithOptions:options error:nil];
    if (s_landmarker == nil) return -4;
    NSString *handPath = [[NSBundle mainBundle] pathForResource:@"hand_landmarker" ofType:@"task" inDirectory:@"Data/Raw"];
    NSString *facePath = [[NSBundle mainBundle] pathForResource:@"face_landmarker" ofType:@"task" inDirectory:@"Data/Raw"];
    if (!handPath || !facePath) return -7;
    MPPHandLandmarkerOptions *handOptions = [MPPHandLandmarkerOptions new];
    handOptions.baseOptions.modelAssetPath = handPath; handOptions.runningMode = MPPRunningModeVideo; handOptions.numHands = 2;
    handOptions.minHandDetectionConfidence = .35f;
    handOptions.minHandPresenceConfidence = .35f;
    handOptions.minTrackingConfidence = .35f;
    s_handDelegate = [NativeHandResultDelegate new];
    s_handLandmarker = [[MPPHandLandmarker alloc] initWithOptions:handOptions error:nil];
    MPPFaceLandmarkerOptions *faceOptions = [MPPFaceLandmarkerOptions new];
    faceOptions.baseOptions.modelAssetPath = facePath; faceOptions.runningMode = MPPRunningModeVideo; faceOptions.numFaces = 1; faceOptions.outputFaceBlendshapes = YES; faceOptions.outputFacialTransformationMatrixes = YES;
    s_faceDelegate = [NativeFaceResultDelegate new];
    s_faceLandmarker = [[MPPFaceLandmarker alloc] initWithOptions:faceOptions error:nil];
    if (!s_handLandmarker || !s_faceLandmarker) return -8;




    s_session = [AVCaptureSession new];
    [s_session beginConfiguration];
    if ([s_session canSetSessionPreset:AVCaptureSessionPreset640x480])
        s_session.sessionPreset = AVCaptureSessionPreset640x480;

    AVCaptureDevice *device = CameraDevice(s_useFrontCamera);
    AVCaptureDeviceInput *input = [AVCaptureDeviceInput deviceInputWithDevice:device error:nil];
    if (input == nil || ![s_session canAddInput:input]) {
        s_session = nil;
        return -1;
    }
    [s_session addInput:input];

    s_output = [AVCaptureVideoDataOutput new];
    s_output.videoSettings = @{(id)kCVPixelBufferPixelFormatTypeKey:
                               @(kCVPixelFormatType_32BGRA)};
    s_output.alwaysDiscardsLateVideoFrames = YES;
    s_queue = dispatch_queue_create("jp.project.native-pose-camera", DISPATCH_QUEUE_SERIAL);
    s_delegate = [NativePoseCaptureDelegate new];
    [s_output setSampleBufferDelegate:s_delegate queue:s_queue];
    if (![s_session canAddOutput:s_output]) {
        [s_session commitConfiguration];
        s_session = nil;
        return -2;
    }
    [s_session addOutput:s_output];
    [s_session commitConfiguration];
    dispatch_async(dispatch_get_main_queue(), ^{
        UIView *unityView = UnityGetGLViewController().view;
        unityView.opaque = NO;
        unityView.backgroundColor = UIColor.clearColor;
        unityView.layer.opaque = NO;
        s_backgroundLayer = [CALayer layer];
        s_backgroundLayer.contentsGravity = kCAGravityResizeAspectFill;
        s_backgroundLayer.masksToBounds = YES;
        UIView *container = unityView.superview;
        if (container != nil) {
            s_backgroundLayer.frame = unityView.frame;
            [container.layer insertSublayer:s_backgroundLayer below:unityView.layer];
        }
        UpdateVideoOrientation();
    });
    [s_session startRunning];
    NotifyCameraState(@"camera_started");
    return 0;
}

extern "C" void NativePoseCaptureSetPaused(int paused) {
    s_paused = paused != 0;
    s_captureStopping = s_paused;
    if (s_paused) [s_session stopRunning];
    else if (s_session != nil) [s_session startRunning];
    if (s_unityObject != nil) NotifyCameraState(s_paused ? @"camera_paused" : @"camera_resumed");
}

extern "C" void NativePoseCaptureSetFrontCamera(int front) {
    BOOL requested = front != 0;
    if (requested == s_useFrontCamera) return;
    s_useFrontCamera = requested;
    if (s_session == nil || s_unityObject == nil) return;
    NSString *receiver = [s_unityObject copy];
    NativePoseCaptureStop();
    NativePoseCaptureStart(receiver.UTF8String);
}

extern "C" void NativePoseCaptureSetMosaicScale(float scale) {
    s_mosaicScale = MAX(2.0, scale);
}

extern "C" void NativePoseCaptureStop() {
    s_stopping = YES;
    s_captureStopping = true;
    [s_session stopRunning];
    [s_output setSampleBufferDelegate:nil queue:NULL];
    [s_backgroundLayer removeFromSuperlayer];
    s_backgroundLayer = nil;
    s_ciContext = nil;
    s_lastSafeBackgroundImage = nil;
    @synchronized(PrivacyGate()) {
        s_poseWristsByTimestamp = nil; s_pendingHandResults = nil; s_handTrackState = nil;
        s_pendingFramePackets = nil;
    }
    { std::lock_guard<std::mutex> lock(s_geometryMutex); s_frameGeometry.clear(); }
    s_output = nil;
    s_delegate = nil;
    s_landmarker = nil;
    s_handLandmarker = nil;
    s_faceLandmarker = nil;
    s_resultDelegate = nil;
    s_handDelegate = nil;
    s_faceDelegate = nil;
    @synchronized(PrivacyGate()) {
        s_posePrivacyPoints = nil;
        s_handPrivacyPoints = nil; s_facePrivacyPoints=nil;
        s_handPrivacyTimestamp=0; s_facePrivacyTimestamp=0;
    }
    s_unityObject = nil;
    s_queue = nil;
    s_session = nil;
    s_stopping = NO;
}
