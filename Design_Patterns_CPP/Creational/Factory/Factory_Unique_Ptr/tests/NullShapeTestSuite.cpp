#include <shapes/Square.h>
#include "shapes/Shape.h"
#include "shapes/ShapeFactory.h"
#include "gtest/gtest.h"

class NullShapeTestSuite : public ::testing::Test {
protected:
    std::unique_ptr<Shape> nullShape{nullptr};

    void SetUp() override {
        nullShape = ShapeFactory::create(ShapeType::nullShape);
    }
};

TEST_F(NullShapeTestSuite, test_nullshape_exists) {
    EXPECT_NE(nullptr, nullShape);
}
