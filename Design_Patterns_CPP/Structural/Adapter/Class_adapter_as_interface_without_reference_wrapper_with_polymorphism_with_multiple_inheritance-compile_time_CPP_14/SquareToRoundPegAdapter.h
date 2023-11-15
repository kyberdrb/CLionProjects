//
// Created by laptop on 11/10/23.
//

#pragma once

#include "RoundCompatible.h"
#include "SquarePeg.h"

#include <functional>
#include <iosfwd>

// Adapter class: extends the Target class and the Adaptee class
class SquareToRoundPegAdapter : public RoundCompatible, private SquarePeg {
public:
    explicit SquareToRoundPegAdapter(SquarePeg& squarePegAdaptee);

    // augment Adaptee class with additional behavior by overriding the function from the Adapter Interface
    double getRadius() const override;

    friend std::ostream& operator<<(std::ostream& out, const SquareToRoundPegAdapter& squareToRoundPegAdapter);
};
