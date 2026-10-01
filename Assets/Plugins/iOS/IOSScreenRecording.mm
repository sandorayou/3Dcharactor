#import <ReplayKit/ReplayKit.h>
#import "UnityInterface.h"

static NSString *s_recordingReceiver;
@interface WindowsPortRecordingPreview : NSObject <RPPreviewViewControllerDelegate>
@end
@implementation WindowsPortRecordingPreview
- (void)previewControllerDidFinish:(RPPreviewViewController *)previewController {
    [previewController dismissViewControllerAnimated:YES completion:nil];
}
@end
static WindowsPortRecordingPreview *s_previewDelegate;

extern "C" void WindowsPortStartRecording(const char *receiver) {
    s_recordingReceiver = [NSString stringWithUTF8String:receiver];
    RPScreenRecorder *recorder = [RPScreenRecorder sharedRecorder];
    recorder.microphoneEnabled = NO;
    [recorder startRecordingWithHandler:^(NSError *error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            if (s_recordingReceiver)
                UnitySendMessage(s_recordingReceiver.UTF8String, "OnIOSRecordingState", error ? error.localizedDescription.UTF8String : "started");
        });
    }];
}
extern "C" void WindowsPortStopRecording() {
    [[RPScreenRecorder sharedRecorder] stopRecordingWithHandler:^(RPPreviewViewController *preview, NSError *error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            if (s_recordingReceiver)
                UnitySendMessage(s_recordingReceiver.UTF8String, "OnIOSRecordingState", error ? error.localizedDescription.UTF8String : "stopped");
            if (preview) {
                if (!s_previewDelegate) s_previewDelegate = [WindowsPortRecordingPreview new];
                preview.previewControllerDelegate = s_previewDelegate;
                [UnityGetGLViewController() presentViewController:preview animated:YES completion:nil];
            }
        });
    }];
}
