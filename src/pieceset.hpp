#pragma once

#include "constants.hpp"
#include "shape.hpp"
class Pieceset {
public:
    Shape all_shapes[NUM_SHAPES];
    Shape all_rotations[NUM_ROTATIONS];
    void generate_rotations();
};
