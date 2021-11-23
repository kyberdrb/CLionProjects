#include <Brick.h>
#include <ConstructionSite.h>

#include "gtest/gtest.h"

class TetrisTestSuite : public ::testing::Test {};

TEST_F(TetrisTestSuite, test_brick_character) {
    EXPECT_EQ("⎕", Brick().getBrickSign());
}

TEST_F(TetrisTestSuite, test_playground) {
    auto constructionSite = std::make_unique<ConstructionSite>();
    EXPECT_EQ("|   |\n|   |\n‾‾‾‾‾\n", constructionSite->getCurrentPlayground());
}
