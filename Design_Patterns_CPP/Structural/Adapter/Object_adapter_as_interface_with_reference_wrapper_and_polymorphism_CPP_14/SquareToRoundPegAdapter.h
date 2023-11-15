//
// Created by laptop on 11/10/23.
//

#pragma once

#include "RoundPeg.h"
#include "SquarePeg.h"

#include <functional>
#include <iosfwd>

// Adapter class: implements the Adapter Interface
class SquareToRoundPegAdapter : public RoundCompatible {
public:
    explicit SquareToRoundPegAdapter(SquarePeg& squarePegAdaptee);

    // augment Adaptee class with additional behavior by overriding the function from the Adapter Interface
    double getRadius() const override;

    // plug adapter to another square peg
    void plugToDifferentSquarePeg(SquarePeg& anotherSquarePegAdaptee);

    friend std::ostream& operator<<(std::ostream& out, const SquareToRoundPegAdapter& squareToRoundPegAdapter);

private:
    std::reference_wrapper<SquarePeg> _squarePegAdaptee;
};
