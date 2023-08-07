#include "Brick.h"
#include "ConstructionSite.h"

#include <iostream>
#include <memory>
#include <sstream>

ConstructionSite::ConstructionSite(uint_fast32_t rows, uint_fast32_t columns) :
        rows(rows),
        columns(columns),
        // TODO calculate middle Y-coordinate (horizontal center) for Brick + adjust constructor for that matter for Brick class
        brick(std::make_unique<Brick>())
{
    // TODO adjustPlaygroundDimensions() - check if at least one brick fits in the playground: rows is greater or equal than 3; columns are greater or equal than 3

    // TODO encapsulate to function reserveCapacity()
    playingField.resize(rows);
    for (auto& row : playingField) {
        row.resize(columns);
    }

    //TODO TODO encapsulate to function initializePlayingField()
    uint_fast32_t forelastRowIndex = rows - 2;
    for (uint_fast32_t row = 0; row <= forelastRowIndex; ++row) {
        for (uint_fast32_t column = 0; column < columns; ++column) {
            // check first and forelast column - fill them with WALL character
            // TODO encapsulate condition to 'bool isSideBorder = isLeftBorder || isRightBorder;
            bool isLeftBorder = column == 0;
            bool isRightBorder = column == columns - 1;
            bool isSideBorder = isLeftBorder || isRightBorder;
            if (isSideBorder) {
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

uint_fast32_t ConstructionSite::getNumberOfRows() const {
    return this->rows;
}
uint_fast32_t ConstructionSite::getNumberOfColumns() const {
    return this->columns;
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
    playingField
        .at(brick->getRow())
        .at(brick->getColumn())
        .assign(brick->getBrickSign());
}

void ConstructionSite::makeBrickVisible() {
    brick->makeVisible();
}

uint_fast32_t ConstructionSite::bottomRowOfUsablePlayingArea() const {
    return this->rows - 2;
}

void ConstructionSite::moveActiveBrickLower() {
    playingField
        .at(brick->getRow())
        .at(brick->getColumn())
        .assign(BLANK);  // clearBrickFromPreviousPosition()

    if (this->brick->getRow() < this->bottomRowOfUsablePlayingArea() ) {
        this->brick->fallOneStepDown();
    }
}

uint_fast32_t ConstructionSite::leftColumnOfUsablePlayingArea() const {
    return 1;
}

void ConstructionSite::moveActiveBrickLeft() {
    playingField
        .at(brick->getRow())
        .at(brick->getColumn())
        .assign(BLANK);  // clearBrickFromPreviousPosition()

    if(this->brick->getColumn() > this->leftColumnOfUsablePlayingArea() ) {
        this->brick->moveLeft();
    }
}

uint_fast32_t ConstructionSite::rightColumnOfUsablePlayingArea() const {
    return this->columns - 2;
}

void ConstructionSite::moveActiveBrickRight() {
    playingField
            .at(brick->getRow())
            .at(brick->getColumn())
            .assign(BLANK);  // clearBrickFromPreviousPosition()

    if(this->brick->getColumn() < this->rightColumnOfUsablePlayingArea() ) {
        this->brick->moveRight();
    }
}
