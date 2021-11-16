#include "Rectangle.h"
#include "Circle.h"
#include <iostream>

using namespace std;

void introduceShape(Shape*);
double calculateShapeArea(Shape*);
double calculateShapeCircumferece(Shape*);

int main()
{
    Shape* rectangle1 = new Rectangle(5,2);
    Shape* circle1 = new Circle(3);

    introduceShape(rectangle1);
    cout << "My area is: " << calculateShapeArea(rectangle1) << ", my circumference is: " << calculateShapeCircumferece(rectangle1) << endl << endl;

    introduceShape(circle1);
    cout << "My area is: " << calculateShapeArea(circle1) << ", my circumference is: " << calculateShapeCircumferece(circle1) << endl << endl;

    delete rectangle1;
    delete circle1;
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
