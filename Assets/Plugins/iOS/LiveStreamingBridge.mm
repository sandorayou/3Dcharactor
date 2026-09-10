#import <Foundation/Foundation.h>

// C ABI fallback. The Swift implementation replaces these symbols when the
// RTMPHaishinKit package is linked in the generated Xcode project.
extern "C" __attribute__((weak)) int NativeStart(const char *url, const char *key, int width, int height, int fps, int videoKbps, int audioKbps)
{
    (void)url; (void)key; (void)width; (void)height; (void)fps; (void)videoKbps; (void)audioKbps;
    return -1;
}

extern "C" __attribute__((weak)) void NativeStop() { }
extern "C" __attribute__((weak)) void NativeSetCamera(int front) { (void)front; }
