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


void Image::drawLine(const Vec2f& p1, const Vec2f& p2, const RGB& col) {
    int sx = (int)p1.x;
    int sy = (int)p1.y;
    int ex = (int)p2.x;
    int ey = (int)p2.y;

    this->checkIndex(sx, sy);
    this->checkIndex(ex, ey);

    float slope = (p2.y - p1.y)/(p2.x - p1.x);
    for(int px = sx; px <= ex; px++) {
        float py = sy + slope*(px - sx); 
        this->setPixel(px, (int)py, col);
    }
}
void Image::drawCircle(const Vec2f& p, float r, const RGB& col) {
    int cx = (int)p.x;
    int cy = (int)p.y;

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
void Image::drawRect(const Vec2f& p1, const Vec2f& p2, const RGB& col) {
    int sx = (int)p1.x;
    int sy = (int)p1.y;
    int ex = (int)p2.x;
    int ey = (int)p2.y;

    this->checkIndex(sx, sy);
    this->checkIndex(ex, ey);

    for(int i = sx; i <= ex; i++) {
        for(int j = sy; j <= ey; j++) {
            this->setPixel(i, j, col);
        }
    }
}
