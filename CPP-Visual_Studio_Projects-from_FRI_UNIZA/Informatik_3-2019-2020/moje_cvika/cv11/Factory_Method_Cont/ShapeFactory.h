#pragma once

#include <memory>

#include "Shape.h"
#include "ShapeType.h"

namespace ShapeCreation {
	class ShapeFactory
	{
	public:
		static std::unique_ptr<Shapes::Shape> createShape(ShapeType shapeType, double dimension);
	};
}
