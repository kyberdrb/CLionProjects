#include "shapes/square/Square.h"
#include "shapes/rectangle/Rectangle.h"
#include "shapes/circle/Circle.h"

#include <iostream>
#include <cassert>
#include <iomanip>
#include <memory>

namespace square = shapes::square;  // namespace aliasing
namespace circle = shapes::circle;  // namespace aliasing

int main() {
    auto squareDimension = std::make_shared<square::SquareDimension>(3);
    auto square = std::make_unique<square::Square>(squareDimension.get());

    std::cout << "Square - side:" << std::setw(13) << squareDimension->getSide() << std::endl;
    assert(squareDimension->getSide() == 3);

    std::cout << "Square - area:" << std::setw(13) << square->calculateArea() << std::endl;
    assert(square->calculateArea() == 9);

    std::cout << "Square - circumference:" << std::setw(4) << square->calculateCircumference() << std::endl;
    assert(square->calculateCircumference() == 12);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    auto newSquareDimension = std::make_shared<square::SquareDimension>(5);
    square->changeDimension(newSquareDimension.get());

    std::cout << "Square - side:" << std::setw(13) << newSquareDimension->getSide() << std::endl;
    assert(newSquareDimension->getSide() == 5);

    std::cout << "Square - area:" << std::setw(13) << square->calculateArea() << std::endl;
    assert(square->calculateArea() == 25);

    std::cout << "Square - circumference:" << std::setw(4) << square->calculateCircumference() << std::endl;
    assert(square->calculateCircumference() == 20);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    auto anotherSquare = std::make_unique<square::Square>(squareDimension.get());

    assert(&anotherSquare->getDimension() == squareDimension.get());

    std::cout << "Square - side:" << std::setw(13) << squareDimension->getSide() << std::endl;
    assert(squareDimension->getSide() == 3);

    std::cout << "Square - area:" << std::setw(13) << anotherSquare->calculateArea() << std::endl;
    assert(anotherSquare->calculateArea() == 9);

    std::cout << "Square - circumference:" << std::setw(4) << anotherSquare->calculateCircumference() << std::endl;
    assert(anotherSquare->calculateCircumference() == 12);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    circle::CircleDimension circleDimension(4);
    circle::Circle circle(&circleDimension);

    std::cout << "Circle - radius:" << std::setw(13) << circleDimension.getRadius() << std::endl;
    assert(circleDimension.getRadius() == 4);

    std::cout << "Circle - diameter:" << std::setw(11) << circle.calculateDiameter() << std::endl;
    assert(circle.calculateDiameter() == 8);

    std::cout << "Circle - area:\t" << std::fixed << std::setprecision(44) << circle.calculateArea() << std::endl;
    assert(circle.calculateArea() == 50.26548245743668985596741549670696258544921875);

    std::cout << "Circle - circumference:\t" << std::fixed << std::setprecision(44) << circle.calculateCircumference() << std::endl;
    assert(circle.calculateCircumference() == 25.13274122871834492798370774835348129272460938);

    std::unique_ptr<shapes::Shape<circle::CircleDimension, circle::Circle>> anotherCircle =
        std::make_unique<circle::Circle>(&circleDimension);
    assert(anotherCircle->getShape().calculateDiameter() == 8);

    return 0;
}
