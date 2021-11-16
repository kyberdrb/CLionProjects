#include <iostream>
#include <string>

// C++: Polymorphic cloning and the CRTP (Curiously Recurring Template Pattern): The Curiously Recurring Template Pattern (CRTP): https://katyscode.wordpress.com/2013/08/22/c-polymorphic-cloning-and-the-crtp-curiously-recurring-template-pattern/

class Vehicle {
public:
    virtual ~Vehicle() = default;
    virtual Vehicle* clone() const = 0;
    virtual void describe() const = 0;
};

template <typename Derived>
class VehicleClonable : public Vehicle {
public:
    VehicleClonable* clone() const override {
        return new Derived(static_cast<const Derived&>(*this));
    }

private:
    VehicleClonable() = default;
    friend Derived;
};

class Car : public VehicleClonable<Car> {
public:
    Car* clone() const override {
        return new Car(*this);
    }

    void describe() const override {
        std::cout << "car" << std::endl;
    }
};

class Plane : public VehicleClonable<Plane> {
    mutable std::string name;

public:
    Plane() : name("plane") {}

    Plane* clone() const override {
        return new Plane(*this);
    }

    void describe() const override {
        this->name = "plane";
        std::cout << "plane" << std::endl;
    }
};

int main() {
    Vehicle* car = new Car;
    Vehicle* plane = new Plane;
    Vehicle* someVehicle = car->clone();

    car->describe();
    plane->describe();
    someVehicle->describe();

    delete car;
    delete plane;
    delete someVehicle;

    return 0;
}
