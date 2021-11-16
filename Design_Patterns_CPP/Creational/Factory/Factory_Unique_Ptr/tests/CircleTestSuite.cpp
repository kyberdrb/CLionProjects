#include <shapes/Circle.h>
#include <shapes/ShapeType.h>
#include "shapes/Shape.h"
#include "shapes/ShapeFactory.h"
#include "gtest/gtest.h"

class CircleTestSuite : public ::testing::Test {
protected:
    std::unique_ptr<Shape> circle{nullptr};

    void SetUp() override {
        circle = ShapeFactory::create(ShapeType::circle);
    }
};

TEST_F(CircleTestSuite, test_circle_exists) {
    EXPECT_NE(nullptr, circle);
}

TEST_F(CircleTestSuite, circle_radius_is_0) {
    Circle *castedCircle = dynamic_cast<Circle*>(circle.get());
    EXPECT_EQ(.0, castedCircle->getRadius());
}

TEST_F(CircleTestSuite, circle_diameter_is_0) {
    Circle *castedCircle = dynamic_cast<Circle*>(circle.get());
    EXPECT_EQ(.0, castedCircle->calculateDiameter());
}
