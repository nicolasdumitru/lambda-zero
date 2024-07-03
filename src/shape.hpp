# pragma once

class Shape {
public:
    char shape[5][5];
    int width;
    int height;
    short get_height();
    short get_width();
    void transpose();
    void flip_vertically();
};
