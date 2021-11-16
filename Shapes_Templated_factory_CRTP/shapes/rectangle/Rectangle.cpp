#include "Rectangle.h"

using namespace rectangle;

Rectangle::Rectangle(RectangleDimension* dimension) : Shape(dimension, this) {}

double Rectangle::calculateArea() const {
    return Shape::getDimension()->getSideA() * this->getDimension()->getSideB();
}

double Rectangle::calculatecircumference() const {
    return (Shape::getDimension()->getSideA() + this->getDimension()->getSideB()) * 2;
}