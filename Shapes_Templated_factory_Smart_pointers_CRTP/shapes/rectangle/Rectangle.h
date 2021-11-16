#pragma once

#include "../Shape.h"
#include "RectangleDimension.h"

namespace shapes {
    namespace rectangle {
        class Rectangle : public shapes::Shape<shapes::rectangle::RectangleDimension, Rectangle> {
        public:
            explicit Rectangle(shapes::rectangle::RectangleDimension *dimension);

            double calculateArea() const;

            double calculateCircumference() const;
        };
    }
}