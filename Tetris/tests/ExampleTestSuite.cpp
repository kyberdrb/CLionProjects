#include <Brick.h>
#include "gtest/gtest.h"

class TetrisTestSuite : public ::testing::Test {};

TEST_F(TetrisTestSuite, test_brick_character) {
    EXPECT_EQ("⎕", Brick().showBrick());
}
