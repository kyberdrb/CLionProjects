#include "RectangleDimension.h"

using namespace rectangle;

RectangleDimension::RectangleDimension(double sideA, double sideB) :
    sideA(sideA), sideB(sideB) {}

double RectangleDimension::getSideA() const {
    return sideA;
}

double RectangleDimension::getSideB() const {
    return sideB;
}