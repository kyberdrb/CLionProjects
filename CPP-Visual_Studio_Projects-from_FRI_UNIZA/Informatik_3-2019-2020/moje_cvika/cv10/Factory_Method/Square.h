#pragma once

#include "Shape.h"

class Square : public Shape
{
private:
	double side;

public:
	Square(double side = 1) : Shape()
	{
		if (side <= 0)
		{
			throw std::invalid_argument("Negative dimensions");
		}
		std::cout << "Square (Subclass) created" << std::endl;
		this->side = side;
	}


	double getSide() const
	{
		return side;
	}

	double calculateCircumfence() const override
	{
		return 4 * side;
	}

	double calculateArea() const override
	{
		return side * side;
	}

	//~Square()
	~Square() override
	{
		std::cout << "Square (Subclass) destroyed" << std::endl;
	}
};
