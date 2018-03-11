#include "image.h"
#include <string>
#include <iostream>
#include <fstream>
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
            file << clamp(col.r, 0.f, 255.f) << " " << clamp(col.g, 0.f, 255.f) << " " << clamp(col.b, 0.f, 255.f) << std::endl;
        }
    }

    file.close();
}
