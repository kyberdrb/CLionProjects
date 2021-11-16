#include "SquareDimension.h"

using namespace shapes::square;

SquareDimension::SquareDimension(double side) : side(side) {}

double SquareDimension::getSide() const {
    return this->side;
}