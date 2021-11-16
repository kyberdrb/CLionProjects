#include <iostream>

using std::cout;
using std::endl;

// C++: Polymorphic cloning and the CRTP (Curiously Recurring Template Pattern): The constructor forwarding problem: https://katyscode.wordpress.com/2013/08/22/c-polymorphic-cloning-and-the-crtp-curiously-recurring-template-pattern/

// declare every possible set of constructor signatures in the base CRTP class
// Consequences:
// - every time we add a constructor with a different signature to any of the derived classes of the CRTP base class,
//   we add a new constructor to the CRTP base class that calls the base constructor from the template parameter with the
//   provided constructor arguments
// Advantages:
// - it works
// Disadvantages:
// - more difficult to extend because it violates the OCP
// - also more difficult to maintain and read

class Vehicle {
protected:
    int fuelCapacity;

public:
    Vehicle() : fuelCapacity(0) {}

    Vehicle(int fuelCapacity) : fuelCapacity(fuelCapacity) {}

    virtual ~Vehicle() = default;
    virtual Vehicle* clone() const = 0;
    virtual void describe() const = 0;
};

template <typename Derived, typename Base>
class VehicleCloneable : public Base {
public:
    VehicleCloneable() = default;
    explicit VehicleCloneable(int arg1) : Base(arg1) {}
    VehicleCloneable(int arg1, int arg2) : Base(arg1, arg2) {}

    Base* clone() const override {
        return new Derived(static_cast<const Derived&>(*this));
    }
};

class Car : public VehicleCloneable<Car, Vehicle> {
public:
    Car() = default;

    Car(int fuelCapacity) : VehicleCloneable<Car, Vehicle>(fuelCapacity) {}

    void describe() const override {
        cout << "car" << endl;
    }
};

class Plane : public VehicleCloneable<Plane, Vehicle> {
    typedef VehicleCloneable<Plane, Vehicle> BaseClass;

public:
    Plane() = default;

    Plane(int fuelCapacity) : BaseClass(fuelCapacity) {}

    void describe() const override {
        cout << "plane" << endl;
    }
};

class CargoPlane : public VehicleCloneable<CargoPlane, Plane> {
public:
    CargoPlane() = default;

    CargoPlane(int fuelCapacity) : VehicleCloneable<CargoPlane, Plane>(fuelCapacity) {}

    void describe() const override {
        cout << "cargo plane" << endl;
    }
};

int main() {
    Vehicle* car = new Car(5);
    Vehicle* plane = new Plane;
    Vehicle* newPlane = plane->clone();
    Vehicle* cargoPlane = new CargoPlane(20);
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
