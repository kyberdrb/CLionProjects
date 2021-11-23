#pragma once

#include "Brick.h"

#include <string>
#include <memory>

class ConstructionSite {
private:
    std::unique_ptr<Brick> brick;

public:
    static constexpr uint_fast32_t ROWS = 3;
    static constexpr uint_fast32_t  COLUMNS = 5;

    const std::string FLOOR = "‾"; // OVERLINE
    const std::string WALL = "|"; // PIPE

    std::string playground[ROWS][COLUMNS] = {
            {WALL, " ", " ", " ", WALL},
            {WALL,  " ", " ", " ", WALL},
            {FLOOR, FLOOR, FLOOR, FLOOR, FLOOR}
    };

    ConstructionSite();

    void showFirstStep();
    void showSecondStep();
    void showFinalStep();

    std::string getCurrentPlayground();
    void showBrick();
    void moveBrickOneStepDown();
};
