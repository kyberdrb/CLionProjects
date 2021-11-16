#include <iostream>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <memory>

template <typename Dimension, typename ShapeType>
class Shape {
public:
    Shape(Dimension* dimension, ShapeType* shape) :
        dimension(dimension), shape(shape) {}

    virtual double calculateArea() const = 0;
    virtual double calculateCircumference() const = 0;

    Dimension* getDimension() const {
        return this->dimension;
    }

    void changeDimension(Dimension* newDimension) {
        this->dimension = newDimension;
    }

    ShapeType* getShape() const {
        return this->shape;
    }

    virtual ~Shape() = default;

private:
    Dimension* dimension{};
    ShapeType* shape{};
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
    explicit Square(SquareDimension* dimension) : Shape(dimension, this) {}

    double calculateArea() const override {
        return Shape::getDimension()->getSide() * this->getDimension()->getSide();
    }

    double calculateCircumference() const override {
        return Shape::getDimension()->getSide() * 4;
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
    explicit Rectangle(RectangleDimension* dimension) : Shape(dimension, this) {}

    double calculateArea() const override {
        return Shape::getDimension()->getSideA() * this->getDimension()->getSideB();
    }

    double calculateCircumference() const override {
        return (Shape::getDimension()->getSideA() + this->getDimension()->getSideB()) * 2;
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
    explicit Circle(CircleDimension* dimension) : Shape(dimension, this) {}

    double calculateArea() const override {
        return M_PI * Shape::getDimension()->getRadius() * Shape::getDimension()->getRadius();
    }

    double calculateCircumference() const override {
        return 2 * M_PI * this->getDimension()->getRadius();
    }

    double calculateDiameter() const {
        return Shape::getDimension()->getRadius() * 2;
    }
};

int main() {
    SquareDimension squareDimension(3);
    Square square(&squareDimension);

    std::cout << "Square - side:" << std::setw(13) << squareDimension.getSide() << std::endl;
    assert(squareDimension.getSide() == 3);

    std::cout << "Square - area:" << std::setw(13) << square.calculateArea() << std::endl;
    assert(square.calculateArea() == 9);

    std::cout << "Square - circumference:" << std::setw(4) << square.calculateCircumference() << std::endl;
    assert(square.calculateCircumference() == 12);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    SquareDimension newSquareDimension(5);
    square.changeDimension(&newSquareDimension);
    std::cout << "Square - side:" << std::setw(13) << newSquareDimension.getSide() << std::endl;
    assert(newSquareDimension.getSide() == 5);

    std::cout << "Square - area:" << std::setw(13) << square.calculateArea() << std::endl;
    assert(square.calculateArea() == 25);

    std::cout << "Square - circumference:" << std::setw(4) << square.calculateCircumference() << std::endl;
    assert(square.calculateCircumference() == 20);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    RectangleDimension rectangleDimension(2, 3);
    Rectangle rectangle(&rectangleDimension);

    std::cout << "Rectangle - sideA:" << std::setw(13) << rectangleDimension.getSideA() << std::endl;
    assert(rectangleDimension.getSideA() == 2);

    std::cout << "Rectangle - sideB:" << std::setw(13) << rectangleDimension.getSideB() << std::endl;
    assert(rectangleDimension.getSideB() == 3);

    std::cout << "Rectangle - area:" << std::setw(14) << rectangle.calculateArea() << std::endl;
    assert(rectangle.calculateArea() == 6);

    std::cout << "Rectangle - circumference:" << std::setw(5) << rectangle.calculateCircumference() << std::endl;
    assert(rectangle.calculateCircumference() == 10);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    RectangleDimension newRectangleDimension(4, 5);
    rectangle.changeDimension(&newRectangleDimension);

    std::cout << "Rectangle - sideA:" << std::setw(13) << newRectangleDimension.getSideA() << std::endl;
    assert(newRectangleDimension.getSideA() == 4);

    std::cout << "Rectangle - sideB:" << std::setw(13) << newRectangleDimension.getSideB() << std::endl;
    assert(newRectangleDimension.getSideB() == 5);

    std::cout << "Rectangle - area:" << std::setw(14) << rectangle.calculateArea() << std::endl;
    assert(rectangle.calculateArea() == 20);

    std::cout << "Rectangle - circumference:" << std::setw(5) << rectangle.calculateCircumference() << std::endl;
    assert(rectangle.calculateCircumference() == 18);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    auto circleDimension = std::make_unique<CircleDimension>(4);
    auto circle = std::make_unique<Circle>(circleDimension.get());

    std::cout << "Circle - radius:" << std::setw(13) << circleDimension->getRadius() << std::endl;
    assert(circleDimension->getRadius() == 4);

    std::cout << "Circle - diameter:" << std::setw(11) << circle->calculateDiameter() << std::endl;
    assert(circle->calculateDiameter() == 8);

    std::cout << "Circle - area:\t" << std::fixed << std::setprecision(44) << circle->calculateArea() << std::endl;
    assert(circle->calculateArea() == 50.26548245743668985596741549670696258544921875);

    std::cout << "Circle - circumference:\t" << std::fixed << std::setprecision(44) << circle->calculateCircumference() << std::endl;
    assert(circle->calculateCircumference() == 25.13274122871834492798370774835348129272460938);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    auto newCircleDimension = std::make_unique<CircleDimension>(1/M_PI);
    circle->changeDimension(newCircleDimension.get());

    std::cout << "Circle - radius:\t" << std::fixed << std::setprecision(44) << newCircleDimension->getRadius() << std::endl;
    assert(newCircleDimension->getRadius() == 0.31830988618379069121644420192751567810773849);

    std::cout << "Circle - diameter:\t" << std::fixed << std::setprecision(44) << circle->calculateDiameter() << std::endl;
    assert(circle->calculateDiameter() == .63661977236758138243288840385503135621547699);

    std::cout << "Circle - area:\t" << std::fixed << std::setprecision(44) << circle->calculateArea() << std::endl;
    assert(circle->calculateArea() == 0.31830988618379069121644420192751567810773849);

    std::cout << "Circle - circumference:\t" << std::fixed << std::setprecision(0) << circle->calculateCircumference() << std::endl;
    assert(circle->calculateCircumference() == 2);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    std::unique_ptr<Shape<CircleDimension, Circle>> anotherCircle = std::make_unique<Circle>(circleDimension.get());

    std::cout << "Circle - radius:" << std::setw(13) << circleDimension->getRadius() << std::endl;
    assert(circleDimension->getRadius() == 4);

    std::cout << "Circle - diameter:" << std::setw(11) << anotherCircle->getShape()->calculateDiameter() << std::endl;
    assert(anotherCircle->getShape()->calculateDiameter() == 8);

    std::cout << "Circle - area:\t" << std::fixed << std::setprecision(44) << anotherCircle->calculateArea() << std::endl;
    assert(anotherCircle->calculateArea() == 50.26548245743668985596741549670696258544921875);

    std::cout << "Circle - circumference:\t" << std::fixed << std::setprecision(44) << anotherCircle->calculateCircumference() << std::endl;
    assert(anotherCircle->calculateCircumference() == 25.13274122871834492798370774835348129272460938);

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

    std::cout << "Circle - circumference:\t" << std::fixed << std::setprecision(44) << circle->calculateCircumference() << std::endl;
    assert(circle->calculateCircumference() == 25.13274122871834492798370774835348129272460938);

    std::cout << std::endl;
    std::cout << "---" << std::endl;
    std::cout << std::endl;

    Square copiedSquare(square);
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

    auto squareDimensionOnHeap = new SquareDimension(6);
    Shape<SquareDimension, Square>* squareOnHeap = new Square(squareDimensionOnHeap);

    std::cout << "Square - side:" << std::setw(13) << squareDimensionOnHeap->getSide() << std::endl;
    assert(squareDimensionOnHeap->getSide() == 6);

    std::cout << "Square - area:" << std::setw(13) << squareOnHeap->calculateArea() << std::endl;
    assert(squareOnHeap->calculateArea() == 36);

    std::cout << "Square - circumference:" << std::setw(4) << squareOnHeap->calculateCircumference() << std::endl;
    assert(squareOnHeap->calculateCircumference() == 24);

    Shape<SquareDimension, Square>* anotherSquare = new Square(squareDimensionOnHeap);
    *anotherSquare = *squareOnHeap;
    assert(anotherSquare->getDimension() == squareOnHeap->getDimension());
    assert(anotherSquare->getDimension()->getSide() == squareOnHeap->getDimension()->getSide());

    delete anotherSquare;
    delete squareOnHeap;
    delete squareDimensionOnHeap;

    return 0;
}
