#include "Brick.h"
#include "ConstructionSite.h"

#include <iostream>
#include <memory>
#include <sstream>

ConstructionSite::ConstructionSite(uint_fast32_t rows, uint_fast32_t columns) :
        rows(rows),
        columns(columns),
        // TODO calculate middle Y-coordinate (horizontal center) for Brick + adjust constructor for that matter for Brick class
        brick_1(std::make_unique<Brick>()),
        brick_2(std::make_unique<Brick>())
{
    // TODO adjustPlaygroundDimensions() - check if at least one brick_1 fits in the playground: rows is greater or equal than 3; columns are greater or equal than 3

    // TODO encapsulate to function reserveCapacity()
    playingField.resize(rows);
    for (auto& row : playingField) {
        row.resize(columns);
    }

    //TODO encapsulate to function initializePlayingField()
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
    if (brick_1->isVisible()) {
        showBrick1OnPlayingField();
    }

    if (brick_2->isVisible()) {
        showBrick2OnPlayingField();
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

void ConstructionSite::showBrick1OnPlayingField() {
    playingField
        .at(brick_1->getRow())
        .at(brick_1->getColumn())
        .assign(brick_1->getBrickSign());
}

void ConstructionSite::showBrick2OnPlayingField() {
    playingField
            .at(brick_2->getRow())
            .at(brick_2->getColumn())
            .assign(brick_2->getBrickSign());
}

void ConstructionSite::makeBrick1Visible() {
    brick_1->makeVisible();
}

void ConstructionSite::makeBrick2Visible() {
    brick_2->makeVisible();
}

uint_fast32_t ConstructionSite::bottomRowOfUsablePlayingArea() const {
    return this->rows - 2;
}

void ConstructionSite::moveBrick1Down() {
    playingField
        .at(brick_1->getRow())
        .at(brick_1->getColumn())
        .assign(BLANK);  // clearBrickFromPreviousPosition()

    if (this->brick_1->getRow() < this->bottomRowOfUsablePlayingArea() ) {
        this->brick_1->moveDown();
    }
}

void ConstructionSite::moveBrick2Down() {
    this->playingField
        .at(this->brick_2->getRow())
        .at(this->brick_2->getColumn())
        .assign(BLANK);

    if (this->brick_2->getRow() < this->bottomRowOfUsablePlayingArea()) {
        this->brick_2->moveDown();
    }
}

uint_fast32_t ConstructionSite::leftColumnOfUsablePlayingArea() const {
    return 1;
}

void ConstructionSite::moveBrick1Left() {
    playingField
        .at(brick_1->getRow())
        .at(brick_1->getColumn())
        .assign(BLANK);  // clearBrickFromPreviousPosition()

    if(this->brick_1->getColumn() > this->leftColumnOfUsablePlayingArea() ) {
        this->brick_1->moveLeft();
        this->brick_1->moveDown();
    }
}

uint_fast32_t ConstructionSite::rightColumnOfUsablePlayingArea() const {
    return this->columns - 2;
}

void ConstructionSite::moveBrick1Right() {
    playingField
            .at(brick_1->getRow())
            .at(brick_1->getColumn())
            .assign(BLANK);  // clearBrickFromPreviousPosition()

    if(this->brick_1->getColumn() < this->rightColumnOfUsablePlayingArea() ) {
        this->brick_1->moveRight();
        this->brick_1->moveDown();
    }
}
