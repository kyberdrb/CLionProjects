//
// Created by laptop on 7/31/19.
//

#include "Color_Specification.h"

Color_Specification::Color_Specification(Color color) : color(color) {}

bool Color_Specification::is_statisfied(Product *item) {
    return item->color == color;
}
