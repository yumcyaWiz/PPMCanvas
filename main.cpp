#include "ppm_drawer.h"


int main() {
    Image img(512, 512);
    img.drawCircle(256, 256, 100, RGB(255));
    img.ppm_output("output.ppm");
};
