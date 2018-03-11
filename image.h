#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "rgb.h"
class Image {
    public:
        Image(int width, int height) : width(width), height(height) {
            data = new RGB[width*height];
        };
        ~Image() {
            delete[] data;
        };

        int getWidth() const {
            return width;
        };
        int getHeight() const {
            return height;
        };

        RGB getPixel(int i, int j) const {
            this->checkIndex(i, j);
            return data[i + j*width];
        };
        void setPixel(int i, int j, const RGB& col) {
            this->checkIndex(i, j);
            data[i + j*width] = col;
        };

        void ppm_output(const std::string& filename) const;


    private:
        int width;
        int height;
        RGB* data;

        void checkIndex(int i, int j) const {
            if(i < 0 || i > width || j < 0 || j > height) {
                std::cerr << "Invalid Index" << std::endl;
                std::exit(1);
            };
        };
};
#endif
