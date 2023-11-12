//
// Created by laptop on 11/10/23.
//

#pragma once

#include "RoundPeg.h"
#include "SquarePeg.h"

#include <iosfwd>

// Client
class RoundHole {
public:
    explicit RoundHole(double radius);

    virtual double getRadius() const;
    bool fits(const RoundCompatible& roundCompatiblePeg) const;

    friend std::ostream& operator<<(std::ostream& out, const RoundHole& roundHole);

private:
    double _radius;
};
