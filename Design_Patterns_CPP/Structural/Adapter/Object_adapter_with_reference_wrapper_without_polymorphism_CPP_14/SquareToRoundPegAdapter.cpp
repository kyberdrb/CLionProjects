//
// Created by laptop on 11/10/23.
//

#include "SquareToRoundPegAdapter.h"

#include <cmath>
#include <ostream>

SquareToRoundPegAdapter::SquareToRoundPegAdapter(SquarePeg& squarePegAdaptee) :
    RoundPeg(0),
    _squarePegAdaptee(squarePegAdaptee)
{
    updateRadius(_squarePegAdaptee.get().getSideLength());
}

void SquareToRoundPegAdapter::updateRadius(double squareSideLength) {
    RoundPeg::setRadius( (squareSideLength / 2) * std::sqrt(2) );
}

void SquareToRoundPegAdapter::plugToDifferentSquarePeg(SquarePeg& anotherSquarePegAdaptee) {
    // works too except of when accessing elements of a vector<reference_wrapper> by square brackets '[]' operator
    //  https://stackoverflow.com/questions/15463721/assign-a-value-to-a-stdreference-wrapper/15463758#15463758
//    this->_squarePegAdaptee = anotherSquarePegAdaptee;

    this->_squarePegAdaptee.get() = anotherSquarePegAdaptee;
    updateRadius(_squarePegAdaptee.get().getSideLength() );
}

std::ostream& operator<<(std::ostream& out, const SquareToRoundPegAdapter& squareToRoundPegAdapter) {
    out << squareToRoundPegAdapter._squarePegAdaptee.get();
    return out;
}
