#include "constants.hpp"
#include "pieceset.hpp"

void Pieceset::initialize() {
    for (int i = 0; i < 21; i++)
        all_shapes[i] = ALL_SHAPES[i];
}

void Pieceset::generate_rotations() {
    int n, m, k, i, j;
    n = 0;
    for (i = 0; i < 21; i++) {
        all_rotations[n] = all_shapes[i];
        m = n;
        n++;
        for (j = 0; j < 4; j++) {
            all_shapes[i].transpose();
            // clang-format off
            for (k = m; k < n && all_shapes[i].cmp(all_rotations[k]) == false; k++) {}
            // clang-format on
            if (k == n) {
                all_rotations[n] = all_shapes[i];
                n++;
            }

            all_shapes[i].flip_vertically();
            // clang-format off
            for (k = m; k < n && all_shapes[i].cmp(all_rotations[k]) == false; k++) {}
            // clang-format on
            if (k == n) {
                all_rotations[n] = all_shapes[i];
                n++;
            }
        }
    }
}
