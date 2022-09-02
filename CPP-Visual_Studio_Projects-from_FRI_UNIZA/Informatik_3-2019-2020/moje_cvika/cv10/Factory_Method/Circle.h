#pragma once

//#define _USE_MATH_DEFINES
//#include <cmath>

//#include <math.h>
#include <corecrt_math_defines.h>

#include "Shape.h"

class Circle : public Shape
{
private:
	double radius;

public:
	Circle(double radius = 1) : Shape()
	{
		if (radius <= 0)
		{
			throw std::invalid_argument("Negative dimensions");
		}
		std::cout << "Circle (Subclass) created" << std::endl;
		this->radius = radius;
	}

	double getRadius() const
	{
		return radius;
	}
	
	double calculateDiameter() const
	{
		return 2 * radius;
	}

	double calculateCircumfence() const override
	{
		return 2 * M_PI * radius;
	}

	double calculateArea() const override
	{
		return M_PI * pow(radius, 2);
	}

	//Circle()
	/*~Circle() override
	{
		std::cout << "Circle (Subclass) destroyed" << std::endl;
	}*/
	
	~Circle() override
	{
		std::cout << "Circle (Subclass) destroyed" << std::endl;
	}
};
