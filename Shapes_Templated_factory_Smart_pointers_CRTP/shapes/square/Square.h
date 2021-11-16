#pragma once

#include "../Shape.h"
#include "SquareDimension.h"

namespace shapes {
    namespace square {
        class Square : public shapes::Shape<shapes::square::SquareDimension, Square> {
        public:
            explicit Square(shapes::square::SquareDimension *dimension);
            double calculateArea() const;
            double calculateCircumference() const;
        };
    }
}