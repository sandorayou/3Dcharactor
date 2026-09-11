#import <Foundation/Foundation.h>
#import <Security/Security.h>
#include <stdlib.h>

extern "C" void NativeSet(const char *key, const char *value) {
    NSString *account = [NSString stringWithUTF8String:key];
    NSData *data = [[NSString stringWithUTF8String:value] dataUsingEncoding:NSUTF8StringEncoding];
    NSDictionary *query = @{(__bridge id)kSecClass: (__bridge id)kSecClassGenericPassword,
        (__bridge id)kSecAttrAccount: account};
    SecItemDelete((__bridge CFDictionaryRef)query);
    NSMutableDictionary *item = [query mutableCopy]; item[(__bridge id)kSecValueData] = data;
    SecItemAdd((__bridge CFDictionaryRef)item, NULL);
}

extern "C" const char *NativeGet(const char *key) {
    NSString *account = [NSString stringWithUTF8String:key];
    NSDictionary *query = @{(__bridge id)kSecClass: (__bridge id)kSecClassGenericPassword,
        (__bridge id)kSecAttrAccount: account, (__bridge id)kSecReturnData: @YES};
    CFTypeRef result = NULL;
    if (SecItemCopyMatching((__bridge CFDictionaryRef)query, &result) != errSecSuccess) return NULL;
    NSString *value = [[NSString alloc] initWithData:(__bridge NSData *)result encoding:NSUTF8StringEncoding];
    return strdup(value.UTF8String);
}

// C ABI fallback. The Swift implementation replaces these symbols when the
// RTMPHaishinKit package is linked in the generated Xcode project.
extern "C" __attribute__((weak)) int NativeStart(const char *url, const char *key, int width, int height, int fps, int videoKbps, int audioKbps)
{
    (void)url; (void)key; (void)width; (void)height; (void)fps; (void)videoKbps; (void)audioKbps;
    return -1;
}

extern "C" __attribute__((weak)) void NativeStop() { }
extern "C" __attribute__((weak)) void NativeSetCamera(int front) { (void)front; }
extern "C" __attribute__((weak)) void NativeSetMuted(int muted) { (void)muted; }
extern "C" __attribute__((weak)) int NativeStartRecording() { return -1; }
extern "C" __attribute__((weak)) void NativeStopRecording() { }
