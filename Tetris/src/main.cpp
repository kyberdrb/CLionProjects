#include "Game.h"

#include <memory>

int main() {
    auto game = std::make_unique<Game>();
    game->startGame();

    return 0;
}
