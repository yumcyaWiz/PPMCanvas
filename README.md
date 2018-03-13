# PPMCanvas
## Usage
make a canvas
```c++
Canvas cv(512, 512);
```
draw shapes with RGB color
```c++
cv.drawRect(Vec2f(0, 0), Vec2f(100, 100), RGB(0, 255, 0));
```
save the image with ppm_output()
```c++
cv.ppm_output("output.ppm")
```
