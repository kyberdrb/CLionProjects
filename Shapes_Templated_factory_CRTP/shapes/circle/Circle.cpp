#include "Circle.h"

#include <cmath>

using namespace circle;

Circle::Circle(CircleDimension* dimension) : Shape(dimension, this) {}

double Circle::calculateArea() const  {
    return M_PI * Shape::getDimension()->getRadius() * Shape::getDimension()->getRadius();
}

double Circle::calculatecircumference() const {
    return 2 * M_PI * this->getDimension()->getRadius();
}

double Circle::calculateDiameter() const {
    return Shape::getDimension()->getRadius() * 2;
}