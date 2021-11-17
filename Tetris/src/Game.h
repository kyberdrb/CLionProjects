#pragma once

class Game {
public:
    Game() = default;

    void runGame();
    void clearTerminal();
    void waitForBrickDescent();
};
