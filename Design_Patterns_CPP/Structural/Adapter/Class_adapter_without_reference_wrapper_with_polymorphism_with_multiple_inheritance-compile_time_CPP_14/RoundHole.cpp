//
// Created by laptop on 11/10/23.
//

#include "RoundHole.h"

#include <ostream>

RoundHole::RoundHole(double radius) :
    _radius(radius)
{}

double RoundHole::getRadius() const {
    return this->_radius;
}

bool RoundHole::fits(const RoundPeg& roundPeg) const {
    return roundPeg.getRadius() <= this->_radius;
}

std::ostream& operator<<(std::ostream& out, const RoundHole& roundHole) {
    out << "round hole with radius of " << roundHole._radius << " inches";
    return out;
}
