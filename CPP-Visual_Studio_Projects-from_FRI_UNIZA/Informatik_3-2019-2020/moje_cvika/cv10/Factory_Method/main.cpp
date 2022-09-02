#include <iostream>

#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "ShapeFactory.h"

int main()
{
	Shape* shape = nullptr;
	
	//C++99
	//shape = new Circle(5);

	// 'createCircle' method in ShapeFactory is a static method,
	//  not instance method. Therefore we can't access the method via '.' ...
	//shape = ShapeFactory.createCircle();

	// ... we use the scope operator '::'
	//shape = ShapeFactory::createShape(0, 5);
	shape = ShapeFactory::createShape(ShapeType::CIRCLE, 5);

	std::cout << shape->calculateCircumfence() << std::endl;
	std::cout << shape->calculateArea() << std::endl;
	std::cout << dynamic_cast<Circle*>(shape)->getRadius() << std::endl;
	std::cout << dynamic_cast<Circle*>(shape)->calculateDiameter() << std::endl;
	
	// C++11
	//std::unique_ptr<Shape> circle(new Circle(5));

	// Access to specific subclass functions that are 
	//Circle* concreteCircle = dynamic_cast<Circle*>(circle.get());
	//std::cout << concreteCircle->getDiameter() << std::endl;

	delete shape;
	shape = nullptr;
	
	std::cout << std::endl;

	//shape = new Square(6);
	//shape = ShapeFactory::createShape(1, 6);
	shape = ShapeFactory::createShape(ShapeType::SQUARE, 6);
	
	std::cout << shape->calculateCircumfence() << std::endl;
	std::cout << shape->calculateArea() << std::endl;
	std::cout << dynamic_cast<Square*>(shape)->getSide() << std::endl;
	
	// C++14
	//std::unique_ptr<Shape> square(std::make_unique<Square>());

	delete shape;
	shape = nullptr;

	// We can't make an instance of the Shape class
	//  beacuse it's (pure) abstract, i.e.
	//  it has at least one pure virtual function
	//shape = new Shape();
	
	std::cout << std::endl;

	try
	{
		shape = new Square(0);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
		shape = nullptr;
	}
	
	delete shape;
	
	return 0;
}
