#include "CircleDimension.h"

using namespace circle;

CircleDimension::CircleDimension(double radius) : radius(radius) {}

double CircleDimension::getRadius() const {
    return this->radius;
}