#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <CoreImage/CoreImage.h>
#import "UnityInterface.h"
#import <MediaPipeTasksVision/MediaPipeTasksVision.h>

#include <atomic>
static std::atomic<int> s_width{640}, s_height{480};
static AVCaptureSession *s_session;
static AVCaptureVideoDataOutput *s_output;
static dispatch_queue_t s_queue;
static MPPPoseLandmarker *s_landmarker;
static MPPHandLandmarker *s_handLandmarker;
static MPPFaceLandmarker *s_faceLandmarker;
static NSString *s_unityObject;
static long long s_frame;
static BOOL s_useFrontCamera = YES;
static CGFloat s_mosaicScale = 24.0;
static CALayer *s_backgroundLayer;
static CIContext *s_ciContext;
static CFTimeInterval s_lastBackgroundFrame;
static NSArray<NSValue *> *s_posePrivacyPoints;
static NSArray<NSValue *> *s_handPrivacyPoints;
static NSMutableDictionary<NSNumber *, NSDictionary *> *s_pendingCameraFrames;
static NSMutableDictionary<NSNumber *, UIImage *> *s_pendingProcessedFrames;
static NSObject *FrameGate() {
    static NSObject *gate;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ gate = [NSObject new]; });
    return gate;
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

static CIImage *PrivacyMask(CVPixelBufferRef pixelBuffer, CGRect extent) {
    const size_t width = 160, height = 120;
    NSMutableData *data = [NSMutableData dataWithLength:width * height];
    uint8_t *mask = (uint8_t *)data.mutableBytes;
    CVPixelBufferLockBaseAddress(pixelBuffer, kCVPixelBufferLock_ReadOnly);
    const uint8_t *pixels = (const uint8_t *)CVPixelBufferGetBaseAddress(pixelBuffer);
    size_t sourceWidth = CVPixelBufferGetWidth(pixelBuffer);
    size_t sourceHeight = CVPixelBufferGetHeight(pixelBuffer);
    size_t stride = CVPixelBufferGetBytesPerRow(pixelBuffer);
    for (size_t y = 0; y < height; ++y) {
        size_t sy = MIN(sourceHeight - 1, y * sourceHeight / height);
        for (size_t x = 0; x < width; ++x) {
            size_t sx = MIN(sourceWidth - 1, x * sourceWidth / width);
            const uint8_t *p = pixels + sy * stride + sx * 4;
            float b = p[0], g = p[1], r = p[2];
            float cb = 128.0f - .168736f * r - .331264f * g + .5f * b;
            float cr = 128.0f + .5f * r - .418688f * g - .081312f * b;
            BOOL rgbSkin = r > 55 && g > 30 && b > 15 && r > g * 1.04f && r > b * 1.08f && MAX(r, MAX(g, b)) - MIN(r, MIN(g, b)) > 12;
            BOOL chromaSkin = cb >= 75 && cb <= 135 && cr >= 130 && cr <= 180 && r > g;
            mask[y * width + x] = (rgbSkin && chromaSkin) ? 255 : 0;
        }
    }
    CVPixelBufferUnlockBaseAddress(pixelBuffer, kCVPixelBufferLock_ReadOnly);

    CGColorSpaceRef gray = CGColorSpaceCreateDeviceGray();
    CGContextRef context = CGBitmapContextCreate(mask, width, height, 8, width, gray, kCGImageAlphaNone);
    CGColorSpaceRelease(gray);
    CGContextSetBlendMode(context, kCGBlendModeLighten);
    CGContextSetGrayStrokeColor(context, 1, 1);
    CGContextSetGrayFillColor(context, 1, 1);
    CGContextSetLineCap(context, kCGLineCapRound);
    NSArray<NSValue *> *pose;
    NSArray<NSValue *> *hands;
    @synchronized(PrivacyGate()) {
        pose = [s_posePrivacyPoints copy] ?: @[];
        hands = [s_handPrivacyPoints copy] ?: @[];
    }
    const int links[][2] = {{0,11},{0,12},{11,12},{11,13},{13,15},{12,14},{14,16},{11,23},{12,24},{23,24},{23,25},{25,27},{24,26},{26,28}};
    CGContextSetLineWidth(context, 18);
    for (NSUInteger i = 0; i < sizeof(links) / sizeof(links[0]); ++i) {
        if (links[i][0] >= pose.count || links[i][1] >= pose.count) continue;
        CGPoint a = pose[links[i][0]].CGPointValue, b = pose[links[i][1]].CGPointValue;
        CGContextMoveToPoint(context, a.x * width, (1.0 - a.y) * height);
        CGContextAddLineToPoint(context, b.x * width, (1.0 - b.y) * height);
        CGContextStrokePath(context);
    }
    for (NSValue *value in pose) {
        CGPoint p = value.CGPointValue;
        CGContextFillEllipseInRect(context, CGRectMake(p.x * width - 7, (1.0 - p.y) * height - 7, 14, 14));
    }
    for (NSValue *value in hands) {
        CGPoint p = value.CGPointValue;
        CGContextFillEllipseInRect(context, CGRectMake(p.x * width - 5, (1.0 - p.y) * height - 5, 10, 10));
    }
    CGImageRef maskImage = CGBitmapContextCreateImage(context);
    CGContextRelease(context);
    CIImage *result = [[CIImage imageWithCGImage:maskImage] imageByApplyingTransform:CGAffineTransformMakeScale(extent.size.width / width, extent.size.height / height)];
    CGImageRelease(maskImage);
    CIFilter *expand = [CIFilter filterWithName:@"CIGaussianBlur"];
    [expand setValue:result forKey:kCIInputImageKey];
    [expand setValue:@18 forKey:kCIInputRadiusKey];
    return [expand.outputImage imageByCroppingToRect:extent];
}

static CIImage *WindowsStylePersonMask(MPPMask *mask, CGRect extent) {
    if (mask == nil || mask.width <= 0 || mask.height <= 0) return nil;
    const NSInteger width = mask.width, height = mask.height;
    NSMutableData *thresholded = [NSMutableData dataWithLength:width * height];
    uint8_t *bytes = (uint8_t *)thresholded.mutableBytes;
    const float *confidence = mask.float32Data;
    for (NSInteger i = 0; i < width * height; ++i)
        bytes[i] = confidence[i] > .18f ? 255 : 0;
    CGColorSpaceRef gray = CGColorSpaceCreateDeviceGray();
    CGContextRef bitmap = CGBitmapContextCreate(bytes, width, height, 8, width, gray, kCGImageAlphaNone);
    CGColorSpaceRelease(gray);
    CGImageRef image = CGBitmapContextCreateImage(bitmap);
    CGContextRelease(bitmap);
    CIImage *result = [CIImage imageWithCGImage:image];
    CGImageRelease(image);
    result = [result imageByApplyingTransform:CGAffineTransformMakeScale(
        extent.size.width / width, extent.size.height / height)];
    CIFilter *dilate = [CIFilter filterWithName:@"CIMorphologyMaximum"];
    [dilate setValue:result forKey:kCIInputImageKey];
    [dilate setValue:@(60.0 * extent.size.width / 640.0) forKey:kCIInputRadiusKey];
    CIFilter *blur = [CIFilter filterWithName:@"CIGaussianBlur"];
    [blur setValue:dilate.outputImage forKey:kCIInputImageKey];
    [blur setValue:@(20.0 * extent.size.width / 640.0) forKey:kCIInputRadiusKey];
    CIFilter *amplify = [CIFilter filterWithName:@"CIColorMatrix"];
    [amplify setValue:blur.outputImage forKey:kCIInputImageKey];
    [amplify setValue:[CIVector vectorWithX:2 Y:0 Z:0 W:0] forKey:@"inputRVector"];
    [amplify setValue:[CIVector vectorWithX:0 Y:2 Z:0 W:0] forKey:@"inputGVector"];
    [amplify setValue:[CIVector vectorWithX:0 Y:0 Z:2 W:0] forKey:@"inputBVector"];
    return [amplify.outputImage imageByCroppingToRect:extent];
}

static CIImage *WindowsStyleMosaic(CIImage *source) {
    CGRect extent = source.extent;
    CIFilter *downsample = [CIFilter filterWithName:@"CILanczosScaleTransform"];
    CGFloat scale = 8.0 / extent.size.height;
    [downsample setValue:source forKey:kCIInputImageKey];
    [downsample setValue:@(scale) forKey:kCIInputScaleKey];
    [downsample setValue:@((10.0 / extent.size.width) / scale) forKey:kCIInputAspectRatioKey];
    CGImageRef tinyImage = [s_ciContext createCGImage:downsample.outputImage fromRect:CGRectMake(0, 0, 10, 8)];
    if (tinyImage == nil) return source;
    CIImage *tiny = [[CIImage imageWithCGImage:tinyImage] imageBySamplingNearest];
    CGImageRelease(tinyImage);
    return [[tiny imageByApplyingTransform:CGAffineTransformMakeScale(
        extent.size.width / 10.0, extent.size.height / 8.0)] imageByCroppingToRect:extent];
}

static void DisplaySynchronizedBackground(MPPPoseLandmarkerResult *result, NSInteger timestamp) {
    NSDictionary *captured = nil;
    @synchronized(FrameGate()) {
        captured = s_pendingCameraFrames[@(timestamp)];
        for (NSNumber *key in [s_pendingCameraFrames.allKeys copy])
            if (key.longLongValue <= timestamp) [s_pendingCameraFrames removeObjectForKey:key];
    }
    CIImage *source = captured[@"source"];
    if (source == nil || s_backgroundLayer == nil) return;
    if (s_ciContext == nil) s_ciContext = [CIContext contextWithOptions:@{kCIContextUseSoftwareRenderer: @NO}];
    CIImage *processed = source;
    CIImage *mask = WindowsStylePersonMask(result.segmentationMasks.firstObject, source.extent);
    CIImage *skinAndTrackerMask = captured[@"privacy"];
    if (mask != nil && skinAndTrackerMask != nil) {
        CIFilter *unionFilter = [CIFilter filterWithName:@"CIMaximumCompositing"];
        [unionFilter setValue:mask forKey:kCIInputImageKey];
        [unionFilter setValue:skinAndTrackerMask forKey:kCIInputBackgroundImageKey];
        mask = [unionFilter.outputImage imageByCroppingToRect:source.extent];
    } else if (mask == nil) {
        mask = skinAndTrackerMask;
    }
    if (mask != nil) {
        CIFilter *blend = [CIFilter filterWithName:@"CIBlendWithMask"];
        [blend setValue:WindowsStyleMosaic(source) forKey:kCIInputImageKey];
        [blend setValue:source forKey:kCIInputBackgroundImageKey];
        [blend setValue:mask forKey:kCIInputMaskImageKey];
        processed = [blend.outputImage imageByCroppingToRect:source.extent];
    }
    CGImageRef frame = [s_ciContext createCGImage:processed fromRect:source.extent];
    if (frame != nil) {
        UIImage *image = [UIImage imageWithCGImage:frame];
        CGImageRelease(frame);
        @synchronized(FrameGate()) {
            if (s_pendingProcessedFrames == nil) s_pendingProcessedFrames = [NSMutableDictionary dictionary];
            s_pendingProcessedFrames[@(timestamp)] = image;
            while (s_pendingProcessedFrames.count > 8) {
                NSNumber *oldest = [[s_pendingProcessedFrames.allKeys sortedArrayUsingSelector:@selector(compare:)] firstObject];
                [s_pendingProcessedFrames removeObjectForKey:oldest];
            }
        }
    }
}
// Each detector completes independently. Publish only matching capture timestamps.
static void SubmitResult(NSString *kind, NSDictionary *packet, NSInteger timestamp) {
    static NSMutableDictionary *pending;
    static NSObject *gate;
    static dispatch_once_t once;
    dispatch_once(&once, ^{ pending = [NSMutableDictionary dictionary]; gate = [NSObject new]; });
    @synchronized(gate) {
        NSNumber *key = @(timestamp);
        NSMutableDictionary *parts = pending[key];
        if (!parts) { parts = [NSMutableDictionary dictionary]; pending[key] = parts; }
        parts[kind] = packet;
        if (parts.count == 3) {
            NSMutableDictionary *combined = [parts[@"pose"] mutableCopy];
            NSMutableArray *points = [combined[@"points"] mutableCopy];
            [points addObjectsFromArray:parts[@"hand"][@"points"]];
            [points addObjectsFromArray:parts[@"face"][@"points"]];
            combined[@"points"] = points;
            combined[@"hand_count"] = parts[@"hand"][@"hand_count"] ?: @0;
            combined[@"left_hand_points"] = parts[@"hand"][@"left_hand_points"] ?: @0;
            combined[@"right_hand_points"] = parts[@"hand"][@"right_hand_points"] ?: @0;
            combined[@"face_blendshapes"] = parts[@"face"][@"face_blendshapes"];
            combined[@"frame"] = @(s_frame++);
            NSData *data = [NSJSONSerialization dataWithJSONObject:combined options:0 error:nil];
            NSString *json = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            NSString *receiver = [s_unityObject copy];
            UIImage *background = nil;
            @synchronized(FrameGate()) {
                background = s_pendingProcessedFrames[@(timestamp)];
                for (NSNumber *old in [s_pendingProcessedFrames.allKeys copy])
                    if (old.longLongValue <= timestamp) [s_pendingProcessedFrames removeObjectForKey:old];
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                if (background != nil && s_backgroundLayer != nil)
                    s_backgroundLayer.contents = (__bridge id)background.CGImage;
                if (receiver && [receiver isEqualToString:s_unityObject] && json)
                    UnitySendMessage(receiver.UTF8String, "OnNativePoseJson", json.UTF8String);
            });
            for (NSNumber *old in [pending.allKeys copy])
                if (old.longLongValue <= timestamp) [pending removeObjectForKey:old];
        }
        // Live-stream detectors can drop frames independently. Bound incomplete frames.
        while (pending.count > 8) {
            NSNumber *oldest = [[pending.allKeys sortedArrayUsingSelector:@selector(compare:)] firstObject];
            [pending removeObjectForKey:oldest];
        }
    }
}

@interface NativePoseCaptureDelegate : NSObject <AVCaptureVideoDataOutputSampleBufferDelegate>
@end

@implementation NativePoseCaptureDelegate
- (void)captureOutput:(AVCaptureOutput *)output
 didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer
        fromConnection:(AVCaptureConnection *)connection {
    CVPixelBufferRef pixelBuffer = CMSampleBufferGetImageBuffer(sampleBuffer);
    if (pixelBuffer == nil) return;

    if (s_landmarker == nil || s_unityObject == nil) return;
    s_width = (int)CVPixelBufferGetWidth(pixelBuffer);
    s_height = (int)CVPixelBufferGetHeight(pixelBuffer);
    MPPImage *image = [[MPPImage alloc] initWithPixelBuffer:pixelBuffer error:nil];
    if (image == nil) return;
    NSInteger timestamp = (NSInteger)(CACurrentMediaTime() * 1000.0);
    @synchronized(FrameGate()) {
        if (s_pendingCameraFrames == nil) s_pendingCameraFrames = [NSMutableDictionary dictionary];
        CIImage *source = [CIImage imageWithCVPixelBuffer:pixelBuffer];
        CIImage *privacy = PrivacyMask(pixelBuffer, source.extent);
        s_pendingCameraFrames[@(timestamp)] = @{@"source": source, @"privacy": privacy};
        while (s_pendingCameraFrames.count > 8) {
            NSNumber *oldest = [[s_pendingCameraFrames.allKeys sortedArrayUsingSelector:@selector(compare:)] firstObject];
            [s_pendingCameraFrames removeObjectForKey:oldest];
        }
    }
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
    if (result == nil || s_unityObject == nil) return;
    DisplaySynchronizedBackground(result, timestamp);
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
    if (!result || !s_unityObject) return;
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
    @synchronized(PrivacyGate()) { s_handPrivacyPoints = [privacyPoints copy]; }
    NSDictionary *packet = @{@"version": @4, @"frame": @(timestamp), @"timestamp_ms": @(timestamp), @"source_width": @(s_width.load()), @"source_height": @(s_height.load()), @"tracking": @(points.count > 0), @"hand_count": @(result.landmarks.count), @"left_hand_points": @(leftCount), @"right_hand_points": @(rightCount), @"points": points};
    SubmitResult(@"hand", packet, timestamp);
}
@end

@implementation NativeFaceResultDelegate
- (void)faceLandmarker:(MPPFaceLandmarker *)landmarker didFinishDetectionWithResult:(MPPFaceLandmarkerResult *)result timestampInMilliseconds:(NSInteger)timestamp error:(NSError *)error {
    if (!result || !s_unityObject) return;
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
    NSDictionary *packet = @{@"version": @4, @"frame": @(timestamp), @"timestamp_ms": @(timestamp), @"source_width": @(s_width.load()), @"source_height": @(s_height.load()), @"tracking": @(result.faceLandmarks.count > 0), @"face_blendshapes": blend, @"points": points};
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
    if (ui == UIInterfaceOrientationLandscapeLeft) orientation = AVCaptureVideoOrientationLandscapeLeft;
    else if (ui == UIInterfaceOrientationLandscapeRight) orientation = AVCaptureVideoOrientationLandscapeRight;
    AVCaptureConnection *video = [s_output connectionWithMediaType:AVMediaTypeVideo];
    if (video.isVideoOrientationSupported) video.videoOrientation = orientation;
    if (video.isVideoMirroringSupported) {
        video.automaticallyAdjustsVideoMirroring = NO;
        video.videoMirrored = s_useFrontCamera;
    }
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
    s_unityObject = [NSString stringWithUTF8String:unityObjectName ?: ""];
    if ([AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo] == AVAuthorizationStatusNotDetermined) {
        [AVCaptureDevice requestAccessForMediaType:AVMediaTypeVideo completionHandler:^(BOOL granted) {
            dispatch_async(dispatch_get_main_queue(), ^{
                if (granted) UnitySendMessage(s_unityObject.UTF8String, "OnNativeCameraPermissionGranted", "");
                else NotifyCameraState(@"camera_permission_denied");
            });
        }];
        return -6;
    } else if ([AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo] != AVAuthorizationStatusAuthorized) {
        NotifyCameraState(@"camera_permission_denied");
        return -5;
    }
    NSString *modelPath = [[NSBundle mainBundle] pathForResource:@"pose_landmarker_full" ofType:@"bytes" inDirectory:@"Data/Raw"];
    if (modelPath == nil) return -3;
    MPPPoseLandmarkerOptions *options = [MPPPoseLandmarkerOptions new];
    options.baseOptions.modelAssetPath = modelPath;
    options.runningMode = MPPRunningModeLiveStream;
    options.numPoses = 1;
    options.shouldOutputSegmentationMasks = YES;
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
    faceOptions.baseOptions.modelAssetPath = facePath; faceOptions.runningMode = MPPRunningModeLiveStream; faceOptions.numFaces = 1; faceOptions.outputFaceBlendshapes = YES;
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
    [s_session stopRunning];
    [s_output setSampleBufferDelegate:nil queue:NULL];
    [s_backgroundLayer removeFromSuperlayer];
    s_backgroundLayer = nil;
    s_ciContext = nil;
    @synchronized(FrameGate()) {
        [s_pendingCameraFrames removeAllObjects]; s_pendingCameraFrames = nil;
        [s_pendingProcessedFrames removeAllObjects]; s_pendingProcessedFrames = nil;
    }
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
        s_handPrivacyPoints = nil;
        s_hasLeftPoseWrist = NO;
        s_hasRightPoseWrist = NO;
    }
    s_unityObject = nil;
    s_queue = nil;
    s_session = nil;
    s_stopping = NO;
}
