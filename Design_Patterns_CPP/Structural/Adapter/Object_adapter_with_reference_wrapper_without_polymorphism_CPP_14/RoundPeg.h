//
// Created by laptop on 11/10/23.
//

#pragma once

#include <cstdint>
#include <iosfwd>

class RoundPeg {
public:
    explicit RoundPeg(double radius);

    double getRadius() const;
    void setRadius(double newRadius);

    friend std::ostream& operator<<(std::ostream& out, const RoundPeg& roundPeg);

private:
    double _radius;
};