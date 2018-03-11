#ifndef IMAGE_H
#define IMAGE_H
#include "rgb.h"
class Image {
    public:
        Image(int width, int height);
        ~Image();

        int getWidth() const;
        int getHeight() const;

        RGB getPixel(int i, int j) const;
        void setPixel(int i, int j, const RGB& col);

    private:
        int width;
        int height;
};
#endif
