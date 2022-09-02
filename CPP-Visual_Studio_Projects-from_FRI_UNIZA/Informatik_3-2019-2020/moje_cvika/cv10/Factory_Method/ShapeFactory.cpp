#include "ShapeFactory.h"
#include "Circle.h"
#include "Square.h"

Shape* ShapeFactory::createShape(ShapeType shapeType, double dimension)
{
	switch (shapeType) {
	case ShapeType::CIRCLE:
	{
		return new Circle(dimension);
	}
	case ShapeType::SQUARE:
	{
		return new Square(dimension);
	}
	}
	return nullptr;
}
