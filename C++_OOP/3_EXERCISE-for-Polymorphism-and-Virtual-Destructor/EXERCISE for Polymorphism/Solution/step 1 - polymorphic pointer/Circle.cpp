#include "Circle.h"
#include <iostream>
#define PI 3.14

Circle::Circle(double radius)
{
    this->radius = radius;
}
void Circle::introduce()
{
    std::cout << "I AM A CIRCLE !" << std::endl;
}
double Circle::calculateArea()
{
    return PI*radius*radius;
}
double Circle::calculateCircumference()
{
    return 2*PI*radius;
}
