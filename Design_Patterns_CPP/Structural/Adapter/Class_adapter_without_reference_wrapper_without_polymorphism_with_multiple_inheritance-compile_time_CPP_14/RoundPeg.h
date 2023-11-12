//
// Created by laptop on 11/10/23.
//

#pragma once

#include <cstdint>
#include <iosfwd>

class RoundPeg {
public:
    explicit RoundPeg(double radius);

    // declare a standard function which will be redeclared and redefined in the Adapter class, whithout making the function virtual
    double getRadius() const;

    friend std::ostream& operator<<(std::ostream& out, const RoundPeg& roundPeg);

protected:
    void updateRadius(double radius);

private:
    double _radius;
};
