//
// Created by laptop on 11/10/23.
//

#pragma once

#include "RoundPeg.h"
#include "SquarePeg.h"

#include <functional>
#include <iosfwd>

// Adapter class: extends the Target class and the Adaptee class
class SquareToRoundPegAdapter : public RoundPeg, private SquarePeg {
public:
    explicit SquareToRoundPegAdapter(SquarePeg& squarePegAdaptee);

    // augment Adaptee class with additional behavior by overriding the function from the Target class
    double getRadius() const override;

    friend std::ostream& operator<<(std::ostream& out, const SquareToRoundPegAdapter& squareToRoundPegAdapter);
};
