#include <iostream>

#define BASE_CLONEABLE(Type) \
virtual Type* clone() const = 0;

#define CLONEABLE(Type) \
Type* clone() const override { return new Type(*this); }

using std::cout;
using std::endl;

// C++: Polymorphic cloning and the CRTP (Curiously Recurring Template Pattern): The C++03 solution: https://katyscode.wordpress.com/2013/08/22/c-polymorphic-cloning-and-the-crtp-curiously-recurring-template-pattern/

// Consequence: In each new derived class we need to use the CLONEABLE macro, in order to make the derived class cloneable
// Advantage: it works
// Disadvantage: you need to keep in mind to add the CLONEABLE macro to each new derived class in order to support cloning
// To see the expanded macros in the classes execute:
//      clang -E main.cpp > main_preprocessed.cpp
// and open 'main_preprocessed.cpp'

class Vehicle {
public:
    BASE_CLONEABLE(Vehicle);

    virtual ~Vehicle() = default;
    virtual void describe() const = 0;
};

class Car : public Vehicle {
public:
    Car() = default;
    Car(const Car&) = default;

    CLONEABLE(Car);

    void describe() const override {
        cout << "car" << endl;
    }
};

class Plane : public Vehicle {
public:
    Plane() = default;
    Plane(const Plane&) = default;

    CLONEABLE(Plane);

    void describe() const override {
        cout << "plane" << endl;
    }
};

class CargoPlane : public Vehicle {
public:
    CargoPlane() = default;
    CargoPlane(const CargoPlane&) = default;

    CLONEABLE(CargoPlane);

    void describe() const override {
        cout << "cargo plane" << endl;
    }
};

int main() {
    Vehicle* car = new Car();
    Vehicle* plane = new Plane;
    Vehicle* newPlane = plane->clone();
    Vehicle* cargoPlane = new CargoPlane();
    Vehicle* newCargoPlane = cargoPlane->clone();

    car->describe();
    plane->describe();
    newPlane->describe();
    cargoPlane->describe();
    newCargoPlane->describe();

    delete car;
    delete plane;
    delete newPlane;
    delete cargoPlane;
    delete newCargoPlane;
    return 0;
}
