#ifndef CANVAS_H
#define CANVAS_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "vec2.h"
#include "rgb.h"
class Canvas {
    public:
        Canvas(int width, int height) : width(width), height(height) {
            data = new RGB[width*height];
        };
        ~Canvas() {
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


        void drawLine(const Vec2f& p1, const Vec2f& p2, const RGB& col);
        void drawCircle(const Vec2f& center, float radius, const RGB& col);
        void drawCircleOutline(const Vec2f& center, float radius, const RGB& col);
        void drawRect(const Vec2f& p1, const Vec2f& p2, const RGB& col);
        void drawRectOutline(const Vec2f& p1, const Vec2f& p2, const RGB& col);
        void drawTriangle(const Vec2f& p1, const Vec2f& p2, const Vec2f& p3, const RGB& col);
        void drawTriangleOutline(const Vec2f& p1, const Vec2f& p2, const Vec2f& p3, const RGB& col);


    private:
        int width;
        int height;
        RGB* data;

        void checkIndex(int i, int j) const {
            if(i < 0 || i >= width || j < 0 || j >= height) {
                std::cerr << "Invalid Index" << std::endl;
                std::exit(1);
            };
        };
};
#endif
