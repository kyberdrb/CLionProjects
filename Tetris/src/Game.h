#pragma once

#include "ConstructionSite.h"

#include <memory>

class Game {
public:
    std::unique_ptr<ConstructionSite> constructionSite;

    Game();

    void runGame();
    void clearTerminal();
    void waitForBrickDescent();
    void showConstructionSite() const;
};
