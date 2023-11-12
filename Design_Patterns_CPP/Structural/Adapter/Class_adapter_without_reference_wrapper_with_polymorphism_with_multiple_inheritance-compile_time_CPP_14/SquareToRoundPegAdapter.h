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

    double getRadius() const override;

    friend std::ostream& operator<<(std::ostream& out, const SquareToRoundPegAdapter& squareToRoundPegAdapter);
};
