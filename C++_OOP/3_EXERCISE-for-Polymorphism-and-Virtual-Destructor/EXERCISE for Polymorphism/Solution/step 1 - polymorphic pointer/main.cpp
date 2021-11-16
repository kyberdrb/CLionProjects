#include "Rectangle.h"
#include "Circle.h"
#include <iostream>

using namespace std;

void introduceShape(Shape*);
double calculateShapeArea(Shape*);
double calculateShapeCircumferece(Shape*);

int main()
{

    Rectangle rectangle1(5,2);
    Circle circle1(3);

    introduceShape(&rectangle1);
    cout << "My area is: " << calculateShapeArea(&rectangle1) << ", my circumference is: " << calculateShapeCircumferece(&rectangle1) << endl << endl;

    introduceShape(&circle1);
    cout << "My area is: " << calculateShapeArea(&circle1) << ", my circumference is: " << calculateShapeCircumferece(&circle1) << endl;

    return 0;
}

void introduceShape(Shape* shapeToIntroduce)
{
    return shapeToIntroduce->introduce();
}

double calculateShapeArea(Shape* shapeToCalculate)
{
    return shapeToCalculate->calculateArea();
}

double calculateShapeCircumferece(Shape* shapeToCalculate)
{
    return shapeToCalculate->calculateCircumference();
}
