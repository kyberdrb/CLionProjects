#include "CircleDimension.h"

using namespace shapes::circle;

CircleDimension::CircleDimension(double radius) : radius(radius) {}

double CircleDimension::getRadius() const {
    return this->radius;
}