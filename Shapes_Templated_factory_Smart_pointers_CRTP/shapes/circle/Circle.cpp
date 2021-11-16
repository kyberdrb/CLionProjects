#include "Circle.h"

#include <cmath>

using namespace shapes::circle;

Circle::Circle(shapes::circle::CircleDimension* dimension) :
    Shape(dimension, *this) {}

double Circle::calculateArea() const {
    return M_PI * Shape::getDimension().getRadius() * Shape::getDimension().getRadius();
}

double Circle::calculateCircumference() const {
    return 2 * M_PI * this->getDimension().getRadius();
}

double Circle::calculateDiameter() const {
    return Shape::getDimension().getRadius() * 2;
}