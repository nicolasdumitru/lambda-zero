#pragma once

#include "shape.hpp"
#include <bitset>
using std::bitset;

const short NUM_SHAPES = 21;
extern const Shape ALL_SHAPES[NUM_SHAPES];

const short NUM_ROTATIONS = 91;
const short NUM_PIECES = NUM_ROTATIONS;

const bitset<256> BORDER("1111111111111111"
                         "1000000000000001"
                         "1000000000000001"
                         "1000000000000001"
                         "1000000000000001"
                         "1000000000000001"
                         "1000000000000001"
                         "1000000000000001"
                         "1000000000000001"
                         "1000000000000001"
                         "1000000000000001"
                         "1000000000000001"
                         "1000000000000001"
                         "1000000000000001"
                         "1000000000000001"
                         "1111111111111111");
