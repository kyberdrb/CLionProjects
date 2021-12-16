#include <Brick.h>
#include <ConstructionSite.h>

#include "gtest/gtest.h"

class TetrisTestSuite : public ::testing::Test {};

TEST_F(TetrisTestSuite, test_brick_character) {
    EXPECT_EQ("■", Brick().getBrickSign());
}

TEST_F(TetrisTestSuite, test_playingField) {
    uint_fast32_t rows = 3;
    uint_fast32_t columns = 5;
    auto constructionSite = std::make_unique<ConstructionSite>(rows, columns);
    EXPECT_EQ("|   |\n|   |\n‾‾‾‾‾\n", constructionSite->getCurrentPlayingField());
}
