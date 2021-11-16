#include <iostream>

using std::cout;
using std::endl;

// C++: Polymorphic cloning and the CRTP (Curiously Recurring Template Pattern): CRTP with Multi-Level Inheritance: https://katyscode.wordpress.com/2013/08/22/c-polymorphic-cloning-and-the-crtp-curiously-recurring-template-pattern/

//This solution is all very well if you have:
//- no constructors
//- only default constructors
//- all constructors in all derived classes use the same signature
//- the individual derived classes only use constructors which don’t call any base constructors
//Most of the time though in a real world application, the derived classes will have multiple constructors with different signatures, and oftentimes you will want to call a base constructor too. In these cases, you will experience the constructor forwarding problem.

class Vehicle {
public:
    virtual ~Vehicle() = default;
    virtual Vehicle* clone() const = 0;
    virtual void describe() const = 0;
};

template <typename Derived, typename Base>
class VehicleCloneable : public Base {
public:
    Base* clone() const override {
        return new Derived(static_cast<const Derived&>(*this));
    }
};

class Car : public VehicleCloneable<Car, Vehicle> {
public:
    Car() = default;
    Car(const Car&) = default;

    void describe() const override {
        cout << "car" << endl;
    }
};

class Plane : public VehicleCloneable<Car, Vehicle> {
public:
    Plane() = default;
    Plane(const Plane&) = default;

    void describe() const override {
        cout << "plane" << endl;
    }
};

class CargoPlane : public VehicleCloneable<CargoPlane, Plane> {
public:
    CargoPlane() = default;
    CargoPlane(const CargoPlane&) = default;

    void describe() const override {
        cout << "cargo plane" << endl;
    }
};

int main() {
    Vehicle* car = new Car;
    Vehicle* plane = new Plane;
    Vehicle* tractor = car->clone();
    Vehicle* cargoPlane = new CargoPlane;

    car->describe();
    plane->describe();
    tractor->describe();
    cargoPlane->describe();

    delete car;
    delete plane;
    delete tractor;
    delete cargoPlane;

    return 0;
}
