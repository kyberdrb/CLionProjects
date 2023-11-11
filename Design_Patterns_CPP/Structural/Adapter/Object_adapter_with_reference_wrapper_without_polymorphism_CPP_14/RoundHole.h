//
// Created by laptop on 11/10/23.
//

#pragma once

#include "RoundPeg.h"
#include "SquarePeg.h"

#include <iosfwd>

class RoundHole {
public:
    explicit RoundHole(double radiusInInches);

    double getRadius() const;
    bool fits(const RoundPeg& roundPeg) const;

    friend std::ostream& operator<<(std::ostream& out, const RoundHole& roundHole);

private:
    double _radius;
};
