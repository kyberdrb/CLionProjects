#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include "Shape.h"

class Rectangle: public Shape
{
    double width;
    double height;
public:
    Rectangle(double, double);
    void introduce();
    double calculateArea();
    double calculateCircumference();

};


#endif // RECTANGLE_H_INCLUDED
