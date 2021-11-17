#include "Brick.h"
#include "ConstructionSite.h"

#include <iostream>
#include <memory>

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
