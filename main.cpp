#include "ppm_drawer.h"


int main() {
    Image img(512, 512);
    img.drawTriangle(Vec2f(0, 0), Vec2f(100, 100), Vec2f(50, 10), RGB(0, 255, 0));
    img.ppm_output("output.ppm");
};
