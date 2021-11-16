#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

class Shape
{
    public:
        virtual void introduce() = 0;
        virtual double calculateArea() = 0;
        virtual double calculateCircumference() = 0;
};

#endif // SHAPE_H_INCLUDED
