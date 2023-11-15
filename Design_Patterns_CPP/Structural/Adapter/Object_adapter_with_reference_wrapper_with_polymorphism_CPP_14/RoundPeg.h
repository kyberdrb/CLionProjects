//
// Created by laptop on 11/10/23.
//

#pragma once

#include <cstdint>
#include <iosfwd>

// Target class: Existing class which interface the Adapter adapts to
class RoundPeg {
public:
    explicit RoundPeg(double radius);

    virtual double getRadius() const;

    friend std::ostream& operator<<(std::ostream& out, const RoundPeg& roundPeg);

private:
    double _radius;
};
