#import "UnityInterface.h"
#import <Foundation/Foundation.h>

// Swift exposes this explicit Objective-C name, independent of the Xcode module.
@interface MyProjectLiveStreaming : NSObject
+ (void)show:(NSString *)receiver;
+ (void)stop;
+ (BOOL)isActive;
@end

extern "C" void MyProjectShowLiveStreaming(const char *receiver) {
    NSString *name = receiver ? [NSString stringWithUTF8String:receiver] : nil;
    if (name) dispatch_async(dispatch_get_main_queue(), ^{ [MyProjectLiveStreaming show:name]; });
}
extern "C" void MyProjectStopLiveStreaming() {
    dispatch_async(dispatch_get_main_queue(), ^{ [MyProjectLiveStreaming stop]; });
}
extern "C" bool MyProjectLiveStreamingBusy() { return [MyProjectLiveStreaming isActive]; }
extern "C" void MyProjectLiveStreamingNotify(const char *receiver, const char *json) {
    NSString *name = receiver ? [NSString stringWithUTF8String:receiver] : nil;
    NSString *state = json ? [NSString stringWithUTF8String:json] : nil;
    if (name && state) dispatch_async(dispatch_get_main_queue(), ^{
        UnitySendMessage(name.UTF8String, "OnLiveStreamingState", state.UTF8String);
    });
}
