#pragma once

#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "ShapeType.h"

class ShapeFactory
{
public:
	static Shape* createShape(ShapeType shapeType, double dimension);
};
