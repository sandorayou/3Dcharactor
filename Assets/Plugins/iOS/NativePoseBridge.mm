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
static AVCaptureSession *s_session;
static AVCaptureVideoDataOutput *s_output;
static dispatch_queue_t s_queue;
static MPPPoseLandmarker *s_landmarker;
static MPPHandLandmarker *s_handLandmarker;
static MPPFaceLandmarker *s_faceLandmarker;
static NSString *s_unityObject;
static long long s_frame;
static BOOL s_useFrontCamera = YES;
static CGFloat s_mosaicScale = 16.0;
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
static NSMutableDictionary<NSNumber *, NSDictionary *> *s_pendingCameraFrames;
static NSMutableDictionary<NSNumber *, UIImage *> *s_pendingProcessedFrames;
static NSDictionary *s_latestHandPacket;
static NSDictionary *s_latestFacePacket;
static NSInteger s_latestHandTimestamp;
static NSInteger s_latestFaceTimestamp;
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

static BOOL ReliablePrivacyPoint(MPPNormalizedLandmark *point) {
    return isfinite(point.x) && isfinite(point.y) &&
           point.x >= 0 && point.x <= 1 && point.y >= 0 && point.y <= 1 &&
           // Visibility is per landmark. Do not discard the complete upper
           // body because one wrist/elbow is temporarily low confidence.
           point.visibility.floatValue >= .15f;
}

// Convex hulls cover the face profile and each hand without joining the two hands.
static void FillPrivacyHull(CGContextRef context, std::vector<CGPoint> points) {
    if (points.size() < 3) return;
    std::sort(points.begin(), points.end(), [](CGPoint a, CGPoint b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    auto cross = [](CGPoint a, CGPoint b, CGPoint c) {
        return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
    };
    std::vector<CGPoint> hull;
    for (const auto &p : points) {
        while (hull.size() >= 2 && cross(hull[hull.size()-2], hull.back(), p) <= 0) hull.pop_back();
        hull.push_back(p);
    }
    size_t lower = hull.size();
    for (size_t i = points.size()-1; i-- > 0;) {
        while (hull.size() > lower && cross(hull[hull.size()-2], hull.back(), points[i]) <= 0) hull.pop_back();
        hull.push_back(points[i]);
    }
    if (hull.size() < 4) return;
    CGContextAddLines(context, hull.data(), hull.size()-1);
    CGContextClosePath(context);
    CGContextFillPath(context);
}

static CIImage *CurrentPosePrivacyMask(MPPPoseLandmarkerResult *result, CGRect extent, NSInteger timestamp, BOOL faceOnly = NO) {
    NSArray<MPPNormalizedLandmark *> *points = result.landmarks.firstObject;
    if (points.count < 25) return nil;
    const size_t width = (size_t)extent.size.width, height = (size_t)extent.size.height;
    NSMutableData *data = [NSMutableData dataWithLength:width * height];
    CGColorSpaceRef gray = CGColorSpaceCreateDeviceGray();
    CGContextRef context = CGBitmapContextCreate(data.mutableBytes, width, height, 8, width, gray, kCGImageAlphaNone);
    CGColorSpaceRelease(gray);
    if (!context) return nil;
    CGContextSetGrayFillColor(context, 1, 1);
    CGContextSetGrayStrokeColor(context, 1, 1);
    CGContextSetLineCap(context, kCGLineCapRound);
    auto point = [&](NSUInteger i) { return CGPointMake(points[i].x*width, (1-points[i].y)*height); };
    CGFloat shoulder = MAX(fabs(point(11).x-point(12).x), width*10.0/320.0);
    CGFloat thickness = MAX(shoulder*.18, width*7.0/320.0);
    std::vector<CGPoint> torso;
    for (NSUInteger i : {11u,12u,24u,23u}) if (ReliablePrivacyPoint(points[i])) torso.push_back(point(i));
    if (!faceOnly) FillPrivacyHull(context, torso);
    CGContextSetLineWidth(context, thickness);
    const NSUInteger edges[][2] = {{11,13},{13,15},{12,14},{14,16},{23,25},{25,27},{24,26},{26,28}};
    for (auto &edge : edges) {
        if (faceOnly) break;
        if (edge[1]>=points.count || !ReliablePrivacyPoint(points[edge[0]]) || !ReliablePrivacyPoint(points[edge[1]])) continue;
        CGPoint a=point(edge[0]), b=point(edge[1]);
        CGContextMoveToPoint(context,a.x,a.y); CGContextAddLineToPoint(context,b.x,b.y); CGContextStrokePath(context);
        CGContextFillEllipseInRect(context,CGRectMake(b.x-thickness,b.y-thickness,thickness*2,thickness*2));
    }
    if (ReliablePrivacyPoint(points[0])) {
        CGPoint a=point(7), b=point(8);
        CGFloat span=fabs(a.x-b.x);
        if (span < width*8.0/320.0) { a=point(2); b=point(5); span=MAX(fabs(a.x-b.x)*2.2,width*10.0/320.0); }
        CGFloat rx=MAX(MAX(span*.68,shoulder*.38),width*12.0/320.0);
        CGFloat ry=MAX(MAX(rx*1.38,shoulder*.5),height*17.0/240.0);
        CGPoint center=CGPointMake((a.x+b.x)*.5,(a.y+b.y)*.5+ry*.32);
        CGContextFillEllipseInRect(context,CGRectMake(center.x-rx,center.y-ry,rx*2,ry*2));
    }
    // Supplemental detections are optional and expire with the same 150ms packet window.
    @synchronized(PrivacyGate()) {
        if (llabs(timestamp-s_facePrivacyTimestamp)<=150 && s_facePrivacyPoints.count>2) {
            CGPoint center=CGPointZero;
            for (NSValue *value in s_facePrivacyPoints) { CGPoint p=value.CGPointValue; center.x+=p.x; center.y+=p.y; }
            center.x/=s_facePrivacyPoints.count; center.y/=s_facePrivacyPoints.count;
            std::vector<CGPoint> face;
            for (NSValue *value in s_facePrivacyPoints) {
                CGPoint p=value.CGPointValue;
                p.x=center.x+(p.x-center.x)*1.16;
                p.y=center.y+(p.y-center.y)*(p.y<center.y?1.5:1.05);
                face.push_back(CGPointMake(p.x*width,(1-p.y)*height));
            }
            FillPrivacyHull(context,face);
        }
        if (!faceOnly && llabs(timestamp-s_handPrivacyTimestamp)<=150) {
            for (NSUInteger start=0; start<s_handPrivacyPoints.count; start+=21) {
                std::vector<CGPoint> hand;
                for (NSUInteger i=start; i<MIN(start+21,s_handPrivacyPoints.count); ++i) {
                    CGPoint p=s_handPrivacyPoints[i].CGPointValue;
                    hand.push_back(CGPointMake(p.x*width,(1-p.y)*height));
                }
                FillPrivacyHull(context,hand);
            }
        }
    }
    CGImageRef image=CGBitmapContextCreateImage(context);
    CGContextRelease(context);
    if (!image) return nil;
    CIImage *mask=[CIImage imageWithCGImage:image];
    CGImageRelease(image);
    mask=[mask imageByApplyingTransform:CGAffineTransformMakeTranslation(extent.origin.x,extent.origin.y)];
    return [[mask imageByApplyingFilter:@"CIGaussianBlur" withInputParameters:@{kCIInputRadiusKey:@1.0}] imageByCroppingToRect:extent];
}

static CIImage *WindowsStyleMosaic(CIImage *source, CGFloat scale) {
    CIFilter *pixelate = [CIFilter filterWithName:@"CIPixellate"];
    [pixelate setValue:source forKey:kCIInputImageKey];
    // Same square-block mosaic size as the Windows tracker.
    [pixelate setValue:@(MAX(2.0, scale)) forKey:kCIInputScaleKey];
    [pixelate setValue:[CIVector vectorWithX:CGRectGetMidX(source.extent)
                                           Y:CGRectGetMidY(source.extent)]
                 forKey:kCIInputCenterKey];
    return [pixelate.outputImage imageByCroppingToRect:source.extent];
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
    CIImage *mask = CurrentPosePrivacyMask(result, source.extent, timestamp);
    // Like Windows, keep the live camera visible even when no person is detected.
    UIImage *image = nil;
    CIImage *processed = source;
    if (mask != nil) {
        CIFilter *blend = [CIFilter filterWithName:@"CIBlendWithMask"];
        [blend setValue:WindowsStyleMosaic(source, s_mosaicScale) forKey:kCIInputImageKey];
        [blend setValue:source forKey:kCIInputBackgroundImageKey];
        [blend setValue:mask forKey:kCIInputMaskImageKey];
        processed = [blend.outputImage imageByCroppingToRect:source.extent];
        // Only the head/profile uses larger blocks; body, hands and background keep their current look.
        CIImage *faceMask = CurrentPosePrivacyMask(result, source.extent, timestamp, YES);
        if (faceMask != nil) {
            CIFilter *faceBlend = [CIFilter filterWithName:@"CIBlendWithMask"];
            [faceBlend setValue:WindowsStyleMosaic(source, MAX(48.0, s_mosaicScale * 3.0)) forKey:kCIInputImageKey];
            [faceBlend setValue:processed forKey:kCIInputBackgroundImageKey];
            [faceBlend setValue:faceMask forKey:kCIInputMaskImageKey];
            processed = [faceBlend.outputImage imageByCroppingToRect:source.extent];
        }
    }
    {
        CGImageRef frame = [s_ciContext createCGImage:processed fromRect:source.extent];
        if (frame != nil) {
            image = [UIImage imageWithCGImage:frame];
            CGImageRelease(frame);
            s_lastSafeBackgroundImage = image;
        }
    }
    if (image != nil) {
        @synchronized(FrameGate()) {
            if (s_pendingProcessedFrames == nil) s_pendingProcessedFrames = [NSMutableDictionary dictionary];
            s_pendingProcessedFrames[@(timestamp)] = image;
            while (s_pendingProcessedFrames.count > 8) {
                NSNumber *oldest = [[s_pendingProcessedFrames.allKeys sortedArrayUsingSelector:@selector(compare:)] firstObject];
                [s_pendingProcessedFrames removeObjectForKey:oldest];
            }
        }
        // Publish from the pose callback itself. The camera preview must not
        // wait for hand and face callbacks, which can legitimately miss an
        // independent live-stream frame.
        dispatch_async(dispatch_get_main_queue(), ^{
            if (s_backgroundLayer != nil)
                s_backgroundLayer.contents = (__bridge id)image.CGImage;
        });
    }
}
// Pose drives the body and must never wait for optional hand/face detectors.
// Supplemental results are reused only for a short interval.
static void SubmitResult(NSString *kind, NSDictionary *packet, NSInteger timestamp) {
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
            if (receiver && [receiver isEqualToString:s_unityObject] && json)
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
    s_width = (int)CVPixelBufferGetWidth(pixelBuffer);
    s_height = (int)CVPixelBufferGetHeight(pixelBuffer);
    MPPImage *image = [[MPPImage alloc] initWithPixelBuffer:pixelBuffer error:nil];
    if (image == nil) return;
    NSInteger timestamp = (NSInteger)(CACurrentMediaTime() * 1000.0);
    @synchronized(FrameGate()) {
        if (s_pendingCameraFrames == nil) s_pendingCameraFrames = [NSMutableDictionary dictionary];
        CIImage *source = [CIImage imageWithCVPixelBuffer:pixelBuffer];
        s_pendingCameraFrames[@(timestamp)] = @{@"source": source};
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
    if (s_unityObject == nil || landmarker != s_landmarker) return;
    DisplaySynchronizedBackground(result, timestamp);
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
    @synchronized(PrivacyGate()) { s_handPrivacyPoints = [privacyPoints copy]; s_handPrivacyTimestamp = timestamp; }
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
    s_lastSafeBackgroundImage = nil;
    s_latestHandPacket = nil; s_latestFacePacket = nil;
    s_latestHandTimestamp = 0; s_latestFaceTimestamp = 0;
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
