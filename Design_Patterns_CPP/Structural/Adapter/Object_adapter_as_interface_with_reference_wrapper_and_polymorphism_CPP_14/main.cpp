#include "RoundHole.h"
#include "SquareToRoundPegAdapter.h"

#include <cassert>
#include <iostream>
#include <memory>

std::string evaluate(bool fits);

int main() {
    auto roundHole = std::make_unique<RoundHole>(5);
    auto roundPeg = std::make_unique<RoundPeg>(5);
    std::cout << "Does " << *roundPeg << " fit into the " << *roundHole << "? "
              << roundPeg->getRadius() << " < " << roundHole->getRadius() << ": " << evaluate(roundHole->fits(*roundPeg) ) << '\n';
    assert(roundHole->fits(*roundPeg) == true);

    auto squarePegSmall = std::make_unique<SquarePeg>(5);
//    std::cout << roundHole->fits(*squarePegSmall) << '\n'; // doesn't compile - incompatible types

    // if we want to use square peg into a round hole, we need to use an adapter
    //  which references square peg and forwards width recalculated to radius to round peg, which the adapter inherits from (round peg)
    auto squareToRoundPegAdapter = std::make_unique<SquareToRoundPegAdapter>(*squarePegSmall);
    std::cout << "Does " << *squareToRoundPegAdapter << " fit into the " << *roundHole << "? "
              << squareToRoundPegAdapter->getRadius() << " < " << roundHole->getRadius() << ": " << evaluate(roundHole->fits(*squareToRoundPegAdapter) ) << '\n';
    assert(roundHole->fits(*squareToRoundPegAdapter) == true);

    auto squarePegLarge = std::make_unique<SquarePeg>(10);
    squareToRoundPegAdapter->plugToDifferentSquarePeg(*squarePegLarge);
    std::cout << "Does " << *squareToRoundPegAdapter << " fit into the " << *roundHole << "? "
              << squareToRoundPegAdapter->getRadius() << " < " << roundHole->getRadius() << ": " << evaluate(roundHole->fits(*squareToRoundPegAdapter) ) << '\n';
    assert(roundHole->fits(*squareToRoundPegAdapter) == false);

    return 0;
}

std::string evaluate(bool fits) {
    if (fits) {
        return "Yes.";
    }
    return "No.";
}
