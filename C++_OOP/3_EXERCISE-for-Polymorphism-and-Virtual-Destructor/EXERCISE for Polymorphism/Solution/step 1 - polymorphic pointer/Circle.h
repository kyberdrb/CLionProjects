#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include "Shape.h"

class Circle: public Shape
{
    double radius;
public:
    Circle(double);
    void introduce();
    double calculateArea();
    double calculateCircumference();
};


#endif // CIRCLE_H_INCLUDED
