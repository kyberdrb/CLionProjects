#pragma once

#include "Brick.h"

#include <memory>
#include <string>
#include <vector>

class ConstructionSite {
private:
    std::unique_ptr<Brick> brick;

    // TODO parametrize with args, i.e. "argv" and with constructor, and maybe add a setter to dynamically resize the playground during the game
    // TODO manually enlarge the playingField in order to test multiple descends and/or input commands - preparation for testing in a while loop
    static constexpr uint_fast32_t ROWS = 3;
    static constexpr uint_fast32_t  COLUMNS = 5;

    const std::string FLOOR = "‾"; // OVERLINE
    const std::string WALL = "|"; // PIPE
    const std::string BLANK = " "; // PIPE

    std::vector<std::vector<std::string>> playingField;

public:
    ConstructionSite(uint_fast32_t rows, uint_fast32_t columns);

    void makeBrickVisible();

    std::string getCurrentPlayingField();
    void addBrickToPlayingField();

    void moveBrickLower();
};
