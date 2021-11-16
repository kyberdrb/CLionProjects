#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double width, double height)
{
    this->width = width;
    this->height = height;
}
void Rectangle::introduce()
{
    std::cout << "I AM A RECTANGLE !" << std::endl;
}
double Rectangle::calculateArea()
{
    return width*height;
}
double Rectangle::calculateCircumference()
{
    return 2*(width+height);
}
