# pragma once

class Shape {
public:
    char shape[5][5];
    int width = 0;
    int height = 0;
    short get_height();
    short get_width();
    void transpose();
    void flip_vertically();
};
