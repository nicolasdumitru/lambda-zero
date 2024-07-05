#pragma once

#include "constants.hpp"
#include "shape.hpp"
#include <bitset>
using std::bitset;

class Pieceset {
public:
    Shape all_shapes[NUM_SHAPES];
    Shape all_orientations[NUM_ROTATIONS];
    bitset<25> bit_pieces[NUM_PIECES];
    void initialize_shapes();
    void generate_orientations();
    void initialize_pieces();
};
