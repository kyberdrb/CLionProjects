#pragma once

#include "ConstructionSite.h"

#include <memory>

class Game {
private:
    std::unique_ptr<ConstructionSite> constructionSite;

public:
    Game();

    void runGame();
    void clearTerminal();
    void waitForBrickDescent();
    void drawFrameOnTerminal() const;
};
