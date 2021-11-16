#pragma once

#include "../Shape.h"
#include "CircleDimension.h"

namespace circle {
    class Circle : public shapes::Shape<CircleDimension, Circle> {
    public:
        explicit Circle(CircleDimension *dimension);
        double calculateArea() const;
        double calculatecircumference() const;
        double calculateDiameter() const;
    };
}