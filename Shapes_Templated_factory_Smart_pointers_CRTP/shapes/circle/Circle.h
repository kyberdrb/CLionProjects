#pragma once

#include "../Shape.h"
#include "CircleDimension.h"

namespace shapes {
    namespace circle {
        class Circle : public shapes::Shape<shapes::circle::CircleDimension, Circle> {
        public:
            explicit Circle(shapes::circle::CircleDimension *dimension);
            double calculateArea() const;
            double calculateCircumference() const;
            double calculateDiameter() const;
        };
    }
}