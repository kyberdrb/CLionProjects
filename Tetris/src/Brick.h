#pragma once

#include <cstdint>
#include <string>

class Brick {
private:
    int_fast32_t row;
    int_fast32_t column;
    bool isBrickVisible;

public:
    Brick();

    int_fast32_t getRow() const;
    int_fast32_t getColumn() const;

    std::string getBrickSign() const;

    bool isVisible() const;
    void makeVisible();

    void fallOneStepDown();
};
