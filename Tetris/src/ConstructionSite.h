#pragma once

#include "Brick.h"

#include <memory>
#include <string>
#include <vector>

class ConstructionSite {
private:
    uint_fast32_t rows;
    uint_fast32_t columns;
    std::unique_ptr<Brick> brick;
    std::vector<std::vector<std::string>> playingField;

    // TODO parametrize with args, i.e. "argv" and with constructor, and maybe add a setter to dynamically resize the playground during the game
    // TODO manually enlarge the playingField in order to test multiple descends and/or input commands - preparation for testing in a while loop
//    static constexpr uint_fast32_t ROWS = 3;
//    static constexpr uint_fast32_t  COLUMNS = 5;

    const std::string FLOOR = "‾"; // OVERLINE
    const std::string WALL = "|"; // PIPE
    const std::string BLANK = " "; // PIPE

public:
    ConstructionSite(uint_fast32_t rows, uint_fast32_t columns);

    uint_fast32_t getNumberOfRows() const;
    uint_fast32_t getNumberOfColumns() const;

    std::string getCurrentPlayingField();

    void makeBrickVisible();
    void moveBrickLower();

private:
    void addBrickToPlayingField();
};
