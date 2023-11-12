//
// Created by laptop on 11/10/23.
//

#pragma once

#include "RoundCompatible.h"

#include <cstdint>
#include <iosfwd>

class RoundPeg : public RoundCompatible {
public:
    explicit RoundPeg(double radius);

    double getRadius() const override;

    friend std::ostream& operator<<(std::ostream& out, const RoundPeg& roundPeg);

private:
    double _radius;
};
