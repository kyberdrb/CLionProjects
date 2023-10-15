#include <iostream>
#include <memory>
#include <cassert>
#include <cmath>

class RoundPeg {
public:
    explicit RoundPeg(double radius) : radius(radius) {}

    double getRadius() const {
        return this->radius;
    }

    virtual ~RoundPeg() = default;

private:
    double radius;
};

class SquarePeg : public RoundPeg {     // But this inheritance/generalization relationship doesn't make sense!
                                        // SquarePeg "is a" RoundPeg? No! It's not.
                                        // SquarePeg differs semantically from a RoundPeg.
                                        // The "radius" of a RoundPeg can be confusing when used for "width" in SquarePeg
                                        // RoundPeg fits into the RoundHole, as long as the radius of the RoundPeg
                                        //  is less or equal than the radius of the RoundHole.
                                        // But SquarePeg has different kind of attributes and methods than RoundPeg.
                                        // Therefore, if we want to use SquarePeg for the RoundHole,
                                        // we need to introduce an intermediary piece between the
                                        // SquarePeg and RoundPeg.
                                        // We will call this piece an Adapter, or Converter or Compatibility Layer.
                                        // The Adapter will convert the protocol of one class to protocol of another class.
public:
    explicit SquarePeg(double width) :
        RoundPeg{(sqrt(2) * width) / 2},
        width(width) {}

    double getWidth() const {
        return this->width;
    }

private:
    double width;
};

class RoundHole {
public:
    explicit RoundHole(double radius) : radius(radius) {}

    double getRadius() const {
        return this->radius;
    }

    bool fits(const RoundPeg& peg) {
        std::cout << this->radius << " < " << peg.getRadius() << "\n";
        return this->radius >= peg.getRadius();
    }

private:
    double radius;
};

int main() {
    auto roundHole = std::make_unique<RoundHole>(10);
    auto roundPeg = std::make_unique<RoundPeg>(10);
    assert(roundHole->fits(*roundPeg) == true);

    auto squarePeg = std::make_unique<SquarePeg>(14.14);
    assert(roundHole->fits(*squarePeg) == true);

    return 0;
}
