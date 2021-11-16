#include <iostream>
#include <cmath>

class Point_1 {
    double a = 0, b = 0;
    Point_1(double a, double b) : a(a), b(b) {}

public:
    friend std::ostream& operator<<(std::ostream& os, const Point_1& point) {
        os << point.a << "; " << point.b;
        return os;
    }

    class PointFactory {
    public:
        static Point_1 createCartesian(double x, double y) {
            return {x, y};
        }

        static Point_1 createPolar(double rho, double theta) {
            return {rho * cos(theta), rho * sin(theta)};
        }
    };
};

class Point_2 {
    double a = 0, b = 0;
    Point_2(double a, double b) : a(a), b(b) {}

public:
    friend std::ostream& operator<<(std::ostream& os, const Point_2& point) {
        os << point.a << "; " << point.b;
        return os;
    }

private:
    class PointFactory {
    public:
        static Point_2 createCartesian(double x, double y) {
            return {x, y};
        }

        static Point_2 createPolar(double rho, double theta) {
            return {rho * cos(theta), rho * sin(theta)};
        }
    };

public:
    static PointFactory Factory;
};

int main() {
    auto cartesianPoint = Point_1::PointFactory::createCartesian(2, 3);
    std::cout << cartesianPoint << std::endl;

    auto polarPoint = Point_2::Factory.createPolar(3, 6);
    std::cout << polarPoint << std::endl;
    return 0;
}