//
// Created by laptop on 11/10/23.
//

#include "RoundPeg.h"

#include <ostream>

RoundPeg::RoundPeg(double radius) :
    _radius(radius)
{}

double RoundPeg::getRadius() const {
    return this->_radius;
}

void RoundPeg::setRadius(double newRadius) {
    this->_radius = newRadius;
}

std::ostream& operator<<(std::ostream& out, const RoundPeg& roundPeg) {
    out << "round peg with radius of " << roundPeg._radius << " inches";
    return out;
}
