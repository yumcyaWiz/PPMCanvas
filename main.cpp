#include "ppm_drawer.h"


int main() {
    Image img(512, 512);
    img.ppm_output("output.ppm");
};
