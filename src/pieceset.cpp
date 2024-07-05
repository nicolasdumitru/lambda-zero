#include "pieceset.hpp"
#include "constants.hpp"

void Pieceset::initialize_shapes() {
    for (int i = 0; i < NUM_SHAPES; i++)
        all_shapes[i] = ALL_SHAPES[i];
}

void Pieceset::generate_orientations() {
    // Core idea:
    // Transposing a shape, then flipping this vertically and repeating the
    // process 8 times is a process which incrementally generates all the 8
    // possible orientations of any piece (rotations, mirrors, flips). Some of
    // these orientations will be repetitions of others for a subset of the
    // pieces.
    int n, m, k, i, j;
    n = 0;
    for (i = 0; i < NUM_SHAPES; i++) {
        all_orientations[n] = all_shapes[i];
        m = n;
        n++;
        for (j = 0; j < 4; j++) {
            all_shapes[i].transpose();
            // clang-format off
            for (k = m; k < n && all_shapes[i].cmp(all_orientations[k]) == false; k++) {}
            // clang-format on
            if (k == n) {
                all_orientations[n] = all_shapes[i];
                n++;
            }

            all_shapes[i].flip_vertically();
            // clang-format off
            for (k = m; k < n && all_shapes[i].cmp(all_orientations[k]) == false; k++) {}
            // clang-format on
            if (k == n) {
                all_orientations[n] = all_shapes[i];
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
                    = (all_orientations[i].shape[row][col] = '#') ? 1 : 0;
            }
        }
    }
}
