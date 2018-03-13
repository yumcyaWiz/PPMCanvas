#include "ppm_canvas.h"


int main() {
    Canvas cv(512, 512);
    cv.drawTriangle(Vec2f(0, 0), Vec2f(100, 50), Vec2f(50, 100), RGB(0, 255, 0));
    cv.ppm_output("output.ppm");
};
