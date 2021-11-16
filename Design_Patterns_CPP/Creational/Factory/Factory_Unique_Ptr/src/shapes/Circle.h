#pragma once

#include <cmath>

#include "Shape.h"

class Circle : public Shape {
private:
    double radius{.0};

public:
    explicit Circle(double radius) : Shape(), radius(radius){}

    double getRadius() const {
        return radius;
    }

    double calculateDiameter() const {
        return 2 * radius;
    }

    double calculateArea() override {
        return M_PI * radius * radius;
    }

    ~Circle() override = default;
};