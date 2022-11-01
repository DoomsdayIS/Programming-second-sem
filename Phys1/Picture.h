#pragma once
#include <string>
#include <vector>
struct Pixel {
    unsigned char R = 0;
    unsigned char G = 0;
    unsigned char B = 0;
};
class Picture {
public:
    Picture(int height, int width, Pixel* image);
    ~Picture();
    void SaveToSingleFile(std::string);
private:
    int height;
    int width;
    Pixel* image;
};