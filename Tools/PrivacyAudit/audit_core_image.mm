#import <Foundation/Foundation.h>
#import <CoreImage/CoreImage.h>
#import <CoreVideo/CoreVideo.h>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
static CVPixelBufferRef Buffer(int w,int h) {
    CVPixelBufferRef p=nullptr;
    CVPixelBufferCreate(kCFAllocatorDefault,w,h,kCVPixelFormatType_32BGRA,nullptr,&p);return p;
}
int main(int argc,char **argv) { @autoreleasepool {
    if(argc!=2)return 2;
    NSData *data=[NSData dataWithContentsOfFile:[NSString stringWithUTF8String:argv[1]]];
    int w=160,h=120;if(data.length!=size_t(w)*h*4)return 3;
    CVPixelBufferRef source=Buffer(w,h),destination=Buffer(w,h);if(!source||!destination)return 4;
    CVPixelBufferLockBaseAddress(source,0);
    for(int y=0;y<h;++y) memcpy((uint8_t *)CVPixelBufferGetBaseAddress(source)+y*CVPixelBufferGetBytesPerRow(source),(const uint8_t *)data.bytes+y*w*4,w*4);
    CVPixelBufferUnlockBaseAddress(source,0);
    CGColorSpaceRef srgb=CGColorSpaceCreateWithName(kCGColorSpaceSRGB);
    CIContext *context=[CIContext contextWithOptions:@{kCIContextUseSoftwareRenderer:@YES}];
    CIImage *image=[CIImage imageWithCVPixelBuffer:source options:@{kCIImageColorSpace:(__bridge id)srgb}];
    [context render:image toCVPixelBuffer:destination bounds:CGRectMake(0,0,w,h) colorSpace:srgb];
    CVPixelBufferLockBaseAddress(destination,kCVPixelBufferLock_ReadOnly);
    int maximum=0;
    for(int y=0;y<h;++y)for(int x=0;x<w*4;++x) {
        int actual=((uint8_t *)CVPixelBufferGetBaseAddress(destination))[y*CVPixelBufferGetBytesPerRow(destination)+x];
        int expected=((const uint8_t *)data.bytes)[y*w*4+x];maximum=std::max(maximum,std::abs(actual-expected));
    }
    CVPixelBufferUnlockBaseAddress(destination,kCVPixelBufferLock_ReadOnly);
    CVPixelBufferRelease(source);CVPixelBufferRelease(destination);CGColorSpaceRelease(srgb);
    std::cout<<"Core Image sRGB + CVPixelBuffer row-order round trip max error="<<maximum<<"\n";
    return maximum<=1?0:5;
} }
