#include "ShapeFactory.h"
#include "Circle.h"
#include "Square.h"
#include "NullShape.h"

std::unique_ptr<Shape> ShapeFactory::create(ShapeType shapeType) {
    switch (shapeType) {
        case ShapeType::circle:
            return std::unique_ptr<Shape>(new Circle(.0));
        case ShapeType::square:
            return std::unique_ptr<Shape>(new Square(.0));
        case nullShape:
            return createNullShape();
    }
    return createNullShape();
}

std::unique_ptr<Shape> ShapeFactory::createNullShape() {
    return std::unique_ptr<Shape>(new NullShape());
}
