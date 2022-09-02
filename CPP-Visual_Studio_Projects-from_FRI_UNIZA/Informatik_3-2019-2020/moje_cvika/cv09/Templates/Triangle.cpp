#include <iostream>
#include <sstream>

#include "Triangle.h"

Triangle::Triangle(const Triangle& sourceTriangle)
{
	this->sideA = new double(sourceTriangle.getSideA());
	this->sideB = sourceTriangle.getSideB();
	this->sideC = sourceTriangle.getSideC();
}

Triangle& Triangle::operator=(const Triangle& sourceTriangle)
{
	// self-assignment prevention
	if (this == &sourceTriangle) return *this;

	// deallocate resources from this instance beacuse it already exists
	delete this->sideA;
	
	this->sideA = new double(sourceTriangle.getSideA());

	this->sideB = sourceTriangle.getSideB();
	this->sideC = sourceTriangle.getSideC();
	return *this;
}


bool Triangle::isConstructible() const
{
	//*(this->sideA) and *this->sideA mean the same thing: dereference attribute 'sideA'
	double sumOfFirstTwoSides = *(this->sideA) + this->sideB;
	bool firstTwoSidesGreaterThanThird = sumOfFirstTwoSides > this->sideC;

	double sumOSecondTwoSides = this->sideB + this->sideC;
	bool secondTwoSidesGreaterThanFirst = sumOSecondTwoSides > *this->sideA;

	double sumOfThirdTwoSides = this->sideC + *this->sideA;
	bool thirdTwoSidesGreaterThanThird = sumOfThirdTwoSides > this->sideB;
	
	return
		firstTwoSidesGreaterThanThird && 
		secondTwoSidesGreaterThanFirst && 
		thirdTwoSidesGreaterThanThird;
}

std::string Triangle::printSides() const
{
	std::stringstream sides;
	sides << "a=" << *this->sideA << ", b=" << this->sideB << ", c=" << this->sideC << "\t";// << "\n";
	return sides.str();
}