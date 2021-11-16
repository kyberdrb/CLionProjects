#pragma once

#include "Shape.h"

//class Square : public Shape {
class Square : public Shape {
    double _side{.0};

public:
    explicit Square(double side) : _side(side) {}

    [[nodiscard]] double getSide() const {
        return _side;
    }

    double calculateArea() override {
        return _side * _side;
    }


    ~Square() override = default;
};