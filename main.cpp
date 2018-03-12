#include "ppm_canvas.h"


int main() {
    Canvas cv(512, 512);
    cv.drawCircleOutline(Vec2f(256, 256), 100.0f, RGB(0, 255, 0));
    cv.ppm_output("output.ppm");
};
