//
// Created by laptop on 11/10/23.
//

#pragma once

#include "RoundCompatible.h"

#include <iosfwd>

class RoundHole {
public:
    explicit RoundHole(double radiusInInches);

    double getRadius() const;
    bool fits(const RoundCompatible& roundCompatiblePeg) const;

    friend std::ostream& operator<<(std::ostream& out, const RoundHole& roundHole);

private:
    double _radius;
};
