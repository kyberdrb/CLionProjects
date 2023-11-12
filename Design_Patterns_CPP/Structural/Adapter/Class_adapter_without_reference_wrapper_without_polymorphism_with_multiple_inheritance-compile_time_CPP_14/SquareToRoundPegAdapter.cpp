//
// Created by laptop on 11/10/23.
//

#include "SquareToRoundPegAdapter.h"

#include <cmath>
#include <ostream>

SquareToRoundPegAdapter::SquareToRoundPegAdapter(SquarePeg& squarePegAdaptee) :
    RoundPeg(0),
    SquarePeg(squarePegAdaptee.getSideLength() )
//    SquarePeg(squarePegAdaptee) // passing the squarePeg instance is equivalent either with explicit constructor or with copy constructor
{
    RoundPeg::updateRadius( (SquarePeg::getSideLength() / 2) * std::sqrt(2) );
}

double SquareToRoundPegAdapter::getRadius() const {
    return RoundPeg::getRadius();
}

std::ostream& operator<<(std::ostream& out, const SquareToRoundPegAdapter& squareToRoundPegAdapter) {
    // static_cast and dynamic_cast function equivalently
//    out << *(dynamic_cast<const SquarePeg*>(&squareToRoundPegAdapter) );
    out << *(static_cast<const SquarePeg*>(&squareToRoundPegAdapter) );
    return out;
}
