#include "shape.hpp"
#include <iostream>

short Shape::get_height() {
    int i = 0;
    while (i < 5 && shape[i][0])
        i++;
    return i;
}

short Shape::get_width() {
    int i = 0;
    while (i < 5 && shape[0][i])
        i++;
    return i;
}

void Shape::transpose() {
    char aux;
    height = get_height();
    width = get_width();
    int max = (height > width) ? height : width;
    for (int i = 0; i < max; i++) {
        for (int j = i - 1; j >= 0; j--) {
            aux = shape[i][j];
            shape[i][j] = shape[j][i];
            shape[j][i] = aux;
        }
    }
}

void Shape::flip_vertically() {
    char aux;
    height = get_height();
    width = get_width();
    for (int j = 0; j < width; j++) {
        for (int i = 0; i < height / 2; i++) {
            aux = shape[i][j];
            shape[i][j] = shape[height - 1 - i][j];
            shape[height - 1 - i][j] = aux;
        }
    }
}

bool Shape::cmp(Shape other) {
    int i, j;
    bool result = true;
    i = 0;
    while (i < 5 && result) {
        j = 0;
        while (j < 5 && shape[i][j] == other.shape[i][j])
            j++;
        if (j < 5)
            result = false;
        i++;
    }
    return result;
}

void Shape::print() {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++)
            if (shape[i][j] != 0)
                std::cerr.put(shape[i][j]);
        std::cerr.put('\n');
    }
}
