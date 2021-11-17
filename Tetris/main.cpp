#include "src/Game.h"

#include <memory>

int main() {
    auto game = std::make_unique<Game>();
    game->runGame();

    return 0;
}
