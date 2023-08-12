#pragma once

#include <cstdint>
#include <string>

class Brick {
private:
    int_fast32_t row;
    int_fast32_t column;
    bool isBrickVisible;
    bool isBrickActive;

public:
    Brick();

    int_fast32_t getRow() const;
    int_fast32_t getColumn() const;

    std::string getBrickSign() const;

    bool isVisible() const;
    void makeVisible();

    bool isActive();
    void deactivate();

    void moveDown();
    void moveLeft();
    void moveRight();
};
