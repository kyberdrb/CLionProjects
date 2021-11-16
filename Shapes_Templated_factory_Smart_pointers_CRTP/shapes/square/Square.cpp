#include "Square.h"

using namespace shapes::square;

Square::Square(shapes::square::SquareDimension* dimension) :
    Shape(dimension, *this) {}

double Square::calculateArea() const {
    return Shape::getDimension().getSide() * this->getDimension().getSide();
}

double Square::calculateCircumference() const {
    return Shape::getDimension().getSide() * 4;
}