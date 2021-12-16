#include "Brick.h"

Brick::Brick() :
    row(0),
    column(2),
    isBrickVisible(false)
{}

int_fast32_t Brick::getRow() const {
    return row;
}

int_fast32_t Brick::getColumn() const {
    return column;
}

std::string Brick::getBrickSign() const {
    return "■"; // '■' - BLACK SQUARE; '⎕ - Apl Functional Symbol Quad'; '□ - White Square'; '⌷ - Apl Functional Symbol Squish Quad'
}

bool Brick::isVisible() const {
    return isBrickVisible;
}

void Brick::makeVisible() {
    isBrickVisible = true;
}

void Brick::fallOneStepDown() {
    row += 1;
}
