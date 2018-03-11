#ifndef RGB_H
#define RGB_H
#include <iostream>
class RGB {
    public:
        float r;
        float g;
        float b;

        RGB() { r = g = b = 0; };
        RGB(float r): r(r), g(r), b(r) {};
        RGB(float r, float g, float b) : r(r), g(g), b(b) {};
};


inline const RGB operator+(const RGB& col1, const RGB& col2) {
    return RGB(col1.r + col2.r, col1.g + col2.g, col1.b + col2.b);
}
inline const RGB operator-(const RGB& col1, const RGB& col2) {
    return RGB(col1.r - col2.r, col1.g - col2.g, col1.b - col2.b);
}
inline const RGB operator*(const RGB& col1, const RGB& col2) {
    return RGB(col1.r * col2.r, col1.g * col2.g, col1.b * col2.b);
}
inline const RGB operator/(const RGB& col1, const RGB& col2) {
    return RGB(col1.r / col2.r, col1.g / col2.g, col1.b / col2.b);
}


inline std::ostream& operator<<(std::ostream& stream, const RGB& col) {
    stream << "(" << col.r << ", " << col.g << ", " << col.b << ")";
    return stream;
}
#endif
