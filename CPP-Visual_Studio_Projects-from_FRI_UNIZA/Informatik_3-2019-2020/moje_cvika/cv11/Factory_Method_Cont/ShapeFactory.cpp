#include "ShapeFactory.h"
#include "Circle.h"
#include "Square.h"

using namespace Shapes;

namespace ShapeCreation {
	std::unique_ptr<Shape> ShapeFactory::createShape(ShapeType shapeType, double dimension)
	{
		switch (shapeType) {
		case ShapeType::CIRCLE:
		{
			return std::make_unique<Circle>(dimension);
		}
		case ShapeType::SQUARE:
		{
			return std::make_unique<Square>(dimension);
		}
		}
		return nullptr;
	}
}