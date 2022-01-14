#pragma once

#include "ConstructionSite.h"

#include <memory>

class Game {
private:
    std::unique_ptr<ConstructionSite> constructionSite;
    std::string keyboardInputCharacters;

public:
    Game();

    void startGame();

private:
    void loadInputFromTerminal();
    void recalculateGameLogic();
    void clearTerminal();
    void drawFrameOnTerminal() const;
};
