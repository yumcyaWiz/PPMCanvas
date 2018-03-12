#include "ppm_canvas.h"


int main() {
    Canvas cv(512, 512);
    cv.drawLine(Vec2f(0, 0), Vec2f(150, 100), RGB(0, 255, 0));
    cv.ppm_output("output.ppm");
};
