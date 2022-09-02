#pragma once

//#define _USE_MATH_DEFINES
//#include <cmath>

//#include <math.h>
#include <corecrt_math_defines.h>

#include "Shape.h"

namespace Shapes {
	class Circle : public Shapes::Shape
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

		/*friend std::ostream& operator<<(std::ostream& out, const Circle& circle)
		{
			out << "Circle" << "\t";
			out << circle.radius << "\t";
			out << circle.calculateDiameter() << "\t";
			out << circle.calculateCircumfence() << "\t";
			out << circle.calculateArea();
			return out;
		}*/

		std::ostream& toString(std::ostream& out, const Shape& shape) const override
		{
			out << "Circle" << "\t";
			out << dynamic_cast<const Circle*>(&shape)->radius << "\t";
			out << dynamic_cast<const Circle*>(&shape)->calculateDiameter() << "\t";
			out << shape.calculateCircumfence() << "\t";
			out << shape.calculateArea();
			return out;
		}

		// prefix 'operator++', e.g. ++(*circle)
		Circle& operator++()
		{
			++(this->radius);
			return *this;
		}

		// postfix 'operator++', e.g. (*circle)++
		Circle operator++(int)
		{
			Circle previousCircle(*this);
			++(*this);
			return previousCircle;
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
		~Circle() override
		{
			std::cout << "Circle (Subclass) destroyed" << std::endl;
		}
	};
}