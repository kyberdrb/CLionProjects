#include "Rectangle.h"

using namespace shapes::rectangle;

Rectangle::Rectangle(shapes::rectangle::RectangleDimension* dimension) :
    Shape(dimension, *this) {}

double Rectangle::calculateArea() const {
    return Shape::getDimension().getSideA() * this->getDimension().getSideB();
}

double Rectangle::calculateCircumference() const {
    return (Shape::getDimension().getSideA() + this->getDimension().getSideB()) * 2;
}