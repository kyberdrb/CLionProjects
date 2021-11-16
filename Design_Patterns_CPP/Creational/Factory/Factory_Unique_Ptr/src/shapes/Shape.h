#pragma once

#include <string>

class Shape {
public:

    virtual double calculateArea() = 0;

    virtual ~Shape() = default;
};