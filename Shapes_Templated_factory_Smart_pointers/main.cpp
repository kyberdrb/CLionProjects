#include <iostream>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <memory>

template <typename Dimension, typename ShapeType>
class Shape {
public:
    Shape(
        Dimension* dimension,
        ShapeType& shape)
        :
        dimension(dimension),
        shape(shape) {}

    virtual double calculateArea() const = 0;
    virtual double calculateCircumference() const = 0;

    Dimension& getDimension() const {
        return *dimension;
    }

    void changeDimension(Dimension* newDimension) {
        dimension = newDimension;
    }

    ShapeType& getShape() const {
        return this->shape;
    }

    virtual ~Shape() = default;

private:
    Dimension* dimension;
    ShapeType& shape;
};

class SquareDimension {
public:
    explicit SquareDimension(double side) : side(side) {}

    double getSide() const {
        return this->side;
    }

private:
    double side{};
};

class Square : public Shape<SquareDimension, Square> {
public:
    explicit Square(SquareDimension* dimension) :
        Shape(dimension, *this) {}

    double calculateArea() const override {
        return Shape::getDimension().getSide() * this->getDimension().getSide();
    }

    double calculateCircumference() const override {
        return Shape::getDimension().getSide() * 4;
    }
};

class RectangleDimension {
public:
    RectangleDimension(double sideA, double sideB) :
            sideA(sideA), sideB(sideB) {}

    double getSideA() const {
        return sideA;
    }

    double getSideB() const {
        return sideB;
    }

private:
    double sideA{};
    double sideB{};
};

class Rectangle : public Shape<RectangleDimension, Rectangle> {
public:
    explicit Rectangle(RectangleDimension* dimension) :
        Shape(dimension, *this) {}

    double calculateArea() const override {
        return Shape::getDimension().getSideA() * this->getDimension().getSideB();
    }

    double calculateCircumference() const override {
        return (Shape::getDimension().getSideA() + this->getDimension().getSideB()) * 2;
    }
};

class CircleDimension {
public:
    explicit CircleDimension(double radius) : radius(radius) {}

    double getRadius() const {
        return this->radius;
    }

private:
    double radius{};
};

class Circle : public Shape<CircleDimension, Circle> {
public:
    explicit Circle(CircleDimension* dimension) :
        Shape(dimension, *this) {}

    double calculateArea() const override {
        return M_PI * Shape::getDimension().getRadius() * Shape::getDimension().getRadius();
    }

    double calculateCircumference() const override {
        return 2 * M_PI * this->getDimension().getRadius();
    }

    double calculateDiameter() const {
        return Shape::getDimension().getRadius() * 2;
    }
};

int main() {
    auto squareDimension = std::make_shared<SquareDimension>(3);
    auto square = std::make_unique<Square>(squareDimension.get());

    std::cout << "Square - side:" << std::setw(13) << squareDimension->getSide() << std::endl;
    assert(squareDimension->getSide() == 3);

    std::cout << "Square - area:" << std::setw(13) << square->calculateArea() << std::endl;
    assert(square->calculateArea() == 9);

    std::cout << "Square - circumference:" << std::setw(4) << square->calculateCircumference() << std::endl;
    assert(square->calculateCircumference() == 12);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    auto newSquareDimension = std::make_shared<SquareDimension>(5);
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

    auto anotherSquare = std::make_unique<Square>(squareDimension.get());

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

    CircleDimension circleDimension(4);
    Circle circle(&circleDimension);

    std::cout << "Circle - radius:" << std::setw(13) << circleDimension.getRadius() << std::endl;
    assert(circleDimension.getRadius() == 4);

    std::cout << "Circle - diameter:" << std::setw(11) << circle.calculateDiameter() << std::endl;
    assert(circle.calculateDiameter() == 8);

    std::cout << "Circle - area:\t" << std::fixed << std::setprecision(44) << circle.calculateArea() << std::endl;
    assert(circle.calculateArea() == 50.26548245743668985596741549670696258544921875);

    std::cout << "Circle - circumference:\t" << std::fixed << std::setprecision(44) << circle.calculateCircumference() << std::endl;
    assert(circle.calculateCircumference() == 25.13274122871834492798370774835348129272460938);

    std::unique_ptr<Shape<CircleDimension, Circle>> anotherCircle = std::make_unique<Circle>(&circleDimension);
    assert(anotherCircle->getShape().calculateDiameter() == 8);

    return 0;
}
