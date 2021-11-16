#include <iostream>

using std::cout;
using std::endl;

// C++: Polymorphic cloning and the CRTP (Curiously Recurring Template Pattern): The constructor forwarding problem: https://katyscode.wordpress.com/2013/08/22/c-polymorphic-cloning-and-the-crtp-curiously-recurring-template-pattern/

// Add 'using Base::Base' to the CRTP base class. Base is the template parameter from which the CRTP base class inherits.
// The 'using' declaration generates a series of constructors in the CRTP base class declared in the template parameter
// from which the CRTP base class inherits. The generated constructors have matching signatures to those declared in the
// CRTP derived classes. The 'using' keyword provides in this way functionality called 'constructor forwarding'.
// The CRTP base class, which indirectly inherits from the Vehicle abstract class through template parameter of derived classes, 
// forwards the calls to the constructors of the abstract class Vehicle in the derived classes, 
// i.e. to the Base class 'Vehicle' of the CRTP base class 'VehicleClonable'.

template <typename Derived, typename Base>
class Clonable : public Base {
public:
    // Make constructors of the Base class accessible to the derived classes
    // via constructor forwarding
    // to make code 
    // - brief (no need to re-define each type of base-class constructor in the derived class), 
    // - readable (avoiding macros), 
    // - easier to extend (more flexibility)
    using Base::Base;

    Base* clone() const override {
        return new Derived(static_cast<const Derived&>(*this)); // Create a new instance of Derived class
                                                                // with the copy constructor of the Derived class
    }
};

class Vehicle {
protected:
    int fuelCapacity;

public:
    Vehicle() : fuelCapacity(0) {}

    explicit Vehicle(int fuelCapacity) : fuelCapacity(fuelCapacity) {}

    virtual ~Vehicle() = default;
    virtual Vehicle* clone() const = 0;
    virtual void describe() const = 0;
};

class Car : public Clonable<Car, Vehicle> {
public:
    Car() = default;

    // in order to use constructors of the base class
    // we need to forward the constructors from the base class to derived classes
    // using the 'constructor forwarding' in the base class
    explicit Car(int fuelCapacity) : Clonable<Car, Vehicle>(fuelCapacity) {}

    void describe() const override {
        cout << "car" << ";" << fuelCapacity << endl;
    }
};

class Plane : public Clonable<Plane, Vehicle> {
    typedef Clonable<Plane, Vehicle> BaseClass;

public:
    Plane() = default;

    explicit Plane(int fuelCapacity) : BaseClass(fuelCapacity) {}

    Plane(const Plane& otherPlane) {
        this->fuelCapacity = otherPlane.fuelCapacity + 1;   // the '+ 1' is there only for verification
                                                            // that we're creating a deep copy
    }

    void describe() const override {
        cout << "plane" << ";" << fuelCapacity << endl;
    }
};

class CargoPlane : public Clonable<CargoPlane, Plane> {
public:
    CargoPlane() = default;

    explicit CargoPlane(int fuelCapacity) : Clonable<CargoPlane, Plane>(fuelCapacity) {}

    void describe() const override {
        cout << "cargo plane" << ";" << fuelCapacity << endl;
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

    for (auto pointer : {car, plane, newPlane, cargoPlane, newCargoPlane}) {
        delete pointer;
        pointer = nullptr;
    }

    return 0;
}
