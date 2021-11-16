#pragma once

namespace rectangle {
    class RectangleDimension {
    public:
        RectangleDimension(double sideA, double sideB);
        double getSideA() const;
        double getSideB() const;

    private:
        double sideA{};
        double sideB{};
    };
}