#include "Game.h"

#include <chrono>
#include <thread>
#include <iostream>

Game::Game() :
//    constructionSite(std::make_unique<ConstructionSite>(3, 5))
//    constructionSite(std::make_unique<ConstructionSite>(5, 7))
    constructionSite(std::make_unique<ConstructionSite>(5, 6))
{}

void Game::startGame() {
//    clearTerminal();

    // TODO transform linear steps in Game into a for/while loop
    //while (true) {
        //loadInputFromTerminal();
        //recalculateGameLogic();
        //drawFrameOnTerminal();
        //clearTerminal();
    //}
//
//    drawFrameOnTerminal();
//    loadInputFromTerminal();
//    clearTerminal();

    // TODO at first when integrating the steps into the while loop make the brick_1 visible before entering the loop to make implementation easier
//    this->constructionSite->makeBrick1Visible();
//    this->drawFrameOnTerminal();
//    this->loadInputFromTerminal();
//    this->clearTerminal();

//    while (this->keyboardInputCharacters != "q") {
//        if (this->keyboardInputCharacters == "d") {
//            this->constructionSite->moveBrick1Down();
//        }
//        if (this->keyboardInputCharacters == "l") {
//            this->constructionSite->moveBrick1Left();
//        }
//        if (this->keyboardInputCharacters == "r") {
//            this->constructionSite->moveBrick1Right();
//        }
//
//        this->drawFrameOnTerminal();
//        this->loadInputFromTerminal();
//        this->clearTerminal();
//    }

    // INIT
    initGame();

    // BRICK 1
    this->loadInputFromTerminal();
    this->constructionSite->makeBrick1Visible();
    this->clearTerminal();
    this->drawFrameOnTerminal();

    this->loadInputFromTerminal();
    this->constructionSite->moveBrick1Down();
    this->clearTerminal();
    this->drawFrameOnTerminal();

    this->loadInputFromTerminal();
    this->constructionSite->moveBrick1Down();
    this->clearTerminal();
    this->drawFrameOnTerminal();

    this->loadInputFromTerminal();
    this->constructionSite->moveBrick1Down();
    this->clearTerminal();
    this->drawFrameOnTerminal();

    // FREEZE/ACTIVATE-CONDITION 1: brick_1 falls on the floor
    // if brick_1 reaches the bottom of the usable playing field
    // deactivate/freeze the current brick_1
    // and make another brick_1

    // BRICK 2
    this->loadInputFromTerminal();
    this->constructionSite->makeBrick2Visible();
    this->clearTerminal();
    this->drawFrameOnTerminal();

    this->loadInputFromTerminal();
    this->constructionSite->moveBrick2Down();
    this->clearTerminal();
    this->drawFrameOnTerminal();

    this->loadInputFromTerminal();
    this->constructionSite->moveBrick2Down();
    this->clearTerminal();
    this->drawFrameOnTerminal();

    this->loadInputFromTerminal();

    // FREEZE/ACTIVATE-CONDITION 2: two bricks are on top of each other
    // if brick_1 falls on another (deactivated?) brick_1
        // deactivate/freeze the current brick_1
        // and make another brick_1

    // TODO join FREEZE/ACTIVATE-CONDITIONs into one if-statement, because the body/behavior is the same in both cases

//    while (this->keyboardInputCharacters != "q") {
//        this->loadInputFromTerminal();
//
//          // more coherent: better overview of surrounding conditions BUT less intuitive, than when on the bottom: breaking chronology
////        if (this->constructionSite->isActiveBrickOnFloor() || this->constructionSite->isActiveBrickOnTopOfAnotherBrick() ) {
////            this->constructionSite->freezeActiveBrick();
////            this->constructionSite->createNewActiveBrick();
////            continue;
////        }
//        if (this->constructionSite->isActiveBrickHidden() ) {
//            this->constructionSite->makeActiveBrickVisible();
//            continue;
//        }
//        this->constructionSite->moveActiveBrickDown();
//
//        this->clearTerminal();
//        this->drawFrameOnTerminal();
//
//        // more intuitive because of chronology BUT less coherent: detached from the other check ''
//        if (this->constructionSite->isActiveBrickOnFloor() || this->constructionSite->isActiveBrickOnTopOfAnotherBrick() ) {
//            this->constructionSite->freezeActiveBrick();
//            this->constructionSite->createNewActiveBrick();
//        }
//    }
}

void Game::initGame() {
    clearTerminal();
    drawFrameOnTerminal();
//    loadInputFromTerminal();
}

void Game::loadInputFromTerminal() {
    std::cout << "enter command(s): ";
    std::cin >> this->keyboardInputCharacters;
    // TODO process input
};

void Game::recalculateGameLogic() {
    // TODO recalculate game logic according to the user's input
    // if brick_1 is not visible
        // make it visible
        // return / switch to other state?
    // if brick_1 is visible
        // put it down
        // return / switch to other state?
    // if brick_1 is deactivated
        // create a new brick_1/building block
        // return / switch to other state?
    // if there are consecutive lines in the ConstructionSite's playingField
        // remove them
        // rearrange the playingField by gravity
        // return / switch to other state?
}

void Game::drawFrameOnTerminal() const {
    std::cout << constructionSite->getCurrentPlayingField() << std::flush;
}

void Game::clearTerminal() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}
