#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <CoreImage/CoreImage.h>
#import "UnityInterface.h"
#import <MediaPipeTasksVision/MediaPipeTasksVision.h>
#include <cmath>

#include <atomic>
static std::atomic<int> s_width{640}, s_height{480};
static AVCaptureSession *s_session;
static AVCaptureVideoDataOutput *s_output;
static dispatch_queue_t s_queue;
static MPPPoseLandmarker *s_landmarker;
static MPPPoseLandmarkerResult *s_lastPoseResult;
static NSString *s_unityObject;
static long long s_frame;
static CALayer *s_backgroundLayer;
static CIContext *s_ciContext;
static UIInterfaceOrientation s_lastVideoOrientation = UIInterfaceOrientationUnknown;
static void UpdateVideoOrientation(void);
// BEGIN PORTABLE PRIVACY CORE (also compiled by the regression test).
static bool PrivacySkinPixel(float r, float g, float b) {
    float maximum = fmaxf(r, fmaxf(g, b)), minimum = fminf(r, fminf(g, b));
    float delta = maximum - minimum;
    float saturation = maximum <= 0 ? 0 : delta / maximum * 255.0f;
    float hue = 0;
    if (delta > .001f) {
        if (maximum == r) hue = 60.0f * ((g - b) / delta);
        else if (maximum == g) hue = 60.0f * ((b - r) / delta + 2.0f);
        else hue = 60.0f * ((r - g) / delta + 4.0f);
        if (hue < 0) hue += 360.0f;
    }
    return hue >= 4.0f && hue <= 45.0f &&
           saturation >= 55.0f && saturation <= 180.0f &&
           maximum >= 105.0f && r > g;
}
// END PORTABLE PRIVACY CORE

static NSData *PrivacyMask(CVPixelBufferRef pixelBuffer) {
    const size_t width = CVPixelBufferGetWidth(pixelBuffer);
    const size_t height = CVPixelBufferGetHeight(pixelBuffer);
    NSMutableData *data = [NSMutableData dataWithLength:width * height];
    uint8_t *mask = (uint8_t *)data.mutableBytes;
    CVPixelBufferLockBaseAddress(pixelBuffer, kCVPixelBufferLock_ReadOnly);
    const uint8_t *pixels = (const uint8_t *)CVPixelBufferGetBaseAddress(pixelBuffer);
    const size_t stride = CVPixelBufferGetBytesPerRow(pixelBuffer);
    // Classify every source pixel: a resized or dilated skin mask can spill onto
    // adjacent white pixels. Never merge cached landmarks into this frame.
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            const uint8_t *p = pixels + y * stride + x * 4;
            mask[y * width + x] = PrivacySkinPixel(p[2], p[1], p[0]) ? 255 : 0;
        }
    }
    CVPixelBufferUnlockBaseAddress(pixelBuffer, kCVPixelBufferLock_ReadOnly);
    return data;
}

static BOOL ReliablePrivacyPoint(MPPNormalizedLandmark *point) {
    return isfinite(point.x) && isfinite(point.y) && point.x >= 0 && point.x <= 1 &&
           point.y >= 0 && point.y <= 1 && point.visibility.floatValue >= .15f;
}

static CIImage *PrivacyBoneMask(MPPPoseLandmarkerResult *result, CGRect extent, NSData *skin) {
    NSArray<MPPNormalizedLandmark *> *points = result.landmarks.firstObject;
    const size_t width = (size_t)extent.size.width, height = (size_t)extent.size.height;
    if (points.count < 17 || skin.length != width * height) return nil;
    NSMutableData *data = [NSMutableData dataWithLength:width * height];
    CGColorSpaceRef gray = CGColorSpaceCreateDeviceGray();
    CGContextRef context = CGBitmapContextCreate(data.mutableBytes, width, height, 8, width, gray, kCGImageAlphaNone);
    CGColorSpaceRelease(gray);
    if (context == nil) return nil;
    CGContextSetGrayFillColor(context, 1, 1);
    CGContextSetGrayStrokeColor(context, 1, 1);
    CGContextSetLineCap(context, kCGLineCapRound);
    const CGFloat radius = MAX(width, height) * .045f;
    CGContextSetLineWidth(context, radius * 2);
    const NSUInteger edges[][2] = {{0,11},{0,12},{11,13},{13,15},{12,14},{14,16},{11,12},{11,23},{12,24},{23,24}};
    for (const auto &edge : edges) {
        if (!ReliablePrivacyPoint(points[edge[0]]) || !ReliablePrivacyPoint(points[edge[1]])) continue;
        MPPNormalizedLandmark *a = points[edge[0]], *b = points[edge[1]];
        CGContextMoveToPoint(context, a.x * width, (1-a.y) * height);
        CGContextAddLineToPoint(context, b.x * width, (1-b.y) * height);
        CGContextStrokePath(context);
    }
    const NSUInteger pointsToFill[] = {0, 11, 12, 13, 14, 15, 16, 23, 24};
    for (NSUInteger index : pointsToFill) {
        if (!ReliablePrivacyPoint(points[index])) continue;
        MPPNormalizedLandmark *point = points[index];
        CGContextFillEllipseInRect(context, CGRectMake(point.x * width - radius, (1-point.y) * height - radius, radius * 2, radius * 2));
    }
    CGContextFlush(context);
    const uint8_t *skinBytes = (const uint8_t *)skin.bytes;
    uint8_t *boneBytes = (uint8_t *)data.mutableBytes;
    for (size_t i = 0; i < width * height; ++i) boneBytes[i] = (skinBytes[i] && boneBytes[i]) ? 255 : 0;
    CGImageRef image = CGBitmapContextCreateImage(context);
    CGContextRelease(context);
    if (image == nil) return nil;
    CIImage *mask = [CIImage imageWithCGImage:image];
    CGImageRelease(image);
    return [mask imageByApplyingTransform:CGAffineTransformMakeTranslation(extent.origin.x, extent.origin.y)];
}

static void DisplayCameraBackground(CVPixelBufferRef pixelBuffer) {
    if (s_backgroundLayer == nil) return;
    if (s_ciContext == nil) s_ciContext = [CIContext contextWithOptions:@{kCIContextUseSoftwareRenderer: @NO}];
    CIImage *source = [CIImage imageWithCVPixelBuffer:pixelBuffer];
    CIImage *mask = PrivacyBoneMask(s_lastPoseResult, source.extent, PrivacyMask(pixelBuffer));
    CIImage *processed = source;
    if (mask != nil) {
        CIFilter *pixelate = [CIFilter filterWithName:@"CIPixellate"];
        [pixelate setValue:source forKey:kCIInputImageKey];
        [pixelate setValue:@36.0 forKey:kCIInputScaleKey];
        [pixelate setValue:[CIVector vectorWithX:CGRectGetMidX(source.extent) Y:CGRectGetMidY(source.extent)] forKey:kCIInputCenterKey];
        CIFilter *blend = [CIFilter filterWithName:@"CIBlendWithMask"];
        [blend setValue:pixelate.outputImage forKey:kCIInputImageKey];
        [blend setValue:source forKey:kCIInputBackgroundImageKey];
        [blend setValue:mask forKey:kCIInputMaskImageKey];
        processed = blend.outputImage;
    }
    CGImageRef frame = [s_ciContext createCGImage:processed fromRect:source.extent];
    if (frame == nil) return;
    UIImage *image = [UIImage imageWithCGImage:frame];
    CGImageRelease(frame);
    dispatch_async(dispatch_get_main_queue(), ^{
        if (s_backgroundLayer != nil) s_backgroundLayer.contents = (__bridge id)image.CGImage;
    });
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
    DisplayCameraBackground(pixelBuffer);
    s_width = (int)CVPixelBufferGetWidth(pixelBuffer);
    s_height = (int)CVPixelBufferGetHeight(pixelBuffer);
    MPPImage *image = [[MPPImage alloc] initWithPixelBuffer:pixelBuffer error:nil];
    if (image == nil) return;
    NSInteger timestamp = (NSInteger)(CACurrentMediaTime() * 1000.0);
    [s_landmarker detectAsyncImage:image timestampInMilliseconds:timestamp error:nil];
}
@end

@interface NativePoseResultDelegate : NSObject <MPPPoseLandmarkerLiveStreamDelegate>
@end
@implementation NativePoseResultDelegate
- (void)poseLandmarker:(MPPPoseLandmarker *)landmarker didFinishDetectionWithResult:(MPPPoseLandmarkerResult *)result timestampInMilliseconds:(NSInteger)timestamp error:(NSError *)error {
    if (s_unityObject == nil) return;
    s_lastPoseResult = result;
    if (result == nil) return;
    NSArray *points = result.landmarks.firstObject;
    NSArray<MPPLandmark *> *world = result.worldLandmarks.firstObject;
    NSArray *names = @[@"nose", @"left_eye_inner", @"left_eye", @"left_eye_outer", @"right_eye_inner", @"right_eye", @"right_eye_outer", @"left_ear", @"right_ear", @"mouth_left", @"mouth_right", @"left_shoulder", @"right_shoulder", @"left_elbow", @"right_elbow", @"left_wrist", @"right_wrist", @"left_pinky", @"right_pinky", @"left_index", @"right_index", @"left_thumb", @"right_thumb", @"left_hip", @"right_hip", @"left_knee", @"right_knee", @"left_ankle", @"right_ankle", @"left_heel", @"right_heel", @"left_foot_index", @"right_foot_index"];
    NSMutableArray *jsonPoints = [NSMutableArray array];
    for (NSUInteger i = 0; i < points.count && i < world.count && i < names.count; ++i) {
        MPPNormalizedLandmark *p = points[i];
        MPPLandmark *w = world[i];
        // Match the Windows protocol: raw MediaPipe world axes, image coordinates
        // separately, and visibility as confidence. Unity performs axis conversion.
        [jsonPoints addObject:@{@"name": names[i], @"x": @(w.x), @"y": @(w.y), @"z": @(w.z), @"confidence": p.visibility ?: @0.0, @"image_x": @(p.x), @"image_y": @(p.y), @"image_z": @(p.z)}];
    }
    NSDictionary *packet = @{@"version": @2, @"frame": @(s_frame++), @"timestamp_ms": @((long long)(NSDate.date.timeIntervalSince1970 * 1000)), @"source_width": @(s_width.load()), @"source_height": @(s_height.load()), @"tracking": @(jsonPoints.count > 0), @"points": jsonPoints};
    NSData *data = [NSJSONSerialization dataWithJSONObject:packet options:0 error:nil];
    NSString *json = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    NSString *receiver = [s_unityObject copy];
    dispatch_async(dispatch_get_main_queue(), ^{
        if (receiver && [receiver isEqualToString:s_unityObject] && json)
            UnitySendMessage(receiver.UTF8String, "OnNativePoseJson", json.UTF8String);
    });
}
@end
static NativePoseCaptureDelegate *s_delegate;
static NativePoseResultDelegate *s_resultDelegate;
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
        video.videoMirrored = YES;
    }
    // Keep the real camera image and avatar pose in the same mirrored preview.
}

static AVCaptureDevice *CameraDevice(void) {
    AVCaptureDeviceDiscoverySession *discovery = [AVCaptureDeviceDiscoverySession
        discoverySessionWithDeviceTypes:@[AVCaptureDeviceTypeBuiltInWideAngleCamera]
        mediaType:AVMediaTypeVideo position:AVCaptureDevicePositionFront];
    return discovery.devices.firstObject;
}

extern "C" void NativePoseCaptureStop();
extern "C" void NativePoseCaptureSetPaused(int paused);

extern "C" int NativePoseCaptureStart(const char *unityObjectName) {
    if (s_session != nil || s_stopping) return 1;
    s_unityObject = [NSString stringWithUTF8String:unityObjectName ?: ""];
    if ([AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo] == AVAuthorizationStatusNotDetermined) {
        [AVCaptureDevice requestAccessForMediaType:AVMediaTypeVideo completionHandler:^(BOOL granted) {
            dispatch_async(dispatch_get_main_queue(), ^{
                if (granted) UnitySendMessage(s_unityObject.UTF8String, "OnNativeCameraPermissionGranted", "");
            });
        }];
        return -6;
    } else if ([AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo] != AVAuthorizationStatusAuthorized) {
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
    s_session = [AVCaptureSession new];
    [s_session beginConfiguration];
    if ([s_session canSetSessionPreset:AVCaptureSessionPreset640x480])
        s_session.sessionPreset = AVCaptureSessionPreset640x480;

    AVCaptureDevice *device = CameraDevice();
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
    return 0;
}

extern "C" void NativePoseCaptureSetPaused(int paused) {
    if (paused) [s_session stopRunning];
    else if (s_session != nil) [s_session startRunning];
}

extern "C" void NativePoseCaptureStop() {
    s_stopping = YES;
    [s_session stopRunning];
    [s_output setSampleBufferDelegate:nil queue:NULL];
    [s_backgroundLayer removeFromSuperlayer];
    s_backgroundLayer = nil;
    s_ciContext = nil;
    s_output = nil;
    s_delegate = nil;
    s_landmarker = nil;
    s_lastPoseResult = nil;
    s_resultDelegate = nil;
    s_unityObject = nil;
    s_queue = nil;
    s_session = nil;
    s_stopping = NO;
}
