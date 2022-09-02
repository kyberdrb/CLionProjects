#pragma once

#include <cmath>
#include <ostream>

class Triangle
{
	double* sideA;
	double sideB;
	double sideC;

public:
	Triangle(
			double a = 1,
			double b = 1,
			double c = sqrt(2))
		:
		sideA(new double{a}),
		sideB(b),
		sideC(c)
	{}

	~Triangle()
	{
		delete sideA;
	}

	Triangle			(const Triangle& sourceTriangle);
	Triangle& operator=	(const Triangle& sourceTriangle);

	double getSideA() const
	{
		return *sideA;
	}

	double getSideB() const
	{
		return sideB;
	}

	double getSideC() const
	{
		return sideC;
	}

	void setSideA(double a)
	{
		*sideA = a;
	}

	void setSideB(double b)
	{
		sideB = b;
	}

	void setSideC(double c)
	{
		sideC = c;
	}

	bool isConstructible() const;

	std::string printSides() const;
	
	friend std::ostream& operator<<(std::ostream& os, const Triangle& triangle)
	{
		os << "a=" << *triangle.sideA << ", b=" << triangle.sideB << ", c=" << triangle.sideC << "\t" << triangle.isConstructible();
		return os;
	}
};
