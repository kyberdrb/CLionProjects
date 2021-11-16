#pragma once

#include "Shape.h"

class NullShape : public Shape {
public:
    NullShape() {}

    double calculateArea() override {
        return 0;
    }
};