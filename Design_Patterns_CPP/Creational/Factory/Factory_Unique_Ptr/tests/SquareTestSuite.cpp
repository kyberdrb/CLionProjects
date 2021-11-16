#include <shapes/Square.h>
#include "shapes/Shape.h"
#include "shapes/ShapeFactory.h"
#include "gtest/gtest.h"

class SquareTestSuite : public ::testing::Test {
protected:
    std::unique_ptr<Shape> square{nullptr};

    void SetUp() override {
        square = ShapeFactory::create(ShapeType::square);
    }
};

TEST_F(SquareTestSuite, test_square_exists) {
    EXPECT_NE(nullptr, square);
}

TEST_F(SquareTestSuite, square_side_is_0) {
    Square* castedSquare = dynamic_cast<Square*>(square.get());
    EXPECT_EQ(.0, castedSquare->getSide());
}
