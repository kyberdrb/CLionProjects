#include "Brick.h"
#include "ConstructionSite.h"

#include <iostream>
#include <memory>
#include <sstream>

ConstructionSite::ConstructionSite(uint_fast32_t rows, uint_fast32_t columns) :
        brick(std::make_unique<Brick>())
{
    //reserveCapacity()
    playingField.resize(rows);
    for (auto& row : playingField) {
        row.resize(columns);
    }

    //initializePlayingField()
    uint_fast32_t forelastRowIndex = rows - 2;
    for (uint_fast32_t row = 0; row <= forelastRowIndex; ++row) {
        for (uint_fast32_t column = 0; column < columns; ++column) {
            //check first and forelast column - fill them with WALL character
            if (column == 0 || column == columns - 1) {
                playingField.at(row).at(column) = WALL;
                continue;
            }

            //fill the rest with BLANK character
            playingField.at(row).at(column) = BLANK;
        }
    }

    //iterate the last line in a separate loop - fill it with FLOOR character
    uint_fast32_t lastRowIndex = rows - 1;
    auto& lastRow = playingField.at(lastRowIndex);
    for (int column = 0; column < columns; ++column) {
        lastRow.at(column).assign(FLOOR);
    }
}

void ConstructionSite::makeBrickVisible() {
    brick->makeVisible();
}

std::string ConstructionSite::getCurrentPlayingField() {
    if (brick->isVisible()) {
        addBrickToPlayingField();
    }

    std::stringstream buffer;
    for (const auto& row : playingField) {
        for (const auto& column : row) {
            buffer << column;
        }
        buffer << "\n";
    }
    return buffer.str();
}

void ConstructionSite::addBrickToPlayingField() {
    playingField.at(brick->getRow()).at(brick->getColumn()).assign(brick->getBrickSign());
}

void ConstructionSite::moveBrickLower() {
    playingField.at(brick->getRow()).at(brick->getColumn()).assign(BLANK);  // clearBrickFromPreviousPosition()
    brick->fallOneStepDown();
}
