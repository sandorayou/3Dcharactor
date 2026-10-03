#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <CoreImage/CoreImage.h>
#import "UnityInterface.h"
#import <MediaPipeTasksVision/MediaPipeTasksVision.h>

#include <atomic>
#include <cmath>
#include <vector>
#include <algorithm>
static std::atomic<int> s_width{640}, s_height{480};
static std::atomic<long long> s_orientationReadyTimestamp{0};
static AVCaptureSession *s_session;
static AVCaptureVideoDataOutput *s_output;
static dispatch_queue_t s_queue;
static float s_skinCb = 105.f, s_skinCr = 151.f;
static bool s_skinRegistered = false;
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

static CIImage *WindowsStyleMosaic(CIImage *source, CGFloat scale) {
    CIFilter *pixelate = [CIFilter filterWithName:@"CIPixellate"];
    [pixelate setValue:source forKey:kCIInputImageKey];
    // Preserve the existing 48-pixel face mosaic.
    [pixelate setValue:@(MAX(2.0, scale)) forKey:kCIInputScaleKey];
    [pixelate setValue:[CIVector vectorWithX:CGRectGetMidX(source.extent)
                                           Y:CGRectGetMidY(source.extent)]
                 forKey:kCIInputCenterKey];
    return [pixelate.outputImage imageByCroppingToRect:source.extent];
}

static CVPixelBufferRef ColourFrame(CIImage *source) {
    size_t width = 160, height = MAX(1, (size_t)(160 * source.extent.size.height / source.extent.size.width));
    CVPixelBufferRef buffer = nullptr;
    if (CVPixelBufferCreate(kCFAllocatorDefault, width, height, kCVPixelFormatType_32BGRA,
                           nullptr, &buffer) != kCVReturnSuccess) return nullptr;
    CIImage *small = [source imageByApplyingTransform:CGAffineTransformMakeScale(
        width / source.extent.size.width, height / source.extent.size.height)];
    [s_ciContext render:small toCVPixelBuffer:buffer];
    return buffer;
}

static CIImage *AdaptiveSkinMask(CVPixelBufferRef current) {
    if (current == nullptr || CVPixelBufferLockBaseAddress(current, kCVPixelBufferLock_ReadOnly) != kCVReturnSuccess) return nil;
    const int width = (int)CVPixelBufferGetWidth(current), height = (int)CVPixelBufferGetHeight(current);
    const size_t stride = CVPixelBufferGetBytesPerRow(current);
    const auto *pixels = static_cast<const unsigned char *>(CVPixelBufferGetBaseAddress(current));
    const size_t count = (size_t)width * height;
    std::vector<unsigned char> raw(count), dilated(count), closed(count), outside(count);
    std::vector<float> luminance(count);
    float sumCb=0, sumCr=0, sumY=0; int samples=0;
    for (int y=0; y<height; ++y) for (int x=0; x<width; ++x) {
        const auto *p = pixels + y*stride + x*4;
        const float luma = .299f*p[2] + .587f*p[1] + .114f*p[0];
        const float cb = 128.f + .564f*(p[0]-luma), cr = 128.f + .713f*(p[2]-luma);
        const float dc=(cb-s_skinCb)/9.f, dr=(cr-s_skinCr)/8.f, distance=dc*dc+dr*dr;
        const bool skin = luma>20 && luma<250 && cr>132 && cb<132 && cr<s_skinCr+7 && distance<1.44f;
        raw[y*width+x] = skin ? 255 : 0;
        luminance[y*width+x] = luma;
        if (skin && distance<.64f && x>=width*35/100 && x<width*65/100 && y>=height/10 && y<height*3/5) {
            sumCb+=cb; sumCr+=cr; sumY+=luma; ++samples;
        }
    }
    CVPixelBufferUnlockBaseAddress(current, kCVPixelBufferLock_ReadOnly);
    if (samples>=40) for(size_t i=0;i<count;++i)
        if(luminance[i]<sumY/samples*.8f) raw[i]=0;
    // Separable closing: four 9-pixel passes instead of two 9x9 passes.
    std::vector<unsigned char> temporary(count);
    for (int y=0; y<height; ++y) for (int x=0; x<width; ++x) {
        unsigned char value=0;
        for(int dx=-4;dx<=4;++dx) value=MAX(value,raw[y*width+ClampColour(x+dx,0,width-1)]);
        temporary[y*width+x]=value;
    }
    for (int y=0; y<height; ++y) for (int x=0; x<width; ++x) {
        unsigned char value=0;
        for(int dy=-4;dy<=4;++dy) value=MAX(value,temporary[ClampColour(y+dy,0,height-1)*width+x]);
        dilated[y*width+x]=value;
    }
    for (int y=0; y<height; ++y) for (int x=0; x<width; ++x) {
        unsigned char value=255;
        for(int dx=-4;dx<=4;++dx) value=MIN(value,dilated[y*width+ClampColour(x+dx,0,width-1)]);
        temporary[y*width+x]=value;
    }
    for (int y=0; y<height; ++y) for (int x=0; x<width; ++x) {
        unsigned char value=255;
        for(int dy=-4;dy<=4;++dy) value=MIN(value,temporary[ClampColour(y+dy,0,height-1)*width+x]);
        closed[y*width+x]=value;
    }
    // Bridge short bounded horizontal gaps even when an eye hole reaches the frame edge.
    for(int y=0;y<height;++y) {
        int x=0;
        while(x<width) {
            if(closed[y*width+x]) { ++x; continue; }
            int start=x;
            while(x<width && !closed[y*width+x]) ++x;
            if(start>0 && x<width && x-start<=width/5)
                for(int fill=start;fill<x;++fill) closed[y*width+fill]=255;
        }
    }
    std::vector<int> queue;
    queue.reserve(count);
    auto add = [&](int x,int y) {
        int index=y*width+x;
        if (!closed[index] && !outside[index]) { outside[index]=255; queue.push_back(index); }
    };
    for (int x=0; x<width; ++x) { add(x,0); add(x,height-1); }
    for (int y=0; y<height; ++y) { add(0,y); add(width-1,y); }
    for (size_t head=0; head<queue.size(); ++head) {
        int x=queue[head]%width, y=queue[head]/width;
        if (x>0) add(x-1,y); if(x+1<width) add(x+1,y);
        if (y>0) add(x,y-1); if(y+1<height) add(x,y+1);
    }
    for (size_t i=0;i<count;++i) closed[i]=closed[i] || !outside[i] ? 255 : 0;
    CVPixelBufferRef bitmap=nullptr;
    if (CVPixelBufferCreate(kCFAllocatorDefault,width,height,kCVPixelFormatType_32BGRA,nullptr,&bitmap)!=kCVReturnSuccess) return nil;
    if (CVPixelBufferLockBaseAddress(bitmap,0)!=kCVReturnSuccess) { CVPixelBufferRelease(bitmap); return nil; }
    auto *output=static_cast<unsigned char *>(CVPixelBufferGetBaseAddress(bitmap));
    const size_t outputStride=CVPixelBufferGetBytesPerRow(bitmap);
    for(int y=0;y<height;++y) for(int x=0;x<width;++x) {
        unsigned char value=0;
        for(int dy=-1;dy<=1;++dy) for(int dx=-1;dx<=1;++dx)
            value=MAX(value,closed[ClampColour(y+dy,0,height-1)*width+ClampColour(x+dx,0,width-1)]);
        auto *p=output+y*outputStride+x*4;
        p[0]=p[1]=p[2]=value; p[3]=255;
    }
    CVPixelBufferUnlockBaseAddress(bitmap,0);
    CIImage *mask=[CIImage imageWithCVPixelBuffer:bitmap];
    CVPixelBufferRelease(bitmap);
    if(samples>=40) {
        float rate=s_skinRegistered ? .04f : .25f;
        s_skinCb=ClampColour(s_skinCb+ClampColour(sumCb/samples-s_skinCb,-4.f,4.f)*rate,95.f,115.f);
        s_skinCr=ClampColour(s_skinCr+ClampColour(sumCr/samples-s_skinCr,-4.f,4.f)*rate,143.f,165.f);
        s_skinRegistered=true;
    }
    return mask;
}

static void DisplayLiveBackground(CIImage *source, CIImage *mask, NSInteger timestamp) {
    if (source == nil || s_backgroundLayer == nil) return;
    CIImage *processed = source;
    if (mask != nil) {
        mask = [[mask imageByApplyingTransform:CGAffineTransformMakeScale(
            source.extent.size.width / mask.extent.size.width,
            source.extent.size.height / mask.extent.size.height)] imageByCroppingToRect:source.extent];
        processed = [WindowsStyleMosaic(source, s_mosaicScale) imageByApplyingFilter:@"CIBlendWithMask"
            withInputParameters:@{kCIInputBackgroundImageKey:source, kCIInputMaskImageKey:mask}];
    }
    CGImageRef frame = [s_ciContext createCGImage:processed fromRect:source.extent];
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
    DisplayLiveBackground(source, AdaptiveSkinMask(colours), timestamp);
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
    s_skinCb=105.f; s_skinCr=151.f; s_skinRegistered=false;
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
