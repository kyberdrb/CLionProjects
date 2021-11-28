#include "Game.h"

#include <chrono>
#include <thread>
#include <iostream>

Game::Game() :
    constructionSite(std::make_unique<ConstructionSite>(3, 5))
{}

void Game::runGame() {
    clearTerminal();

    // TODO transform linear steps in Game into a for/while loop
    //while (true) {
        //loadInputFromTerminal();
        //recalculateGameLogic();
        //drawFrameOnTerminal();
        //clearTerminal();
    //}

    drawFrameOnTerminal();
    waitForBrickDescent();
    clearTerminal();

    constructionSite->makeBrickVisible();
    drawFrameOnTerminal();
    waitForBrickDescent();
    clearTerminal();

    constructionSite->moveBrickLower(); // loadInputFromTerminal()
    drawFrameOnTerminal();
}

void Game::clearTerminal() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void Game::waitForBrickDescent() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
};

void Game::drawFrameOnTerminal() const {
    std::cout << constructionSite->getCurrentPlayingField() << std::flush;
}
