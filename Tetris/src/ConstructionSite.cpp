#include "Brick.h"
#include "ConstructionSite.h"

#include <iostream>
#include <memory>
#include <sstream>

void ConstructionSite::showFirstStep() {
    std::cout << "ConstructionSite (stavenisko - hracia plocha)" << std::endl;
    std::cout << std::endl;

    std::cout << "|   |" << std::endl;
    std::cout << "|   |" << std::endl;
    std::cout << "‾‾‾‾‾" << std::endl;
}

void ConstructionSite::showSecondStep() {
    std::cout << "Brick (one part of a Tetromino - tehlička)" << std::endl;
    std::cout << std::endl;

    auto brick = std::make_unique<Brick>();

    std::cout << "| " << brick->showBrick() << " |" << std::endl;
    std::cout << "|   |" << std::endl;
    std::cout << "‾‾‾‾‾" << std::endl;
}
void ConstructionSite::showFinalStep() {
    std::cout << "Brick has fallen to the bottom - this brick stops moving and next brick starts falling" << std::endl;
    std::cout << std::endl;

    auto brick = std::make_unique<Brick>();

    std::cout << "|   |" << std::endl;
    std::cout << "| " << brick->showBrick() << " |" << std::endl;
    std::cout << "‾‾‾‾‾" << std::endl;
}

std::string ConstructionSite::getCurrentPlayground() const {
    std::stringstream buffer{};
    for (int row = 0; row < 2; ++row) {
        for (int column = 0; column < 2; ++column) {
            buffer << playground[row][column];
            buffer << " ";
        }
        buffer << "\n";
    }
    return buffer.str();
}
