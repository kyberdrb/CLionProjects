#pragma once

#include "../Shape.h"
#include "SquareDimension.h"

namespace square {
    class Square : public shapes::Shape<SquareDimension, Square> {
    public:
        explicit Square(SquareDimension *dimension);
        double calculateArea() const;
        double calculatecircumference() const;
    };
}