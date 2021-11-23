#include "Brick.h"
#include "ConstructionSite.h"

#include <iostream>
#include <memory>
#include <sstream>

ConstructionSite::ConstructionSite() :
    brick(std::make_unique<Brick>())
{}

void ConstructionSite::showFirstStep() {
    std::cout << "ConstructionSite (stavenisko - hracia plocha)" << std::endl;
    std::cout << std::endl;

    std::cout<< getCurrentPlayground() << std::flush;
}

void ConstructionSite::showSecondStep() {
    std::cout << "Brick (one part of a Tetromino - tehlička)" << std::endl;
    std::cout << std::endl;

    brick->makeVisible();
    std::cout<< getCurrentPlayground() << std::flush;
}
void ConstructionSite::showFinalStep() {
    std::cout << "Brick has fallen to the bottom - this brick stops moving and next brick starts falling" << std::endl;
    std::cout << std::endl;

    moveBrickOneStepDown();
    std::cout<< getCurrentPlayground() << std::flush;
}

std::string ConstructionSite::getCurrentPlayground() {
    if (brick->isVisible()) {
        showBrick();
    }

    std::stringstream buffer{};
    for (int row = 0; row < ROWS; ++row) {
        for (int column = 0; column < COLUMNS; ++column) {
            buffer << playground[row][column];
        }
        buffer << "\n";
    }
    return buffer.str();
}

void ConstructionSite::showBrick() {
    playground[brick->getRow()][brick->getColumn()] = brick->getBrickSign();
}

void ConstructionSite::moveBrickOneStepDown() {
    playground[brick->getRow()][brick->getColumn()] = " ";  // clearBrickFromPreviousPosition
    brick->fallOneStepDown();
}
