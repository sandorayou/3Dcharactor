#include "../../Assets/Plugins/iOS/PrivacyMosaicCore.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <chrono>
std::vector<uint8_t> Read(const std::string &p) { std::ifstream f(p,std::ios::binary); return {std::istreambuf_iterator<char>(f),std::istreambuf_iterator<char>()}; }
int main(int argc,char **argv) {
    if(argc!=2)return 2;std::string root=argv[1],name;std::ifstream manifest(root+"/manifest.txt");
    if(!manifest)return 3;int w,h,count=0;float cb,cr,sc,sr;
    while(manifest>>name>>w>>h>>cb>>cr>>sc>>sr) {
        auto input=Read(root+"/"+name+".bgra"),expected=Read(root+"/"+name+".mask"),expectedPixel=Read(root+"/"+name+".pixel");
        if(input.size()!=size_t(w)*h*4 || expected.size()!=size_t(w)*h || expectedPixel.size()!=input.size())return 4;
        PrivacyMosaic::SkinClassifier classifier(cb,cr,sc,sr);std::vector<uint8_t> actual;
        auto start=std::chrono::steady_clock::now();
        for(int i=0;i<8;++i)actual=classifier.Classify(input.data(),w,h,w*4);
        int differences=0;for(size_t i=0;i<actual.size();++i)if(actual[i]!=expected[i])++differences;
        auto pixel=PrivacyMosaic::Pixelate(input.data(),w,h,w*4,16);int maxError=0;
        for(size_t i=0;i<pixel.size();++i)maxError=std::max(maxError,std::abs(int(pixel[i])-int(expectedPixel[i])));
        std::cout<<name<<" mask differences="<<differences<<" pixel max error="<<maxError<<"\n";
        if(differences!=0 || maxError>1)return 5;++count;
    }
    if(count!=6)return 6;
    std::cout<<"PASS: 6 fixtures, including first-frame calibration and no-person wall; native masks equal Python; mosaic colour error <= 1/255\n";
    return 0;
}
