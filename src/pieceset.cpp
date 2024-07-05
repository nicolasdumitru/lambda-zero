#include "pieceset.hpp"
#include "constants.hpp"

void Pieceset::initialize_shapes() {
    for (int i = 0; i < NUM_SHAPES; i++)
        all_shapes[i] = ALL_SHAPES[i];
}

void Pieceset::generate_rotations() {
    int n, m, k, i, j;
    n = 0;
    for (i = 0; i < NUM_SHAPES; i++) {
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

void Pieceset::initialize_pieces() {
    for (int i = 0; i < NUM_PIECES; i++) {
        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                bit_pieces[i][5 * row + col]
                    = (all_rotations[i].shape[row][col] = '#') ? 1 : 0;
            }
        }
    }
}
