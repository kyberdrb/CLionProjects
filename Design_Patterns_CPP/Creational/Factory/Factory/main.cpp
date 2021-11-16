#include <iostream>
#include <cmath>

class Point {
    // Making the Factory class a friend of Point conforms to the rule
    // that it should be one obvious way to do things.
    // At the same time, friend classes violate the OCP
    // beacuse we need to modify existing code
    // in order to add functionality
//    friend class PointFactory;

    double a = 0, b = 0;

    // Make constructor public:
    // PointFactory can then instantiate the Point objects via constructor.
    // Now there are two ways how to make an instance of Point:
    // - via the constructor
    // - via the Factory
    // This violates the rule that there should be ideally only one obvious way to do things
    // i.e. to create instances of a class Point.
    // Violating the OCP rule is worse, so I will leave a public constructor
public:
    Point(double a, double b) : a(a), b(b) {}

public:
    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << point.a << "; " << point.b;
        return os;
    }
};

class PointFactory {
public:
    static Point createCartesian(double x, double y) {
        return {x, y};
    }

    static Point createPolar(double rho, double theta) {
        return {rho * cos(theta), rho * sin(theta)};
    }
};

int main() {
    auto cartesianPoint = PointFactory::createCartesian(5, 6);
    std::cout << cartesianPoint << std::endl;

    auto polarPoint = PointFactory::createPolar(7, 8);
    std::cout << polarPoint << std::endl;
    return 0;
}