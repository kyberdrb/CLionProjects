//
// Created by laptop on 11/10/23.
//

#include "SquarePeg.h"

#include <ostream>

SquarePeg::SquarePeg(double sideLength) :
    _sideLength(sideLength)
{}

double SquarePeg::getSideLength() const {
    return this->_sideLength;
}

std::ostream& operator<<(std::ostream& out, const SquarePeg& squarePeg) {
    out << "square peg with side length of " << squarePeg._sideLength << " inches";
    return out;
}
