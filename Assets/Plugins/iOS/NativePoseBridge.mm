#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <CoreImage/CoreImage.h>
#import "UnityInterface.h"
#import <MediaPipeTasksVision/MediaPipeTasksVision.h>

#include "PrivacyMosaicCore.h"
#include <atomic>
#include <cmath>
#include <vector>
#include <algorithm>
static std::atomic<int> s_width{640}, s_height{480};
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
static UIInterfaceOrientation s_lastVideoOrientation = UIInterfaceOrientationUnknown;
static void UpdateVideoOrientation(void);
static NSDictionary *s_latestHandPacket;
static NSDictionary *s_latestFacePacket;
static NSInteger s_latestHandTimestamp;
static NSInteger s_latestFaceTimestamp;
template<typename T> static T ClampColour(T value, T low, T high) {
    return std::max(low, std::min(high, value));
}
static CGPoint s_leftPoseWrist;
static CGPoint s_rightPoseWrist;
static BOOL s_hasLeftPoseWrist;
static BOOL s_hasRightPoseWrist;
static NSObject *PrivacyGate() {
    static NSObject *gate;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ gate = [NSObject new]; });
    return gate;
}

static NSDictionary *HeadRotationFromFaceMatrix(MPPTransformMatrix *matrix) {
    if (matrix == nil || matrix.rows < 3 || matrix.columns < 3) return nil;
    float r[3][3];
    for (NSUInteger row = 0; row < 3; ++row)
        for (NSUInteger column = 0; column < 3; ++column)
            r[row][column] = [matrix valueAtRow:row column:column];
    // Newton polar decomposition produces the same nearest orthogonal matrix as
    // Windows' U @ Vh SVD scale removal, without adding another native library.
    for (NSUInteger iteration = 0; iteration < 6; ++iteration) {
        float determinant =
            r[0][0] * (r[1][1] * r[2][2] - r[1][2] * r[2][1]) -
            r[0][1] * (r[1][0] * r[2][2] - r[1][2] * r[2][0]) +
            r[0][2] * (r[1][0] * r[2][1] - r[1][1] * r[2][0]);
        if (fabsf(determinant) < .000001f) return nil;
        float inverseTranspose[3][3] = {
            {(r[1][1]*r[2][2]-r[1][2]*r[2][1])/determinant, (r[1][2]*r[2][0]-r[1][0]*r[2][2])/determinant, (r[1][0]*r[2][1]-r[1][1]*r[2][0])/determinant},
            {(r[0][2]*r[2][1]-r[0][1]*r[2][2])/determinant, (r[0][0]*r[2][2]-r[0][2]*r[2][0])/determinant, (r[0][1]*r[2][0]-r[0][0]*r[2][1])/determinant},
            {(r[0][1]*r[1][2]-r[0][2]*r[1][1])/determinant, (r[0][2]*r[1][0]-r[0][0]*r[1][2])/determinant, (r[0][0]*r[1][1]-r[0][1]*r[1][0])/determinant}
        };
        for (NSUInteger row = 0; row < 3; ++row)
            for (NSUInteger column = 0; column < 3; ++column)
                r[row][column] = .5f * (r[row][column] + inverseTranspose[row][column]);
    }
    const float axis[3] = {1, -1, -1};
    for (NSUInteger row = 0; row < 3; ++row)
        for (NSUInteger column = 0; column < 3; ++column)
            r[row][column] *= axis[row] * axis[column];
    float x, y, z, w;
    float trace = r[0][0] + r[1][1] + r[2][2];
    if (trace > 0) {
        float scale = sqrtf(trace + 1) * 2;
        w = .25f * scale; x = (r[2][1] - r[1][2]) / scale;
        y = (r[0][2] - r[2][0]) / scale; z = (r[1][0] - r[0][1]) / scale;
    } else if (r[0][0] > r[1][1] && r[0][0] > r[2][2]) {
        float scale = sqrtf(1 + r[0][0] - r[1][1] - r[2][2]) * 2;
        x = .25f * scale; y = (r[0][1] + r[1][0]) / scale;
        z = (r[0][2] + r[2][0]) / scale; w = (r[2][1] - r[1][2]) / scale;
    } else if (r[1][1] > r[2][2]) {
        float scale = sqrtf(1 + r[1][1] - r[0][0] - r[2][2]) * 2;
        x = (r[0][1] + r[1][0]) / scale; y = .25f * scale;
        z = (r[1][2] + r[2][1]) / scale; w = (r[0][2] - r[2][0]) / scale;
    } else {
        float scale = sqrtf(1 + r[2][2] - r[0][0] - r[1][1]) * 2;
        x = (r[0][2] + r[2][0]) / scale; y = (r[1][2] + r[2][1]) / scale;
        z = .25f * scale; w = (r[1][0] - r[0][1]) / scale;
    }
    float norm = sqrtf(x*x + y*y + z*z + w*w);
    if (norm < .00001f) return nil;
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
    // Old coordinates cannot protect a moving face. Fail closed on startup,
    // detector loss, rotation and a face result more than 150 ms behind video.
    if (points.count < 100 || timestamp < detectedAt || timestamp - detectedAt > 150)
        return [white imageByCroppingToRect:full];
    CGFloat left=1, right=0, top=1, bottom=0;
    for (NSValue *value in points) {
        CGPoint p=value.CGPointValue;
        if (!std::isfinite(p.x) || !std::isfinite(p.y))
            return [white imageByCroppingToRect:full];
        left=MIN(left,p.x);right=MAX(right,p.x);top=MIN(top,p.y);bottom=MAX(bottom,p.y);
    }
    CGFloat width=right-left, height=bottom-top;
    if (width <= 0 || height <= 0) return [white imageByCroppingToRect:full];
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

// Pose drives the body and must never wait for optional hand/face detectors.
// Supplemental results are reused only for a short interval.
static void SubmitResult(NSString *kind, NSDictionary *packet, NSInteger timestamp) {
    if (timestamp < s_orientationReadyTimestamp.load()) return;
    static NSObject *gate;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ gate = [NSObject new]; });
    @synchronized(gate) {
        if ([kind isEqualToString:@"hand"]) {
            s_latestHandPacket = packet;
            s_latestHandTimestamp = timestamp;
            return;
        }
        if ([kind isEqualToString:@"face"]) {
            s_latestFacePacket = packet;
            s_latestFaceTimestamp = timestamp;
            return;
        }
        NSMutableDictionary *combined = [packet mutableCopy];
        NSMutableArray *points = [combined[@"points"] mutableCopy] ?: [NSMutableArray array];
        NSInteger handAge = timestamp >= s_latestHandTimestamp
            ? timestamp - s_latestHandTimestamp : s_latestHandTimestamp - timestamp;
        NSInteger faceAge = timestamp >= s_latestFaceTimestamp
            ? timestamp - s_latestFaceTimestamp : s_latestFaceTimestamp - timestamp;
        NSDictionary *hand = s_latestHandPacket != nil && handAge <= 150 ? s_latestHandPacket : nil;
        NSDictionary *face = s_latestFacePacket != nil && faceAge <= 150 ? s_latestFacePacket : nil;
        if (hand[@"points"] != nil) [points addObjectsFromArray:hand[@"points"]];
        if (face[@"points"] != nil) [points addObjectsFromArray:face[@"points"]];
        combined[@"points"] = points;
        combined[@"hand_count"] = hand[@"hand_count"] ?: @0;
        combined[@"left_hand_points"] = hand[@"left_hand_points"] ?: @0;
        combined[@"right_hand_points"] = hand[@"right_hand_points"] ?: @0;
        combined[@"face_blendshapes"] = face[@"face_blendshapes"] ?: @[];
        if (face[@"head_rotation"] != nil) combined[@"head_rotation"] = face[@"head_rotation"];
        combined[@"frame"] = @(s_frame++);
        NSData *data = [NSJSONSerialization dataWithJSONObject:combined options:0 error:nil];
        NSString *json = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
        NSString *receiver = [s_unityObject copy];
        dispatch_async(dispatch_get_main_queue(), ^{
            if (timestamp >= s_orientationReadyTimestamp.load() && receiver && [receiver isEqualToString:s_unityObject] && json)
                UnitySendMessage(receiver.UTF8String, "OnNativePoseJson", json.UTF8String);
        });
    }
}

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
    NSInteger timestamp = (NSInteger)(CACurrentMediaTime() * 1000.0);
    if (timestamp < s_orientationReadyTimestamp.load()) return;
    s_width = (int)CVPixelBufferGetWidth(pixelBuffer);
    s_height = (int)CVPixelBufferGetHeight(pixelBuffer);
    MPPImage *image = [[MPPImage alloc] initWithPixelBuffer:pixelBuffer error:nil];
    if (image == nil) return;
    if (s_ciContext == nil) s_ciContext = [CIContext contextWithOptions:@{kCIContextUseSoftwareRenderer:@NO}];
    CIImage *source = [CIImage imageWithCVPixelBuffer:pixelBuffer];
    CVPixelBufferRef colours = ColourFrame(source);
    DisplayLiveBackground(source, HeadPrivacyMask(source, AdaptiveSkinMask(colours), timestamp), timestamp);
    if (colours != nullptr) CVPixelBufferRelease(colours);
    [s_landmarker detectAsyncImage:image timestampInMilliseconds:timestamp error:nil];
    [s_handLandmarker detectAsyncImage:image timestampInMilliseconds:timestamp error:nil];
    [s_faceLandmarker detectAsyncImage:image timestampInMilliseconds:timestamp error:nil];
}
@end

@interface NativePoseResultDelegate : NSObject <MPPPoseLandmarkerLiveStreamDelegate>
@end
@interface NativeHandResultDelegate : NSObject <MPPHandLandmarkerLiveStreamDelegate>
@end
@interface NativeFaceResultDelegate : NSObject <MPPFaceLandmarkerLiveStreamDelegate>
@end
@implementation NativePoseResultDelegate
- (void)poseLandmarker:(MPPPoseLandmarker *)landmarker didFinishDetectionWithResult:(MPPPoseLandmarkerResult *)result timestampInMilliseconds:(NSInteger)timestamp error:(NSError *)error {
    if (s_unityObject == nil || landmarker != s_landmarker || timestamp < s_orientationReadyTimestamp.load()) return;
    if (result == nil) return;
    NSArray *points = result.landmarks.firstObject;
    NSArray<MPPLandmark *> *world = result.worldLandmarks.firstObject;
    NSArray *names = @[@"nose", @"left_eye_inner", @"left_eye", @"left_eye_outer", @"right_eye_inner", @"right_eye", @"right_eye_outer", @"left_ear", @"right_ear", @"mouth_left", @"mouth_right", @"left_shoulder", @"right_shoulder", @"left_elbow", @"right_elbow", @"left_wrist", @"right_wrist", @"left_pinky", @"right_pinky", @"left_index", @"right_index", @"left_thumb", @"right_thumb", @"left_hip", @"right_hip", @"left_knee", @"right_knee", @"left_ankle", @"right_ankle", @"left_heel", @"right_heel", @"left_foot_index", @"right_foot_index"];
    NSMutableArray *jsonPoints = [NSMutableArray array];
    NSMutableArray<NSValue *> *privacyPoints = [NSMutableArray array];
    for (NSUInteger i = 0; i < points.count && i < world.count && i < names.count; ++i) {
        MPPNormalizedLandmark *p = points[i];
        MPPLandmark *w = world[i];
        [privacyPoints addObject:[NSValue valueWithCGPoint:CGPointMake(p.x, p.y)]];
        // Match the Windows protocol: raw MediaPipe world axes, image coordinates
        // separately, and visibility as confidence. Unity performs axis conversion.
        [jsonPoints addObject:@{@"name": names[i], @"x": @(w.x), @"y": @(w.y), @"z": @(w.z), @"confidence": p.visibility ?: @0.0, @"image_x": @(p.x), @"image_y": @(p.y), @"image_z": @(p.z)}];
    }
    @synchronized(PrivacyGate()) {
        s_posePrivacyPoints = [privacyPoints copy];
        s_hasLeftPoseWrist = points.count > 15;
        s_hasRightPoseWrist = points.count > 16;
        if (s_hasLeftPoseWrist) { MPPNormalizedLandmark *p = points[15]; s_leftPoseWrist = CGPointMake(p.x, p.y); }
        if (s_hasRightPoseWrist) { MPPNormalizedLandmark *p = points[16]; s_rightPoseWrist = CGPointMake(p.x, p.y); }
    }
    NSDictionary *packet = @{@"version": @4, @"frame": @(timestamp), @"timestamp_ms": @((long long)(NSDate.date.timeIntervalSince1970 * 1000)), @"source_width": @(s_width.load()), @"source_height": @(s_height.load()), @"tracking": @(jsonPoints.count > 0), @"points": jsonPoints};
    SubmitResult(@"pose", packet, timestamp);
}
@end

@implementation NativeHandResultDelegate
- (void)handLandmarker:(MPPHandLandmarker *)landmarker didFinishDetectionWithResult:(MPPHandLandmarkerResult *)result timestampInMilliseconds:(NSInteger)timestamp error:(NSError *)error {
    if (!result || !s_unityObject || timestamp < s_orientationReadyTimestamp.load()) return;
    NSArray *names = @[@"wrist", @"thumb_cmc", @"thumb_mcp", @"thumb_ip", @"thumb", @"index_mcp", @"index_pip", @"index_dip", @"index", @"middle_mcp", @"middle_pip", @"middle_dip", @"middle", @"ring_mcp", @"ring_pip", @"ring_dip", @"ring", @"pinky_mcp", @"pinky_pip", @"pinky_dip", @"pinky"];
    NSMutableArray *points = [NSMutableArray array];
    NSMutableArray<NSValue *> *privacyPoints = [NSMutableArray array];
    NSMutableArray<NSString *> *sides = [NSMutableArray array];
    NSMutableArray<NSNumber *> *scores = [NSMutableArray array];
    CGPoint leftWrist, rightWrist; BOOL hasLeft, hasRight;
    @synchronized(PrivacyGate()) { leftWrist = s_leftPoseWrist; rightWrist = s_rightPoseWrist; hasLeft = s_hasLeftPoseWrist; hasRight = s_hasRightPoseWrist; }
    for (NSUInteger h = 0; h < result.landmarks.count; ++h) {
        NSArray *image = result.landmarks[h];
        if (image.count == 0) { [sides addObject:@"right"]; [scores addObject:@0.0]; continue; }
        MPPNormalizedLandmark *wrist = image[0];
        MPPCategory *category = h < result.handedness.count ? [result.handedness[h] firstObject] : nil;
        NSString *side = category.categoryName.lowercaseString ?: @"";
        if (hasLeft || hasRight) {
            CGFloat leftDistance = hasLeft ? hypot(wrist.x - leftWrist.x, wrist.y - leftWrist.y) : CGFLOAT_MAX;
            CGFloat rightDistance = hasRight ? hypot(wrist.x - rightWrist.x, wrist.y - rightWrist.y) : CGFLOAT_MAX;
            side = leftDistance <= rightDistance ? @"left" : @"right";
        } else if (![side isEqualToString:@"left"] && ![side isEqualToString:@"right"]) {
            side = wrist.x > .5 ? @"left" : @"right";
        }
        [sides addObject:side];
        [scores addObject:@(category ? category.score : .5f)];
    }
    if (sides.count == 2 && [sides[0] isEqualToString:sides[1]]) {
        MPPNormalizedLandmark *a = [result.landmarks[0] firstObject];
        MPPNormalizedLandmark *b = [result.landmarks[1] firstObject];
        sides[0] = a.x > b.x ? @"left" : @"right";
        sides[1] = a.x > b.x ? @"right" : @"left";
    }
    int leftCount = 0, rightCount = 0;
    for (NSUInteger h = 0; h < result.landmarks.count; h++) {
        NSArray *image = result.landmarks[h]; NSArray *world = h < result.worldLandmarks.count ? result.worldLandmarks[h] : @[];
        NSString *side = sides[h];
        float score = scores[h].floatValue;
        for (NSUInteger i = 0; i < image.count && i < world.count && i < names.count; i++) {
            MPPNormalizedLandmark *p = image[i]; MPPLandmark *w = world[i];
            [privacyPoints addObject:[NSValue valueWithCGPoint:CGPointMake(p.x, p.y)]];
            [points addObject:@{@"name": [NSString stringWithFormat:@"%@_hand_%@", side, names[i]], @"x": @(w.x), @"y": @(w.y), @"z": @(w.z), @"confidence": @(score), @"image_x": @(p.x), @"image_y": @(p.y), @"image_z": @(p.z)}];
        }
        if (image.count > 17 && world.count > 17) {
            NSArray<NSNumber *> *indices = @[@5, @9, @17];
            float ix = 0, iy = 0, iz = 0, wx = 0, wy = 0, wz = 0;
            for (NSNumber *number in indices) {
                NSUInteger i = number.unsignedIntegerValue; MPPNormalizedLandmark *p = image[i]; MPPLandmark *w = world[i];
                ix += p.x; iy += p.y; iz += p.z; wx += w.x; wy += w.y; wz += w.z;
            }
            [points addObject:@{@"name": [NSString stringWithFormat:@"%@_hand_palm", side], @"x": @(wx / 3), @"y": @(wy / 3), @"z": @(wz / 3), @"confidence": @(score), @"image_x": @(ix / 3), @"image_y": @(iy / 3), @"image_z": @(iz / 3)}];
        }
        if ([side isEqualToString:@"left"]) leftCount = (int)MIN(image.count + 1, 22); else rightCount = (int)MIN(image.count + 1, 22);
    }
    @synchronized(PrivacyGate()) { s_handPrivacyPoints = [privacyPoints copy]; s_handPrivacyTimestamp = timestamp; }
    NSDictionary *packet = @{@"version": @4, @"frame": @(timestamp), @"timestamp_ms": @(timestamp), @"source_width": @(s_width.load()), @"source_height": @(s_height.load()), @"tracking": @(points.count > 0), @"hand_count": @(result.landmarks.count), @"left_hand_points": @(leftCount), @"right_hand_points": @(rightCount), @"points": points};
    SubmitResult(@"hand", packet, timestamp);
}
@end

@implementation NativeFaceResultDelegate
- (void)faceLandmarker:(MPPFaceLandmarker *)landmarker didFinishDetectionWithResult:(MPPFaceLandmarkerResult *)result timestampInMilliseconds:(NSInteger)timestamp error:(NSError *)error {
    if (!result || !s_unityObject || landmarker != s_faceLandmarker || s_captureStopping.load() || timestamp < s_orientationReadyTimestamp.load()) return;
    NSMutableArray *blend = [NSMutableArray array];
    NSMutableArray *points = [NSMutableArray array];
    if (result.faceBlendshapes.count > 0) for (MPPCategory *c in result.faceBlendshapes.firstObject.categories)
        [blend addObject:@{@"name": c.categoryName ?: @"", @"score": @(c.score)}];
    // Match the Windows packet: these two image-space anchors drive continuous
    // camera framing so the avatar face stays on top of the captured face.
    NSArray<MPPNormalizedLandmark *> *face = result.faceLandmarks.firstObject;
    if (face.count > 152) {
        NSArray<NSString *> *names = @[@"face_top", @"face_chin"];
        NSArray<NSNumber *> *indices = @[@10, @152];
        for (NSUInteger i = 0; i < indices.count; ++i) {
            MPPNormalizedLandmark *p = face[indices[i].unsignedIntegerValue];
            [points addObject:@{@"name": names[i], @"x": @0.0, @"y": @0.0, @"z": @0.0,
                                @"confidence": @1.0, @"image_x": @(p.x), @"image_y": @(p.y), @"image_z": @(p.z)}];
        }
    }
    NSMutableDictionary *packet = [@{@"version": @4, @"frame": @(timestamp), @"timestamp_ms": @(timestamp), @"source_width": @(s_width.load()), @"source_height": @(s_height.load()), @"tracking": @(result.faceLandmarks.count > 0), @"face_blendshapes": blend, @"points": points} mutableCopy];
    NSDictionary *headRotation = HeadRotationFromFaceMatrix(result.facialTransformationMatrixes.firstObject);
    if (headRotation != nil) packet[@"head_rotation"] = headRotation;
    NSMutableArray<NSValue *> *privacy = [NSMutableArray array];
    for (MPPNormalizedLandmark *p in result.faceLandmarks.firstObject)
        [privacy addObject:[NSValue valueWithCGPoint:CGPointMake(p.x,p.y)]];
    @synchronized(PrivacyGate()) { s_facePrivacyPoints=[privacy copy]; s_facePrivacyTimestamp=timestamp; }
    SubmitResult(@"face", packet, timestamp);
}
@end

static NativePoseCaptureDelegate *s_delegate;
static NativePoseResultDelegate *s_resultDelegate;
static NativeHandResultDelegate *s_handDelegate;
static NativeFaceResultDelegate *s_faceDelegate;
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
    s_latestHandPacket = nil; s_latestFacePacket = nil;
    s_latestHandTimestamp = 0; s_latestFaceTimestamp = 0;
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
    options.runningMode = MPPRunningModeLiveStream;
    options.numPoses = 1;
    options.shouldOutputSegmentationMasks = NO;
    s_resultDelegate = [NativePoseResultDelegate new];
    options.poseLandmarkerLiveStreamDelegate = s_resultDelegate;
    s_landmarker = [[MPPPoseLandmarker alloc] initWithOptions:options error:nil];
    if (s_landmarker == nil) return -4;
    NSString *handPath = [[NSBundle mainBundle] pathForResource:@"hand_landmarker" ofType:@"task" inDirectory:@"Data/Raw"];
    NSString *facePath = [[NSBundle mainBundle] pathForResource:@"face_landmarker" ofType:@"task" inDirectory:@"Data/Raw"];
    if (!handPath || !facePath) return -7;
    MPPHandLandmarkerOptions *handOptions = [MPPHandLandmarkerOptions new];
    handOptions.baseOptions.modelAssetPath = handPath; handOptions.runningMode = MPPRunningModeLiveStream; handOptions.numHands = 2;
    handOptions.minHandDetectionConfidence = .35f;
    handOptions.minHandPresenceConfidence = .35f;
    handOptions.minTrackingConfidence = .35f;
    s_handDelegate = [NativeHandResultDelegate new]; handOptions.handLandmarkerLiveStreamDelegate = s_handDelegate;
    s_handLandmarker = [[MPPHandLandmarker alloc] initWithOptions:handOptions error:nil];
    MPPFaceLandmarkerOptions *faceOptions = [MPPFaceLandmarkerOptions new];
    faceOptions.baseOptions.modelAssetPath = facePath; faceOptions.runningMode = MPPRunningModeLiveStream; faceOptions.numFaces = 1; faceOptions.outputFaceBlendshapes = YES; faceOptions.outputFacialTransformationMatrixes = YES;
    s_faceDelegate = [NativeFaceResultDelegate new]; faceOptions.faceLandmarkerLiveStreamDelegate = s_faceDelegate;
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
    s_latestHandPacket = nil; s_latestFacePacket = nil;
    s_latestHandTimestamp = 0; s_latestFaceTimestamp = 0;
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
        s_hasLeftPoseWrist = NO;
        s_hasRightPoseWrist = NO;
    }
    s_unityObject = nil;
    s_queue = nil;
    s_session = nil;
    s_stopping = NO;
}
