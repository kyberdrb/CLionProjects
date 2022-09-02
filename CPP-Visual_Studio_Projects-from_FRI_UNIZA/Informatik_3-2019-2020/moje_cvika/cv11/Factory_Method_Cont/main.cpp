#include <iostream>

#include <vector>

#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "ShapeFactory.h"

using namespace Shapes;
using namespace ShapeCreation;

int main()
{
	Circle* circle = new Circle(4);

	std::cout << (*circle).getRadius() << std::endl;

	delete circle;
	std::cout << std::endl;
	
	std::vector<std::unique_ptr<Shape>> shapes;

	shapes.emplace_back(ShapeFactory::createShape(ShapeType::CIRCLE, 5));
	shapes.emplace_back(ShapeFactory::createShape(ShapeType::SQUARE, 6));

	//for (const auto& shape : shapes)
	for (auto&& shape : shapes)
	{
		std::cout << std::endl;
		std::cout << "VTABLE pointer: " << shape << std::endl;
		std::cout << *shape << std::endl;
		std::cout << std::endl;

		// Dynamic cast returns nullptr at runtime when it doesn't find the overloaded
		//  virtual function in the subclass that we call after we dynamically
		//  casted the pointer of the base class
		Circle* circle = dynamic_cast<Circle*>(shape.get());
		if (circle != nullptr)
		{
			std::cout << *circle << std::endl;
			std::cout << ++(*circle) << std::endl;
			std::cout << (*circle)++ << std::endl;
			std::cout << *circle << std::endl;
		}

		Square* square = dynamic_cast<Square*>(shape.get());
		if (square != nullptr)
		{
			std::cout << *square << std::endl;
			std::cout << ++(*square) << std::endl;
			std::cout << (*square)++ << std::endl;
			std::cout << *square << std::endl;
		}
	}

	std::cout << std::endl;

	std::unique_ptr<Shape> shape;
	
	// We can't make an instance of the Shape class
	//  beacuse it's (pure) abstract class, i.e.
	//  it has at least one pure virtual function
	//std::unique_ptr<Shape> shape(new Shape());

	try
	{
		shape = std::make_unique<Square>(0);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
