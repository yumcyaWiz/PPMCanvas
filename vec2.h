#ifndef VEC2_H
#define VEC2_H
#include <cmath>
template <typename T>
class Vec2 {
    public:
        T x;
        T y;

        Vec2() { x = y = 0; };
        Vec2(T x) :x(x), y(x) {};
        Vec2(T x, T y) : x(x), y(y) {};

        T length() const {
            return std::sqrt(x*x + y*y);
        };
        T length2() const {
            return x*x + y*y;
        };
};
template <typename T>
inline const Vec2<T> operator+(const Vec2<T>& v1, const Vec2<T>& v2) {
    return Vec2<T>(v1.x + v2.x, v1.y + v2.y);
}
template <typename T>
inline const Vec2<T> operator+(const Vec2<T>& v1, T k) {
    return Vec2<T>(v1.x + k, v1.y + k);
}
template <typename T>
inline const Vec2<T> operator+(T k, const Vec2<T>& v2) {
    return v2 + k;
}

template <typename T>
inline const Vec2<T> operator-(const Vec2<T>& v1, const Vec2<T>& v2) {
    return Vec2<T>(v1.x - v2.x, v1.y - v2.y);
}
template <typename T>
inline const Vec2<T> operator-(const Vec2<T>& v1, T k) {
    return Vec2<T>(v1.x - k, v1.y - k);
}
template <typename T>
inline const Vec2<T> operator-(T k, const Vec2<T>& v2) {
    return Vec2<T>(k - v2.x, k - v2.y);
}

template <typename T>
inline const Vec2<T> operator*(const Vec2<T>& v1, const Vec2<T>& v2) {
    return Vec2<T>(v1.x * v2.x, v1.y * v2.y);
}
template <typename T>
inline const Vec2<T> operator*(const Vec2<T>& v1, T k) {
    return Vec2<T>(v1.x * k, v1.y * k);
}
template <typename T>
inline const Vec2<T> operator*(T k, const Vec2<T>& v2) {
    return v2 * k;
}

template <typename T>
inline const Vec2<T> operator/(const Vec2<T>& v1, const Vec2<T>& v2) {
    return Vec2<T>(v1.x / v2.x, v1.y / v2.y);
}
template <typename T>
inline const Vec2<T> operator/(const Vec2<T>& v1, T k) {
    return Vec2<T>(v1.x / k, v1.y / k);
}
template <typename T>
inline const Vec2<T> operator/(T k, const Vec2<T>& v2) {
    return Vec2<T>(k / v2.x, k / v2.y);
}


template <typename T>
inline Vec2<T> normalize(const Vec2<T>& v) {
    return v/v.length();
}


template <typename T>
inline T dot(const Vec2<T>& v1, const Vec2<T>& v2) {
    return v1.x*v2.x + v1.y*v2.y;
}


typedef Vec2<double> Vec2d;
typedef Vec2<float> Vec2f;
typedef Vec2<int> Vec2i;
#endif
