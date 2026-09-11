#import <AVFoundation/AVFoundation.h>
#import <QuartzCore/QuartzCore.h>
#import <UnityInterface.h>
@import MediaPipeTasksVision;

// Phase 1 of the native tracking bridge.
// MediaPipe inference is intentionally not included yet; this owns the camera
// and provides the CVPixelBuffer hand-off point for the next phase.
static AVCaptureSession *s_session;
static AVCaptureVideoDataOutput *s_output;
static dispatch_queue_t s_queue;
static MPPPoseLandmarker *s_landmarker;
static NSString *s_unityObject;
static long long s_frame;

@interface NativePoseCaptureDelegate : NSObject <AVCaptureVideoDataOutputSampleBufferDelegate>
@end

@implementation NativePoseCaptureDelegate
- (void)captureOutput:(AVCaptureOutput *)output
 didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer
        fromConnection:(AVCaptureConnection *)connection {
    CVPixelBufferRef pixelBuffer = CMSampleBufferGetImageBuffer(sampleBuffer);
    if (pixelBuffer == nil) return;

    if (s_landmarker == nil || s_unityObject == nil) return;
    MPPImage *image = [[MPPImage alloc] initWithPixelBuffer:pixelBuffer error:nil];
    if (image == nil) return;
    [s_landmarker detectAsyncImage:image timestampInMilliseconds:(NSInteger)(CACurrentMediaTime() * 1000.0) error:nil];
}
@end

@interface NativePoseResultDelegate : NSObject <MPPPoseLandmarkerLiveStreamDelegate>
@end
@implementation NativePoseResultDelegate
- (void)poseLandmarker:(MPPPoseLandmarker *)landmarker didFinishDetectionWithResult:(MPPPoseLandmarkerResult *)result timestampInMilliseconds:(NSInteger)timestamp error:(NSError *)error {
    if (result == nil || result.landmarks.count == 0 || s_unityObject == nil) return;
    NSArray *points = result.landmarks.firstObject;
    NSArray *names = @[@"nose", @"left_eye_inner", @"left_eye", @"left_eye_outer", @"right_eye_inner", @"right_eye", @"right_eye_outer", @"left_ear", @"right_ear", @"mouth_left", @"mouth_right", @"left_shoulder", @"right_shoulder", @"left_elbow", @"right_elbow", @"left_wrist", @"right_wrist", @"left_pinky", @"right_pinky", @"left_index", @"right_index", @"left_thumb", @"right_thumb", @"left_hip", @"right_hip", @"left_knee", @"right_knee", @"left_ankle", @"right_ankle", @"left_heel", @"right_heel", @"left_foot_index", @"right_foot_index"];
    NSMutableArray *jsonPoints = [NSMutableArray array];
    for (NSUInteger i = 0; i < points.count && i < names.count; ++i) {
        MPPLandmark *p = points[i];
        [jsonPoints addObject:@{@"name": names[i], @"x": @(p.x), @"y": @(p.y), @"z": @(p.z), @"confidence": @1.0, @"image_x": @(p.x), @"image_y": @(p.y), @"image_z": @(p.z)}];
    }
    NSDictionary *packet = @{@"version": @4, @"frame": @(s_frame++), @"timestamp_ms": @(timestamp), @"source_width": @640, @"source_height": @480, @"tracking": @(jsonPoints.count >= 4), @"points": jsonPoints};
    NSData *data = [NSJSONSerialization dataWithJSONObject:packet options:0 error:nil];
    NSString *json = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    UnitySendMessage(s_unityObject.UTF8String, "OnNativePoseJson", json.UTF8String);
}
@end

static NativePoseCaptureDelegate *s_delegate;
static NativePoseResultDelegate *s_resultDelegate;

extern "C" int NativePoseCaptureStart(const char *unityObjectName) {
    if (s_session != nil) return 1;
    s_unityObject = [NSString stringWithUTF8String:unityObjectName ?: ""];
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
    [s_session startRunning];
    return 0;
}

extern "C" void NativePoseCaptureStop() {
    [s_session stopRunning];
    [s_output setSampleBufferDelegate:nil queue:NULL];
    s_output = nil;
    s_delegate = nil;
    s_landmarker = nil;
    s_resultDelegate = nil;
    s_unityObject = nil;
    s_queue = nil;
    s_session = nil;
}
