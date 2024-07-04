#pragma once

#include "shape.hpp"
class Pieceset {
public:
    Shape all_shapes[21];
    Shape all_rotations[91];
    void initialize();
    void generate_rotations();
};
