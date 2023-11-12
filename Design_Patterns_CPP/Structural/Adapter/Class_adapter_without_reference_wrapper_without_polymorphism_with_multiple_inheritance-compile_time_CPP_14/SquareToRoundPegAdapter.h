//
// Created by laptop on 11/10/23.
//

#pragma once

#include "RoundHole.h"
#include "SquarePeg.h"

#include <functional>
#include <iosfwd>

class SquareToRoundPegAdapter : public RoundPeg, private SquarePeg {
public:
    explicit SquareToRoundPegAdapter(SquarePeg& squarePegAdaptee);

    // hiding the function instead of overriding a virtual function from the Target class
    double getRadius() const;

    friend std::ostream& operator<<(std::ostream& out, const SquareToRoundPegAdapter& squareToRoundPegAdapter);
};
