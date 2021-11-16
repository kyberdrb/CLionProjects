#include <memory>
#include <iostream>

template <typename Derived, typename Base>
class Clonable : public Base {
public:
    using Base::Base;

    Base* cloneRaw() const override {
        return new Derived(static_cast<const Derived&>(*this));
    }

private:
    Clonable() = default;   // mechanism to check, if the type in the 'Derived' template parameter
    friend Derived;         // for CRTP base class matches the class which inherits the CRTP base class
};

class Vehicle {
public:
    Vehicle() : fuelCapacity(0) {}

    explicit Vehicle(int fuelCapacity) : fuelCapacity(fuelCapacity) {}

    virtual ~Vehicle() = default;

    virtual Vehicle* cloneRaw() const = 0;

    std::unique_ptr<Vehicle> cloneUnique() const {
        return std::unique_ptr<Vehicle>(this->cloneRaw());
    }

    virtual void describe() const = 0;

protected:
    int fuelCapacity;

    void describe(std::string vehicleType) const {
        std::cout << vehicleType << ";" << this->fuelCapacity << std::endl;
    }
};

class Car : public Clonable<Car, Vehicle> {
public:
    Car() = default;

    explicit Car(int fuelCapacity) : Clonable<Car, Vehicle>(fuelCapacity) {}

    Car(const Car& otherCar) {
        this->fuelCapacity = otherCar.fuelCapacity + 1;
    }

    void describe() const override {
        Vehicle::describe("car");
    }
};

class Plane : public Clonable<Plane, Vehicle> {
public:
    Plane() = default;

    explicit Plane(int fuelCapacity) : Clonable<Plane, Vehicle>(fuelCapacity) {}

    Plane(const Plane& otherPlane) {
        this->fuelCapacity = otherPlane.fuelCapacity + 1;
    }

    void describe() const override {
        Vehicle::describe("plane");
    }
};

class CargoPlane : public Clonable<CargoPlane, Plane> {
public:
    CargoPlane() = default;

    explicit CargoPlane(int fuelCapacity) : Clonable<CargoPlane, Plane>(fuelCapacity) {}

    void describe() const override {
        Vehicle::describe("cargo plane");
    }
};

int main() {
    Vehicle* car = new Car(5);
    Vehicle* clonedCar = car->cloneRaw();
    std::unique_ptr<Vehicle> uniqueClonedCar = clonedCar->cloneUnique();
    Vehicle* plane = new Plane;
    Vehicle* clonedPlane = plane->cloneRaw();
    Vehicle* cargoPlane = new CargoPlane(20);
    Vehicle* clonedCargoPlane = cargoPlane->cloneRaw();

    car->describe();
    clonedCar->describe();
    uniqueClonedCar->describe();
    plane->describe();
    clonedPlane->describe();
    cargoPlane->describe();
    clonedCargoPlane->describe();

    for (auto pointer : {car, clonedCar, plane, clonedPlane, cargoPlane, clonedCargoPlane}) {
        delete pointer;
        pointer = nullptr;
    }

    return 0;
}
