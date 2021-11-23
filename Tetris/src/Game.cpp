#include "Game.h"

#include <chrono>
#include <thread>
#include <iostream>

Game::Game() :
    constructionSite(std::make_unique<ConstructionSite>())
{}

void Game::runGame() {
    clearTerminal();

    constructionSite->showFirstStep();
    waitForBrickDescent();
    clearTerminal();

    constructionSite->showSecondStep();
    waitForBrickDescent();
    clearTerminal();

    constructionSite->showFinalStep();
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

void Game::showConstructionSite() const {
    std::cout << constructionSite->getCurrentPlayground() << std::endl;
}
