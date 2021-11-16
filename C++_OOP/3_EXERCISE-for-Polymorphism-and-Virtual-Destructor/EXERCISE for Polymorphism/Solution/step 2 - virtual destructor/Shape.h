#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED
#include <iostream>

class Shape
{
    public:
        virtual ~Shape() {std::cout << "Shape destructor !" << std::endl;};
        virtual void introduce() = 0;
        virtual double calculateArea() = 0;
        virtual double calculateCircumference() = 0;
};

#endif // SHAPE_H_INCLUDED
