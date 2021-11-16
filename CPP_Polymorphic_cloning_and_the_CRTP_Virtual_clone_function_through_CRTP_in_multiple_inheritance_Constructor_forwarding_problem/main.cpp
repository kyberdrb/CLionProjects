#include <iostream>

using std::cout;
using std::endl;

// C++: Polymorphic cloning and the CRTP (Curiously Recurring Template Pattern): The constructor forwarding problem: https://katyscode.wordpress.com/2013/08/22/c-polymorphic-cloning-and-the-crtp-curiously-recurring-template-pattern/

// the code doesn't compile because the compiler expects the base class constructors to be in the base CRTP class,
// not in the abstract class Vehicle, although the CRTP base class inherits from the abstract class indirectly
// through a template parameter

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
    Base* clone() const override {
        return new Derived(static_cast<const Derived&>(*this));
    }
};

class Car : public VehicleCloneable<Car, Vehicle> {
public:
    Car() = default;

    Car(int fuelCapacity) : Vehicle(fuelCapacity) {}    // error: type ‘Vehicle’ is not a direct base of ‘Car’
    Car(int fuelCapacity) : VehicleCloneable<Car, Vehicle>(fuelCapacity) {}     // error: no matching function for call to ‘VehicleCloneable<Car, Vehicle>::VehicleCloneable(int&)’

    void describe() const override {
        cout << "car" << endl;
    }
};

class Plane : public VehicleCloneable<Plane, Vehicle> {
    typedef VehicleCloneable<Plane, Vehicle> BaseClass;

public:
    Plane() = default;

    Plane(int fuelCapacity) : Vehicle(fuelCapacity) {}    // error: type ‘Vehicle’ is not a direct base of ‘Car’
    Plane(int fuelCapacity) : BaseClass(fuelCapacity) {}     // error: no matching function for call to ‘VehicleCloneable<Car, Vehicle>::VehicleCloneable(int&)’

    void describe() const override {
        cout << "plane" << endl;
    }
};

class CargoPlane : public VehicleCloneable<CargoPlane, Plane> {
public:
    CargoPlane() = default;

    CargoPlane(int fuelCapacity) : Vehicle(fuelCapacity) {}    // error: type ‘Vehicle’ is not a direct base of ‘Car’
    CargoPlane(int fuelCapacity) : VehicleCloneable<CargoPlane, Plane>(fuelCapacity) {}     // error: no matching function for call to ‘VehicleCloneable<Car, Vehicle>::VehicleCloneable(int&)’

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
