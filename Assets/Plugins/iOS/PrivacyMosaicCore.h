#pragma once
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <vector>

namespace PrivacyMosaic {
struct EmptySceneGate {
    int64_t emptySince=-1;
    bool ClearBackground(int64_t now,int64_t faceAt,bool facePresent,int64_t poseAt,bool posePresent) {
        bool fresh=faceAt>0 && poseAt>0 && now>=faceAt && now>=poseAt &&
            now-faceAt<=150 && now-poseAt<=150;
        if (!fresh || facePresent || posePresent) { emptySince=-1;return false; }
        if (emptySince<0 || now<emptySince) emptySince=now;
        return now-emptySince>=300;
    }
};
template<class T> inline T Clamp(T v,T low,T high) { return std::max(low,std::min(high,v)); }
struct SkinClassifier {
    float cb, cr, seedCb, seedCr, spreadCb, spreadCr;
    bool registered=false;
    SkinClassifier(float cb0,float cr0,float cbSpread,float crSpread)
        : cb(cb0),cr(cr0),seedCb(cb0),seedCr(cr0),spreadCb(cbSpread),spreadCr(crSpread) {}
    std::vector<uint8_t> Classify(const uint8_t *pixels,int w,int h,size_t stride) {
        size_t count=static_cast<size_t>(w)*h;
        std::vector<uint8_t> raw(count),tmp(count),dilated(count),closed(count),outside(count);
        std::vector<float> luminance(count);
        float sumCb=0,sumCr=0,sumY=0; int samples=0;
        for(int y=0;y<h;++y) for(int x=0;x<w;++x) {
            const uint8_t *p=pixels+y*stride+x*4;
            float luma=.299f*p[2]+.587f*p[1]+.114f*p[0];
            float normalizer=140.f/std::max(luma,20.f);
            float c=128.f+.564f*(p[0]-luma)*normalizer, r=128.f+.713f*(p[2]-luma)*normalizer;
            float dc=(c-cb)/spreadCb, dr=(r-cr)/spreadCr, distance=dc*dc+dr*dr;
            bool skin=luma>20 && luma<250 && r>132 && c<132 && r<cr+7 && distance<2.25f;
            raw[y*w+x]=skin?255:0; luminance[y*w+x]=luma;
            if(skin && distance<.64f && x>=w*35/100 && x<w*65/100 && y>=h/10 && y<h*3/5) {
                sumCb+=c;sumCr+=r;sumY+=luma;++samples;
            }
        }
        if(!registered && samples<40) {
            float initialCb=0,initialCr=0;int initialCount=0;
            for(int y=h/10;y<h*3/5;++y) for(int x=w*35/100;x<w*65/100;++x) {
                const uint8_t *p=pixels+y*stride+x*4;
                float luma=.299f*p[2]+.587f*p[1]+.114f*p[0],normalizer=140.f/std::max(luma,20.f);
                float c=128.f+.564f*(p[0]-luma)*normalizer,r=128.f+.713f*(p[2]-luma)*normalizer;
                if(luma>40 && luma<230 && c>90 && c<124 && r>135 && r<180 && std::abs(c-seedCb)<14 && std::abs(r-seedCr)<18) {
                    initialCb+=c;initialCr+=r;++initialCount;
                }
            }
            if(initialCount>=40) {
                cb=Clamp(initialCb/initialCount,seedCb-6,seedCb+6);
                cr=Clamp(initialCr/initialCount,seedCr-6,seedCr+6);registered=true;
                return Classify(pixels,w,h,stride);
            }
        }
        if(samples>=40) for(size_t i=0;i<count;++i) if(luminance[i]<sumY/samples*.55f) raw[i]=0;
        for(int y=0;y<h;++y) for(int x=0;x<w;++x) {
            uint8_t v=0; for(int d=-4;d<=4;++d) v=std::max(v,raw[y*w+Clamp(x+d,0,w-1)]); tmp[y*w+x]=v;
        }
        for(int y=0;y<h;++y) for(int x=0;x<w;++x) {
            uint8_t v=0; for(int d=-4;d<=4;++d) v=std::max(v,tmp[Clamp(y+d,0,h-1)*w+x]); dilated[y*w+x]=v;
        }
        for(int y=0;y<h;++y) for(int x=0;x<w;++x) {
            uint8_t v=255; for(int d=-4;d<=4;++d) v=std::min(v,dilated[y*w+Clamp(x+d,0,w-1)]); tmp[y*w+x]=v;
        }
        for(int y=0;y<h;++y) for(int x=0;x<w;++x) {
            uint8_t v=255; for(int d=-4;d<=4;++d) v=std::min(v,tmp[Clamp(y+d,0,h-1)*w+x]); closed[y*w+x]=v;
        }
        for(int y=0;y<h;++y) {
            int x=0;
            while(x<w) {
                if(closed[y*w+x]) { ++x;continue; }
                int start=x;while(x<w && !closed[y*w+x]) ++x;
                if(start>0 && x<w && x-start<=w/5) for(int fill=start;fill<x;++fill) closed[y*w+fill]=255;
            }
        }
        std::vector<int> queue;queue.reserve(count);
        auto add=[&](int x,int y) {int i=y*w+x;if(!closed[i]&&!outside[i]) {outside[i]=255;queue.push_back(i);} };
        for(int x=0;x<w;++x) {add(x,0);add(x,h-1);} for(int y=0;y<h;++y) {add(0,y);add(w-1,y);}
        for(size_t i=0;i<queue.size();++i) {
            int x=queue[i]%w,y=queue[i]/w;
            if(x>0)add(x-1,y);if(x+1<w)add(x+1,y);if(y>0)add(x,y-1);if(y+1<h)add(x,y+1);
        }
        for(size_t i=0;i<count;++i) closed[i]=(closed[i]||!outside[i])?255:0;
        for(int y=0;y<h;++y) for(int x=0;x<w;++x) {
            uint8_t v=0;for(int dy=-1;dy<=1;++dy) for(int dx=-1;dx<=1;++dx)
                v=std::max(v,closed[Clamp(y+dy,0,h-1)*w+Clamp(x+dx,0,w-1)]);
            raw[y*w+x]=v;
        }
        if(samples>=40) {
            float rate=registered?.04f:.25f;
            cb=Clamp(cb+Clamp(sumCb/samples-cb,-4.f,4.f)*rate,seedCb-6,seedCb+6);
            cr=Clamp(cr+Clamp(sumCr/samples-cr,-4.f,4.f)*rate,seedCr-6,seedCr+6);
            registered=true;
        }
        return raw;
    }
};
// INTER_AREA-style area averages, followed by nearest-neighbour expansion.
inline std::vector<uint8_t> Pixelate(const uint8_t *input,int w,int h,size_t stride,int block) {
    int gw=(w+block-1)/block,gh=(h+block-1)/block;
    std::vector<uint8_t> grid(static_cast<size_t>(gw)*gh*4),output(static_cast<size_t>(w)*h*4);
    for(int gy=0;gy<gh;++gy) for(int gx=0;gx<gw;++gx) {
        double left=double(gx)*w/gw,right=double(gx+1)*w/gw,top=double(gy)*h/gh,bottom=double(gy+1)*h/gh;
        double sum[3]={0,0,0},area=(right-left)*(bottom-top);
        for(int y=int(top);y<std::min(h,int(std::ceil(bottom)));++y) for(int x=int(left);x<std::min(w,int(std::ceil(right)));++x) {
            double weight=(std::min(right,double(x+1))-std::max(left,double(x)))*(std::min(bottom,double(y+1))-std::max(top,double(y)));
            const uint8_t *p=input+y*stride+x*4;for(int c=0;c<3;++c) sum[c]+=p[c]*weight;
        }
        uint8_t *p=&grid[(gy*gw+gx)*4];for(int c=0;c<3;++c)p[c]=uint8_t(Clamp(int(std::nearbyint(sum[c]/area)),0,255));p[3]=255;
    }
    for(int y=0;y<h;++y)for(int x=0;x<w;++x) {
        const uint8_t *p=&grid[((y*gh/h)*gw+x*gw/w)*4];uint8_t *q=&output[(y*w+x)*4];
        for(int c=0;c<4;++c)q[c]=p[c];
    }
    return output;
}
}
