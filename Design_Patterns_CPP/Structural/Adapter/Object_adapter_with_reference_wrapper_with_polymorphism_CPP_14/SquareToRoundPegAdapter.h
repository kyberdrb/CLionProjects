//
// Created by laptop on 11/10/23.
//

#pragma once

#include "RoundHole.h"
#include "SquarePeg.h"

#include <functional>
#include <iosfwd>

class SquareToRoundPegAdapter : public RoundPeg {
public:
    explicit SquareToRoundPegAdapter(SquarePeg& squarePegAdaptee);

    // plug adapter to another square peg
    void plugToDifferentSquarePeg(SquarePeg& anotherSquarePegAdaptee);
    double getRadius() const override;

    friend std::ostream& operator<<(std::ostream& out, const SquareToRoundPegAdapter& squareToRoundPegAdapter);
private:

    std::reference_wrapper<SquarePeg> _squarePegAdaptee;
};
