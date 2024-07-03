#include "shape.hpp"

short Shape::get_height() {
    int i = 0;
    bool ok = true;
    while (i < 5 && ok) {
        i++;
        // clang-format off
            ok = shape[i][0]
                | shape[i][1]
                | shape[i][2]
                | shape[i][3]
                | shape[i][4];
        // clang-format on
    }
    return i;
}

short Shape::get_width() {
    int i = 0;
    bool ok = true;
    while (i < 5 && ok) {
        i++;
        // clang-format off
            ok = shape[0][i]
                | shape[1][i]
                | shape[2][i]
                | shape[3][i]
                | shape[4][i];
        // clang-format on
    }
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
            shape[height - 1 - i][j] = shape[i][j];
        }
    }
}
