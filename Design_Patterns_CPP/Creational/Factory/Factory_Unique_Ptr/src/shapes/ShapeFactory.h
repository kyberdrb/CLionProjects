#pragma once

#include <bits/unique_ptr.h>
#include "Shape.h"
#include "ShapeType.h"

class ShapeFactory {
private:
    static std::unique_ptr<Shape> createNullShape();

public:
    // Make the Factory a Singleton by
    ShapeFactory() = delete;

    // The Singleton would also need to
    //  delete Copy Constructor and Copy Assignment Operator
    //ShapeFactory(const ShapeFactory&) = delete;
    //ShapeFactory& operator=(const ShapeFactory&) = delete;

    static std::unique_ptr<Shape> create(ShapeType shapeType);
};
