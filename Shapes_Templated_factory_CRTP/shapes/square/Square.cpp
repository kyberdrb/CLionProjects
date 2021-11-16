#include "Square.h"

using namespace square;

Square::Square(SquareDimension* dimension) : Shape(dimension, this) {}

double Square::calculateArea() const {
    return Shape::getDimension()->getSide() * this->getDimension()->getSide();
}

double Square::calculatecircumference() const {
    return Shape::getDimension()->getSide() * 4;
}