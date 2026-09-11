#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
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
            combined[@"points"] = points;
            combined[@"face_blendshapes"] = parts[@"face"][@"face_blendshapes"];
            combined[@"frame"] = @(s_frame++);
            NSData *data = [NSJSONSerialization dataWithJSONObject:combined options:0 error:nil];
            NSString *json = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            NSString *receiver = [s_unityObject copy];
            dispatch_async(dispatch_get_main_queue(), ^{
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
    NSDictionary *packet = @{@"version": @4, @"frame": @(timestamp), @"timestamp_ms": @((long long)(NSDate.date.timeIntervalSince1970 * 1000)), @"source_width": @(s_width.load()), @"source_height": @(s_height.load()), @"tracking": @(jsonPoints.count > 0), @"points": jsonPoints};
    SubmitResult(@"pose", packet, timestamp);
}
@end

@implementation NativeHandResultDelegate
- (void)handLandmarker:(MPPHandLandmarker *)landmarker didFinishDetectionWithResult:(MPPHandLandmarkerResult *)result timestampInMilliseconds:(NSInteger)timestamp error:(NSError *)error {
    if (!result || !s_unityObject) return;
    NSArray *names = @[@"wrist", @"thumb_cmc", @"thumb_mcp", @"thumb_ip", @"thumb", @"index_mcp", @"index_pip", @"index_dip", @"index", @"middle_mcp", @"middle_pip", @"middle_dip", @"middle", @"ring_mcp", @"ring_pip", @"ring_dip", @"ring", @"pinky_mcp", @"pinky_pip", @"pinky_dip", @"pinky"];
    NSMutableArray *points = [NSMutableArray array];
    for (NSUInteger h = 0; h < result.landmarks.count; h++) {
        NSArray *image = result.landmarks[h]; NSArray *world = h < result.worldLandmarks.count ? result.worldLandmarks[h] : @[];
        NSString *side = @"right";
        if (h < result.handedness.count && [[result.handedness[h] firstObject].categoryName.lowercaseString containsString:@"left"]) side = @"left";
        for (NSUInteger i = 0; i < image.count && i < world.count && i < names.count; i++) {
            MPPNormalizedLandmark *p = image[i]; MPPLandmark *w = world[i];
            [points addObject:@{@"name": [NSString stringWithFormat:@"%@_hand_%@", side, names[i]], @"x": @(w.x), @"y": @(w.y), @"z": @(w.z), @"confidence": p.visibility ?: @1.0, @"image_x": @(p.x), @"image_y": @(p.y), @"image_z": @(p.z)}];
        }
    }
    NSDictionary *packet = @{@"version": @4, @"frame": @(timestamp), @"timestamp_ms": @(timestamp), @"source_width": @(s_width.load()), @"source_height": @(s_height.load()), @"tracking": @(points.count > 0), @"points": points};
    SubmitResult(@"hand", packet, timestamp);
}
@end

@implementation NativeFaceResultDelegate
- (void)faceLandmarker:(MPPFaceLandmarker *)landmarker didFinishDetectionWithResult:(MPPFaceLandmarkerResult *)result timestampInMilliseconds:(NSInteger)timestamp error:(NSError *)error {
    if (!result || !s_unityObject) return;
    NSMutableArray *blend = [NSMutableArray array];
    if (result.faceBlendshapes.count > 0) for (MPPCategory *c in result.faceBlendshapes.firstObject.categories)
        [blend addObject:@{@"name": c.categoryName ?: @"", @"score": @(c.score)}];
    NSDictionary *packet = @{@"version": @4, @"frame": @(timestamp), @"timestamp_ms": @(timestamp), @"source_width": @(s_width.load()), @"source_height": @(s_height.load()), @"tracking": @(result.faceLandmarks.count > 0), @"face_blendshapes": blend, @"points": @[]};
    SubmitResult(@"face", packet, timestamp);
}
@end

static NativePoseCaptureDelegate *s_delegate;
static NativePoseResultDelegate *s_resultDelegate;
static NativeHandResultDelegate *s_handDelegate;
static NativeFaceResultDelegate *s_faceDelegate;
static AVCaptureVideoPreviewLayer *s_previewLayer;
static BOOL s_paused;
static BOOL s_stopping;

static void UpdateVideoOrientation() {
    s_previewLayer.frame = UnityGetGLViewController().view.bounds;
    AVCaptureVideoOrientation orientation = AVCaptureVideoOrientationPortrait;
    UIInterfaceOrientation ui = UIApplication.sharedApplication.statusBarOrientation;
    if (ui == UIInterfaceOrientationLandscapeLeft) orientation = AVCaptureVideoOrientationLandscapeLeft;
    else if (ui == UIInterfaceOrientationLandscapeRight) orientation = AVCaptureVideoOrientationLandscapeRight;
    AVCaptureConnection *video = [s_output connectionWithMediaType:AVMediaTypeVideo];
    if (video.isVideoOrientationSupported) video.videoOrientation = orientation;
    AVCaptureConnection *preview = s_previewLayer.connection;
    if (preview.isVideoOrientationSupported) preview.videoOrientation = orientation;
}

static void NotifyCameraState(NSString *message) {
    if (s_unityObject != nil) UnitySendMessage(s_unityObject.UTF8String, "OnNativeCameraState", message.UTF8String);
}

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
    s_resultDelegate = [NativePoseResultDelegate new];
    options.poseLandmarkerLiveStreamDelegate = s_resultDelegate;
    s_landmarker = [[MPPPoseLandmarker alloc] initWithOptions:options error:nil];
    if (s_landmarker == nil) return -4;
    NSString *handPath = [[NSBundle mainBundle] pathForResource:@"hand_landmarker" ofType:@"task" inDirectory:@"Data/Raw"];
    NSString *facePath = [[NSBundle mainBundle] pathForResource:@"face_landmarker" ofType:@"task" inDirectory:@"Data/Raw"];
    if (!handPath || !facePath) return -7;
    MPPHandLandmarkerOptions *handOptions = [MPPHandLandmarkerOptions new];
    handOptions.baseOptions.modelAssetPath = handPath; handOptions.runningMode = MPPRunningModeLiveStream; handOptions.numHands = 2;
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

    AVCaptureDevice *device = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
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
    s_previewLayer = [AVCaptureVideoPreviewLayer layerWithSession:s_session];
    s_previewLayer.videoGravity = AVLayerVideoGravityResizeAspectFill;
    dispatch_async(dispatch_get_main_queue(), ^{
        UIView *unityView = UnityGetGLViewController().view;
        unityView.opaque = NO;
        unityView.backgroundColor = UIColor.clearColor;
        s_previewLayer.frame = unityView.bounds;
        [unityView.layer insertSublayer:s_previewLayer atIndex:0];
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

extern "C" void NativePoseCaptureStop() {
    s_stopping = YES;
    [s_session stopRunning];
    [s_output setSampleBufferDelegate:nil queue:NULL];
    [s_previewLayer removeFromSuperlayer];
    s_previewLayer = nil;
    s_output = nil;
    s_delegate = nil;
    s_landmarker = nil;
    s_handLandmarker = nil;
    s_faceLandmarker = nil;
    s_resultDelegate = nil;
    s_handDelegate = nil;
    s_faceDelegate = nil;
    s_unityObject = nil;
    s_queue = nil;
    s_session = nil;
    s_stopping = NO;
}
