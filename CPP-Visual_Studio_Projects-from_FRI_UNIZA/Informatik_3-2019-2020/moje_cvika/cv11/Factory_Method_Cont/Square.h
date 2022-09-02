#pragma once

#include "Shape.h"

class Square : public Shapes::Shape
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

	/*friend std::ostream& operator<<(std::ostream& out, const Square& square)
	{
		out << "Square" << "\t";
		out << square.side << "\t";
		out << square.calculateCircumfence() << "\t";
		out << square.calculateArea();
		return out;
	}*/

	std::ostream& toString(std::ostream& out, const Shape& shape) const override
	{
		out << "Square" << "\t";
		out << dynamic_cast<const Square*>(&shape)->side << "\t";
		out << shape.calculateCircumfence() << "\t";
		out << shape.calculateArea();
		return out;
	}

	// prefix 'operator++', e.g. ++(*square)
	Square& operator ++()
	{
		++(this->side);
		return *this;
	}

	// postfix 'operator++', e.g. (*square)++
	Square operator ++(int)
	{
		Square previousSquare(*this);
		++(*this);
		return previousSquare;
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
