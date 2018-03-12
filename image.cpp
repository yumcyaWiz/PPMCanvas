#include "image.h"
#include <string>
#include <iostream>
#include <fstream>
#include "rgb.h"
#include "util.h"


void Image::ppm_output(const std::string& filename) const {
    std::ofstream file(filename.c_str());
    
    int width = this->width;
    int height = this->height;

    file << "P3" << std::endl;
    file << width << " " << height << std::endl;
    file << 255 << std::endl;

    for(int j = 0; j < height; j++) {
        for(int i = 0; i < width; i++) {
            RGB col = this->getPixel(i, j);
            file << (int)clamp(255*col.r, 0.f, 255.f) << " " << (int)clamp(255*col.g, 0.f, 255.f) << " " << (int)clamp(255*col.b, 0.f, 255.f) << std::endl;
        }
    }

    file.close();
}


void Image::drawLine(float x1, float y1, float x2, float y2, const RGB& col) {
    int sx = (int)x1;
    int sy = (int)y1;
    int ex = (int)x2;
    int ey = (int)y2;

    this->checkIndex(sx, sy);
    this->checkIndex(ex, ey);

    float slope = (y2 - y1)/(x2 - x1);
    for(int px = sx; px <= ex; px++) {
        float py = sy + slope*(px - sx); 
        this->setPixel(px, (int)py, col);
    }
}
void Image::drawCircle(float x, float y, float r, const RGB& col) {
    int cx = (int)x;
    int cy = (int)y;

    for(int i = -r; i <= r; i++) {
        int px = cx + i;
        if(px < 0 || px > this->width)
            continue;

        for(int j = -r; j <= r; j++) {
            int py = cy + j;
            if(py < 0 || py > this->height)
                continue;

            if((px - cx)*(px - cx) + (py - cy)*(py - cy) >= r*r)
                continue;

            this->setPixel(px, py, col);
        }
    }
}
void Image::drawRect(float x1, float y1, float x2, float y2, const RGB& col) {
    int sx = (int)x1;
    int sy = (int)y1;
    int ex = (int)x2;
    int ey = (int)y2;

    this->checkIndex(sx, sy);
    this->checkIndex(ex, ey);

    for(int i = sx; i <= ex; i++) {
        for(int j = sy; j <= ey; j++) {
            this->setPixel(i, j, col);
        }
    }
}
