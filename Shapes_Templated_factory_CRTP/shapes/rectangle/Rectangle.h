#pragma once

#include "../Shape.h"
#include "RectangleDimension.h"

namespace rectangle {
    class Rectangle : public shapes::Shape<RectangleDimension, Rectangle> {
    public:
        explicit Rectangle(RectangleDimension *dimension);
        double calculateArea() const;
        double calculatecircumference() const;
    };
}