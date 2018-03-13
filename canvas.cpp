#include "canvas.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "rgb.h"
#include "util.h"


void Canvas::ppm_output(const std::string& filename) const {
    std::ofstream file(filename.c_str());
    
    int width = this->width;
    int height = this->height;

    file << "P3" << std::endl;
    file << width << " " << height << std::endl;
    file << 255 << std::endl;

    for(int j = 0; j < height; j++) {
        for(int i = 0; i < width; i++) {
            RGB col = this->getPixel(i, j);
            file << (int)clamp(col.r, 0.f, 255.f) << " " << (int)clamp(col.g, 0.f, 255.f) << " " << (int)clamp(col.b, 0.f, 255.f) << std::endl;
        }
    }

    file.close();
}


void Canvas::drawLine(const Vec2f& p1, const Vec2f& p2, const RGB& col) {
    this->checkIndex(p1.x, p1.y);
    this->checkIndex(p2.x, p2.y);

    Vec2f direction = normalize(p2 - p1);
    float dist = (p2 - p1).length();
    for(float t = 0; t <= dist; t++) {
        Vec2f p = p1 + t*direction;
        this->setPixel((int)p.x, (int)p.y, col);
    }
}
void Canvas::drawCircle(const Vec2f& p, float r, const RGB& col) {
    int cx = (int)p.x;
    int cy = (int)p.y;

    for(int i = -r; i <= r; i++) {
        int px = cx + i;
        if(px < 0 || px > this->width)
            continue;

        for(int j = -r; j <= r; j++) {
            int py = cy + j;
            if(py < 0 || py > this->height)
                continue;

            if((px - cx)*(px - cx) + (py - cy)*(py - cy) >= r*r)
                continue;

            this->setPixel(px, py, col);
        }
    }
}
void Canvas::drawCircleOutline(const Vec2f& p, float r, const RGB& col) {
    for(float theta = 0; theta <= 2*M_PI; theta += 0.01) {
        Vec2f cp = p + r*Vec2f(std::cos(theta), std::sin(theta));

        int cpxi = (int)cp.x;
        int cpyi = (int)cp.y;
        if(cpxi < 0 || cpxi >= this->width || cpyi < 0 || cpyi >= this->height)
            continue;

        this->setPixel(cpxi, cpyi, col);
    }
}

void Canvas::drawEllipse(const Vec2f& center, float rx, float ry, const RGB& col) {
    int cx = (int)center.x;
    int cy = (int)center.y;

    for(int px = cx - rx; px <= cx + rx; px++) {
        if(px < 0 || px >= this->width)
            continue;
        for(int py = cy - ry; py <= cy + ry; py++) {
            if(py < 0 || py >= this->height)
                continue;

            if(((px - cx)*(px - cx))/(rx*rx) + ((py - cy)*(py - cy))/(ry*ry) >= 1)
                continue;
            
            this->setPixel(px, py, col);
        }
    }
}
void Canvas::drawEllipseOutline(const Vec2f& center, float rx, float ry, const RGB& col) {
    for(float theta = 0; theta <= 2*M_PI; theta += 0.01) {
        Vec2f p = center + Vec2f(rx*std::cos(theta), ry*std::sin(theta));
        if(p.x < 0 || p.x >= this->width || p.y < 0 || p.y >= this->height)
            continue;
        
        this->setPixel(p.x, p.y, col);
    }
}

void Canvas::drawRect(const Vec2f& p1, const Vec2f& p2, const RGB& col) {
    int sx = (int)p1.x;
    int sy = (int)p1.y;
    int ex = (int)p2.x;
    int ey = (int)p2.y;

    for(int i = sx; i <= ex; i++) {
        for(int j = sy; j <= ey; j++) {
            if(i < 0 || i >= this->width || j < 0 || j >= this->height)
                continue;

            this->setPixel(i, j, col);
        }
    }
}
void Canvas::drawRectOutline(const Vec2f& p1, const Vec2f& p2, const RGB& col) {
    int sx = (int)p1.x;
    int sy = (int)p1.y;
    int ex = (int)p2.x;
    int ey = (int)p2.y;
    
    this->checkIndex(sx, sy);
    this->checkIndex(ex, ey);

    Vec2f p3(p1.x, p2.y), p4(p2.x, p1.y);

    this->drawLine(p1, p3, col);
    this->drawLine(p3, p2, col);
    this->drawLine(p2, p4, col);
    this->drawLine(p4, p1, col);
}

void Canvas::drawTriangle(const Vec2f& p1, const Vec2f& p2, const Vec2f& p3, const RGB& col) {
    int sx = (int)std::min(p1.x, std::min(p2.x, p3.x));
    int sy = (int)std::min(p1.y, std::min(p2.y, p3.y));
    int ex = (int)std::max(p1.x, std::max(p2.x, p3.x));
    int ey = (int)std::max(p1.y, std::max(p2.y, p3.y));

    Vec2f p1p2 = p2 - p1;
    Vec2f p2p3 = p3 - p2;
    Vec2f p3p1 = p1 - p3;
    for(int px = sx; px <= ex; px++) {
        for(int py = sy; py <= ey; py++) {
            if(px < 0 || px >= this->width || py < 0 || py >= this->height)
                continue;

            Vec2f p0(px, py);
            Vec2f p1p0 = p1 - p0;
            Vec2f p2p0 = p2 - p0;
            Vec2f p3p0 = p3 - p0;

            if(!(cross(p1p2, p1p0) < 0 && cross(p2p3, p2p0) < 0 && cross(p3p1, p3p0) < 0))
                continue;

            this->setPixel(px, py, col);
        }
    }
}
void Canvas::drawTriangleOutline(const Vec2f& p1, const Vec2f& p2, const Vec2f& p3, const RGB& col) {
    this->drawLine(p1, p2, col);
    this->drawLine(p2, p3, col);
    this->drawLine(p3, p1, col);
}
