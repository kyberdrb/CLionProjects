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

    // declare an ordinary function which will be shared - redeclared and redefined - in the Adapter class, whithout making the function virtual
    double getRadius() const;

    friend std::ostream& operator<<(std::ostream& out, const RoundPeg& roundPeg);

protected:
    void updateRadius(double radius);

private:
    double _radius;
};
