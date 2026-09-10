#import <Foundation/Foundation.h>

// Integration seam for the iOS encoder/RTMPS implementation.
// This intentionally fails closed until a vetted RTMP/RTMPS encoder is linked.
extern "C" int NativeStart(const char *url, const char *key, int fps, int videoKbps, int audioKbps)
{
    (void)url; (void)key; (void)fps; (void)videoKbps; (void)audioKbps;
    return -1;
}

extern "C" void NativeStop() { }
extern "C" void NativeSetCamera(int front) { (void)front; }
