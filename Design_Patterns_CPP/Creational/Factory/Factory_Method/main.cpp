#include <iostream>
#include <cmath>

class Point {
    double a = 0, b = 0;
    Point(double a, double b) : a(a), b(b) {}

public:
    static Point createCartesian(double x, double y) {
        return {x, y};
    }

    static Point createPolar(double rho, double theta) {
        return {rho * cos(theta), rho * sin(theta)};
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << point.a << "; " << point.b;
        return os;
    }
};

int main() {
    auto cartesianPoint = Point::createCartesian(3, 4);
    std::cout << cartesianPoint << std::endl;

    auto polarPoint = Point::createPolar(5, M_PI_4);
    std::cout << polarPoint << std::endl;
    return 0;
}