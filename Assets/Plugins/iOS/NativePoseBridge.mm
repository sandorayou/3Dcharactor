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

static bool PrivacyEligiblePixel(float r, float g, float b) {
    float maximum = fmaxf(r, fmaxf(g, b)), minimum = fminf(r, fminf(g, b));
    float saturation = maximum <= 0 ? 0 : (maximum - minimum) / maximum * 255.0f;
    return !(maximum >= 180.0f && saturation <= 42.0f);
}

static NSData *PrivacyMask(CVPixelBufferRef pixelBuffer, NSData **eligibleResult) {
    const size_t width = CVPixelBufferGetWidth(pixelBuffer);
    const size_t height = CVPixelBufferGetHeight(pixelBuffer);
    NSMutableData *data = [NSMutableData dataWithLength:width * height];
    NSMutableData *eligibleData = [NSMutableData dataWithLength:width * height];
    uint8_t *mask = (uint8_t *)data.mutableBytes;
    uint8_t *eligible = (uint8_t *)eligibleData.mutableBytes;
    CVPixelBufferLockBaseAddress(pixelBuffer, kCVPixelBufferLock_ReadOnly);
    const uint8_t *pixels = (const uint8_t *)CVPixelBufferGetBaseAddress(pixelBuffer);
    const size_t stride = CVPixelBufferGetBytesPerRow(pixelBuffer);
    // Classify every source pixel: a resized or dilated skin mask can spill onto
    // adjacent white pixels. Never merge cached landmarks into this frame.
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            const uint8_t *p = pixels + y * stride + x * 4;
            mask[y * width + x] = PrivacySkinPixel(p[2], p[1], p[0]) ? 255 : 0;
            eligible[y * width + x] = PrivacyEligiblePixel(p[2], p[1], p[0]) ? 255 : 0;
        }
    }
    CVPixelBufferUnlockBaseAddress(pixelBuffer, kCVPixelBufferLock_ReadOnly);
    if (eligibleResult != nil) *eligibleResult = eligibleData;
    return data;
}

static void DilatePrivacySeeds(const uint8_t *skin, size_t width, size_t height,
                               size_t radius, uint8_t *horizontal, uint8_t *output) {
    for (size_t y = 0; y < height; ++y) {
        const size_t row = y * width;
        size_t right = MIN(radius, width - 1), active = 0;
        for (size_t x = 0; x <= right; ++x) active += skin[row + x] != 0;
        for (size_t x = 0; x < width; ++x) {
            horizontal[row + x] = active ? 255 : 0;
            if (x >= radius) active -= skin[row + x - radius] != 0;
            if (x + radius + 1 < width) active += skin[row + x + radius + 1] != 0;
        }
    }
    for (size_t x = 0; x < width; ++x) {
        size_t bottom = MIN(radius, height - 1), active = 0;
        for (size_t y = 0; y <= bottom; ++y) active += horizontal[y * width + x] != 0;
        for (size_t y = 0; y < height; ++y) {
            output[y * width + x] = active ? 255 : 0;
            if (y >= radius) active -= horizontal[(y - radius) * width + x] != 0;
            if (y + radius + 1 < height) active += horizontal[(y + radius + 1) * width + x] != 0;
        }
    }
}

static BOOL ReliablePrivacyPoint(MPPNormalizedLandmark *point) {
    return isfinite(point.x) && isfinite(point.y) && point.x >= 0 && point.x <= 1 &&
           point.y >= 0 && point.y <= 1 && point.visibility.floatValue >= .15f;
}

static CIImage *PrivacyBoneMask(MPPPoseLandmarkerResult *result, CGRect extent,
                                NSData *skin, NSData *eligible) {
    NSArray<MPPNormalizedLandmark *> *points = result.landmarks.firstObject;
    const size_t width = (size_t)extent.size.width, height = (size_t)extent.size.height;
    if (points.count < 33 || skin.length != width * height || eligible.length != width * height) return nil;
    NSMutableData *data = [NSMutableData dataWithLength:width * height];
    CGColorSpaceRef gray = CGColorSpaceCreateDeviceGray();
    CGContextRef context = CGBitmapContextCreate(data.mutableBytes, width, height, 8, width, gray, kCGImageAlphaNone);
    CGColorSpaceRelease(gray);
    if (context == nil) return nil;
    CGContextSetGrayFillColor(context, 1, 1);
    CGContextSetGrayStrokeColor(context, 1, 1);
    CGContextSetLineCap(context, kCGLineCapRound);
    const CGFloat radius = MAX(width, height) * .05f;
    CGContextSetLineWidth(context, radius * 2);
    const NSUInteger edges[][2] = {
        {0,1},{1,2},{2,3},{3,7},{0,4},{4,5},{5,6},{6,8},{9,10},
        {11,12},{11,13},{13,15},{15,17},{15,19},{15,21},{17,19},
        {12,14},{14,16},{16,18},{16,20},{16,22},{18,20},
        {11,23},{12,24},{23,24},{23,25},{25,27},{27,29},{29,31},{27,31},
        {24,26},{26,28},{28,30},{30,32},{28,32}
    };
    for (const auto &edge : edges) {
        if (!ReliablePrivacyPoint(points[edge[0]]) || !ReliablePrivacyPoint(points[edge[1]])) continue;
        MPPNormalizedLandmark *a = points[edge[0]], *b = points[edge[1]];
        CGContextMoveToPoint(context, a.x * width, (1-a.y) * height);
        CGContextAddLineToPoint(context, b.x * width, (1-b.y) * height);
        CGContextStrokePath(context);
    }
    CGFloat faceMinX = width, faceMaxX = 0, faceMinY = height, faceMaxY = 0;
    NSUInteger facePointCount = 0;
    for (NSUInteger index = 0; index <= 10; ++index) {
        if (!ReliablePrivacyPoint(points[index])) continue;
        MPPNormalizedLandmark *point = points[index];
        CGFloat x = point.x * width, y = (1 - point.y) * height;
        faceMinX = MIN(faceMinX, x); faceMaxX = MAX(faceMaxX, x);
        faceMinY = MIN(faceMinY, y); faceMaxY = MAX(faceMaxY, y);
        ++facePointCount;
    }
    const NSUInteger trackedBodyIndices[] = {
        0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,
        17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32
    };
    for (NSUInteger index : trackedBodyIndices) {
        if (!ReliablePrivacyPoint(points[index])) continue;
        MPPNormalizedLandmark *point = points[index];
        CGFloat jointRadius = radius * (index <= 10 ? 1.2f : 1.35f);
        CGContextFillEllipseInRect(context, CGRectMake(point.x * width - jointRadius,
            (1 - point.y) * height - jointRadius, jointRadius * 2, jointRadius * 2));
    }
    CGContextFlush(context);

    NSMutableData *faceData = [NSMutableData dataWithLength:width * height];
    if (facePointCount >= 3) {
        CGColorSpaceRef faceGray = CGColorSpaceCreateDeviceGray();
        CGContextRef faceContext = CGBitmapContextCreate(faceData.mutableBytes, width, height, 8, width, faceGray, kCGImageAlphaNone);
        CGColorSpaceRelease(faceGray);
        if (faceContext != nil) {
            const CGFloat padX = MAX(MAX(width, height) * .018f, (faceMaxX - faceMinX) * .12f) + 24.0f;
            const CGFloat padTop = MAX(MAX(width, height) * .018f, (faceMaxY - faceMinY) * .25f) + 24.0f;
            const CGFloat padBottom = MAX(MAX(width, height) * .025f, (faceMaxY - faceMinY) * .45f) + 24.0f;
            CGContextSetGrayFillColor(faceContext, 1, 1);
            CGContextFillEllipseInRect(faceContext, CGRectMake(faceMinX - padX, faceMinY - padTop,
                faceMaxX - faceMinX + padX * 2, faceMaxY - faceMinY + padTop + padBottom));
            CGContextRelease(faceContext);
        }
    }

    const NSUInteger dilationRadius = MAX((size_t)4, (size_t)(MAX(width, height) * .04f));
    NSMutableData *horizontal = [NSMutableData dataWithLength:width * height];
    NSMutableData *nearSkin = [NSMutableData dataWithLength:width * height];
    DilatePrivacySeeds((const uint8_t *)skin.bytes, width, height, dilationRadius,
                      (uint8_t *)horizontal.mutableBytes, (uint8_t *)nearSkin.mutableBytes);
    const uint8_t *boneBytes = (const uint8_t *)data.bytes;
    const uint8_t *nearSkinBytes = (const uint8_t *)nearSkin.bytes;
    const uint8_t *eligibleBytes = (const uint8_t *)eligible.bytes;
    const uint8_t *faceBytes = (const uint8_t *)faceData.bytes;
    uint8_t *outputBytes = (uint8_t *)faceData.mutableBytes;
    for (size_t i = 0; i < width * height; ++i)
        outputBytes[i] = (faceBytes[i] || (boneBytes[i] && nearSkinBytes[i] && eligibleBytes[i])) ? 255 : 0;
    CGContextRelease(context);
    CGColorSpaceRef maskGray = CGColorSpaceCreateDeviceGray();
    CGContextRef maskContext = CGBitmapContextCreate(faceData.mutableBytes, width, height, 8, width, maskGray, kCGImageAlphaNone);
    CGColorSpaceRelease(maskGray);
    if (maskContext == nil) return nil;
    CGImageRef image = CGBitmapContextCreateImage(maskContext);
    CGContextRelease(maskContext);
    if (image == nil) return nil;
    CIImage *mask = [CIImage imageWithCGImage:image];
    CGImageRelease(image);
    return [mask imageByApplyingTransform:CGAffineTransformMakeTranslation(extent.origin.x, extent.origin.y)];
}

static void DisplayCameraBackground(CVPixelBufferRef pixelBuffer) {
    if (s_backgroundLayer == nil) return;
    if (s_ciContext == nil) s_ciContext = [CIContext contextWithOptions:@{kCIContextUseSoftwareRenderer: @NO}];
    CIImage *source = [CIImage imageWithCVPixelBuffer:pixelBuffer];
    NSData *eligible = nil;
    NSData *skin = PrivacyMask(pixelBuffer, &eligible);
    CIImage *mask = PrivacyBoneMask(s_lastPoseResult, source.extent, skin, eligible);
    // Never publish an uncensored frame while pose landmarks are unavailable.
    if (mask == nil) return;
    CIFilter *pixelate = [CIFilter filterWithName:@"CIPixellate"];
    [pixelate setValue:source forKey:kCIInputImageKey];
    [pixelate setValue:@48.0 forKey:kCIInputScaleKey];
    [pixelate setValue:[CIVector vectorWithX:CGRectGetMidX(source.extent) Y:CGRectGetMidY(source.extent)] forKey:kCIInputCenterKey];
    CIImage *mosaic = [pixelate.outputImage imageByCroppingToRect:source.extent];
    CIFilter *blend = [CIFilter filterWithName:@"CIBlendWithMask"];
    [blend setValue:mosaic forKey:kCIInputImageKey];
    [blend setValue:source forKey:kCIInputBackgroundImageKey];
    [blend setValue:mask forKey:kCIInputMaskImageKey];
    CIImage *processed = [blend.outputImage imageByCroppingToRect:source.extent];
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
// Link-only compatibility shims for the unused streaming/recording scripts.
// This app does not persist stream keys or switch away from the front camera.
extern "C" void NativeSet(const char *key, const char *value) {
    (void)key;
    (void)value;
}
extern "C" const char *NativeGet(const char *key) {
    (void)key;
    return nullptr;
}
extern "C" void NativePoseCaptureSetFrontCamera(int front) {
    (void)front;
}
extern "C" int NativeStart(const char *url, const char *key, int width, int height,
                              int fps, int videoKbps, int audioKbps) {
    (void)url; (void)key; (void)width; (void)height;
    (void)fps; (void)videoKbps; (void)audioKbps;
    return -1;
}
extern "C" void NativeStop(void) { }
extern "C" void NativeSetCamera(int front) { (void)front; }
extern "C" void NativeSetMuted(int muted) { (void)muted; }
extern "C" int NativeStartRecording(void) { return -1; }
extern "C" void NativeStopRecording(void) { }

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
