#pragma once

#include "Brick.h"

#include <memory>
#include <string>
#include <vector>

class ConstructionSite {
public:
    ConstructionSite(uint_fast32_t rows, uint_fast32_t columns);

    uint_fast32_t getNumberOfRows() const;
    uint_fast32_t getNumberOfColumns() const;

    std::string getCurrentPlayingField();

    void makeBrickVisible();
    void makeBrick2Visible();

    void moveBrickDown();
    void moveBrick2Down();

    void moveActiveBrickLeft();
    void moveActiveBrickRight();

private:
    uint_fast32_t rows;
    uint_fast32_t columns;

    std::unique_ptr<Brick> brick;
    std::unique_ptr<Brick> brick_2;

    std::vector<std::vector<std::string>> playingField;

    // TODO parametrize with args, i.e. "argv" and with constructor, and maybe add a setter to dynamically resize the playground during the game
    // TODO manually enlarge the playingField in order to test multiple descends and/or input commands - preparation for testing in a while loop
//    static constexpr uint_fast32_t ROWS = 3;
//    static constexpr uint_fast32_t  COLUMNS = 5;

    const std::string FLOOR = "‾"; // OVERLINE
    const std::string WALL = "|"; // PIPE
    const std::string BLANK = " "; // PIPE

    void addBrickToPlayingField();
    void addBrick2ToPlayingField();

    uint_fast32_t bottomRowOfUsablePlayingArea() const;
    uint_fast32_t leftColumnOfUsablePlayingArea() const;
    uint_fast32_t rightColumnOfUsablePlayingArea() const;
};
