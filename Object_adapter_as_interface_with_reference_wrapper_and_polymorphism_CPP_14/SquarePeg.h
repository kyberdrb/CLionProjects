//
// Created by laptop on 11/10/23.
//

#pragma once

#include <cstdint>
#include <iosfwd>

// Adaptee class - may be read-only / provided from external sources
class SquarePeg {
public:
    explicit SquarePeg(double sideLength);

    double getSideLength() const;

    friend std::ostream& operator<<(std::ostream& out, const SquarePeg& squarePeg);

private:
    double _sideLength;
};
