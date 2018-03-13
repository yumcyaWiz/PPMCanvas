#include "ppm_canvas.h"


int main() {
    Canvas cv(512, 512);
    cv.drawEllipseOutline(Vec2f(256, 256), 100, 50, RGB(0, 255, 0));
    cv.ppm_output("output.ppm");
};
