#pragma once

#include <iostream>

namespace Shapes {
	class Shape
	{
	public:
		friend std::ostream& operator<<(std::ostream& out, const Shape& shape)
		{
			return shape.toString(out, shape);
		};

		virtual std::ostream& toString(std::ostream& out, const Shape& shape) const = 0;
		
		//virtual Shape& operator++() = 0;
		
		virtual double calculateCircumfence() const = 0;
		virtual double calculateArea() const = 0;

		// Why destructor of base class should always be virtual?
		// What would happen if it wasn't?
		//  The table of virtual functions, VTABLE, for the destructor function
		//  in the subclass won't be looked up.
		//  Only the destructor of the base class will be called
		//  which means, we get a memory leak.
		//~Shape()
		virtual ~Shape()
		{
			std::cout << "Shape (Base Class) destroyed" << std::endl;
		}

		// Default destructor: C++11
		//virtual ~Shape() = default;		// the same as in C++99: virtual ~Shape() {};

		// What would happen if the destructor was pure virtual,
		//  i.e. 'virtual ~Shape() = 0;'?
	};
}