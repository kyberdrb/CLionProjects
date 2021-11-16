#include "shapes/square/Square.h"
#include "shapes/rectangle/Rectangle.h"
#include "shapes/circle/Circle.h"

#include <iostream>
#include <cassert>
#include <iomanip>
#include <memory>
#include <cmath>

int main() {
    square::SquareDimension squareDimension(3);
    square::Square square(&squareDimension);

    std::cout << "Square - side:" << std::setw(13) << squareDimension.getSide() << std::endl;
    assert(squareDimension.getSide() == 3);

    std::cout << "Square - area:" << std::setw(13) << square.calculateArea() << std::endl;
    assert(square.calculateArea() == 9);

    std::cout << "Square - circumference:" << std::setw(4) << square.calculatecircumference() << std::endl;
    assert(square.calculatecircumference() == 12);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    square::SquareDimension newSquareDimension(5);
    square.changeDimension(&newSquareDimension);
    std::cout << "Square - side:" << std::setw(13) << newSquareDimension.getSide() << std::endl;
    assert(newSquareDimension.getSide() == 5);

    std::cout << "Square - area:" << std::setw(13) << square.calculateArea() << std::endl;
    assert(square.calculateArea() == 25);

    std::cout << "Square - circumference:" << std::setw(4) << square.calculatecircumference() << std::endl;
    assert(square.calculatecircumference() == 20);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    rectangle::RectangleDimension rectangleDimension(2, 3);
    rectangle::Rectangle rectangle(&rectangleDimension);

    std::cout << "Rectangle - sideA:" << std::setw(13) << rectangleDimension.getSideA() << std::endl;
    assert(rectangleDimension.getSideA() == 2);

    std::cout << "Rectangle - sideB:" << std::setw(13) << rectangleDimension.getSideB() << std::endl;
    assert(rectangleDimension.getSideB() == 3);

    std::cout << "Rectangle - area:" << std::setw(14) << rectangle.calculateArea() << std::endl;
    assert(rectangle.calculateArea() == 6);

    std::cout << "Rectangle - circumference:" << std::setw(5) << rectangle.calculatecircumference() << std::endl;
    assert(rectangle.calculatecircumference() == 10);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    rectangle::RectangleDimension newRectangleDimension(4, 5);
    rectangle.changeDimension(&newRectangleDimension);

    std::cout << "Rectangle - sideA:" << std::setw(13) << newRectangleDimension.getSideA() << std::endl;
    assert(newRectangleDimension.getSideA() == 4);

    std::cout << "Rectangle - sideB:" << std::setw(13) << newRectangleDimension.getSideB() << std::endl;
    assert(newRectangleDimension.getSideB() == 5);

    std::cout << "Rectangle - area:" << std::setw(14) << rectangle.calculateArea() << std::endl;
    assert(rectangle.calculateArea() == 20);

    std::cout << "Rectangle - circumference:" << std::setw(5) << rectangle.calculatecircumference() << std::endl;
    assert(rectangle.calculatecircumference() == 18);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    auto circleDimension = std::make_unique<circle::CircleDimension>(4);
    auto circle = std::make_unique<circle::Circle>(circleDimension.get());

    std::cout << "Circle - radius:" << std::setw(13) << circleDimension->getRadius() << std::endl;
    assert(circleDimension->getRadius() == 4);

    std::cout << "Circle - diameter:" << std::setw(11) << circle->calculateDiameter() << std::endl;
    assert(circle->calculateDiameter() == 8);

    std::cout << "Circle - area:\t" << std::fixed << std::setprecision(44) << circle->calculateArea() << std::endl;
    assert(circle->calculateArea() == 50.26548245743668985596741549670696258544921875);

    std::cout << "Circle - circumference:\t" << std::fixed << std::setprecision(44) << circle->calculatecircumference() << std::endl;
    assert(circle->calculatecircumference() == 25.13274122871834492798370774835348129272460938);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    auto newCircleDimension = std::make_unique<circle::CircleDimension>(1/M_PI);
    circle->changeDimension(newCircleDimension.get());

    std::cout << "Circle - radius:\t" << std::fixed << std::setprecision(44) << newCircleDimension->getRadius() << std::endl;
    assert(newCircleDimension->getRadius() == 0.31830988618379069121644420192751567810773849);

    std::cout << "Circle - diameter:\t" << std::fixed << std::setprecision(44) << circle->calculateDiameter() << std::endl;
    assert(circle->calculateDiameter() == .63661977236758138243288840385503135621547699);

    std::cout << "Circle - area:\t" << std::fixed << std::setprecision(44) << circle->calculateArea() << std::endl;
    assert(circle->calculateArea() == 0.31830988618379069121644420192751567810773849);

    std::cout << "Circle - circumference:\t" << std::fixed << std::setprecision(0) << circle->calculatecircumference() << std::endl;
    assert(circle->calculatecircumference() == 2);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    std::unique_ptr<shapes::Shape<circle::CircleDimension, circle::Circle>> anotherCircle =
        std::make_unique<circle::Circle>(circleDimension.get());

    std::cout << "Circle - radius:" << std::setw(13) << circleDimension->getRadius() << std::endl;
    assert(circleDimension->getRadius() == 4);

    std::cout << "Circle - diameter:" << std::setw(11) << anotherCircle->getShape()->calculateDiameter() << std::endl;
    assert(anotherCircle->getShape()->calculateDiameter() == 8);

    std::cout << "Circle - area:\t" << std::fixed << std::setprecision(44) << anotherCircle->calculateArea() << std::endl;
    assert(anotherCircle->calculateArea() == 50.26548245743668985596741549670696258544921875);

    std::cout << "Circle - circumference:\t" << std::fixed << std::setprecision(44) << anotherCircle->calculatecircumference() << std::endl;
    assert(anotherCircle->calculatecircumference() == 25.13274122871834492798370774835348129272460938);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    circle->changeDimension(circleDimension.get());

    std::cout << std::setprecision(0);

    std::cout << "Circle - radius:" << std::setw(11) << circleDimension->getRadius() << std::endl;
    assert(circleDimension->getRadius() == 4);

    std::cout << "Circle - diameter:" << std::setw(9) << circle->calculateDiameter() << std::endl;
    assert(circle->calculateDiameter() == 8);

    std::cout << "Circle - area:\t" << std::fixed << std::setprecision(44) << circle->calculateArea() << std::endl;
    assert(circle->calculateArea() == 50.26548245743668985596741549670696258544921875);

    std::cout << "Circle - circumference:\t" << std::fixed << std::setprecision(44) << circle->calculatecircumference() << std::endl;
    assert(circle->calculatecircumference() == 25.13274122871834492798370774835348129272460938);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    square::Square copiedSquare(square);
    std::cout << std::setprecision(0);
    std::cout << square.getDimension() << std::endl;
    std::cout << copiedSquare.getDimension() << std::endl;
    std::cout << square.getDimension()->getSide() << std::endl;
    std::cout << copiedSquare.getDimension()->getSide() << std::endl;

    std::cout << std::endl;

    copiedSquare.changeDimension(&squareDimension);
    std::cout << square.getDimension()->getSide() << std::endl;
    std::cout << copiedSquare.getDimension()->getSide() << std::endl;

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    auto squareDimensionOnHeap = new square::SquareDimension(6);
    shapes::Shape<square::SquareDimension, square::Square>* squareOnHeap = new square::Square(squareDimensionOnHeap);

    std::cout << "Square - side:" << std::setw(13) << squareDimensionOnHeap->getSide() << std::endl;
    assert(squareDimensionOnHeap->getSide() == 6);

    std::cout << "Square - area:" << std::setw(13) << squareOnHeap->calculateArea() << std::endl;
    assert(squareOnHeap->calculateArea() == 36);

    std::cout << "Square - circumference:" << std::setw(4) << squareOnHeap->calculatecircumference() << std::endl;
    assert(squareOnHeap->calculatecircumference() == 24);

    shapes::Shape<square::SquareDimension, square::Square>* anotherSquare = new square::Square(squareDimensionOnHeap);
    *anotherSquare = *squareOnHeap;
    assert(anotherSquare->getDimension() == squareOnHeap->getDimension());
    assert(anotherSquare->getDimension()->getSide() == squareOnHeap->getDimension()->getSide());

    delete anotherSquare;
    delete squareOnHeap;
    delete squareDimensionOnHeap;

    return 0;
}
