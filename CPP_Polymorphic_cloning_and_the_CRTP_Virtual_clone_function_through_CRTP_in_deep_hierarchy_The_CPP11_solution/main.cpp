#include <iostream>
#include <memory>

using std::cout;
using std::endl;

template <typename Derived, typename Base>
class Clonable : public Base {
	using Base::Base;

public:
	Base* cloneRaw() const override {	// if it would be exclusively about unique_ptr cloning, then this function would be in private section
		return new Derived(static_cast<const Derived&>(*this));
	}

private:
	Clonable() = default;
	friend Derived;
};

class Vehicle {
public:
	Vehicle() : fuelCapacity(0) {}

	explicit Vehicle(int fuelCapacity) : fuelCapacity(fuelCapacity) {}

	~Vehicle() = default;

	virtual Vehicle* cloneRaw() const = 0; // if it would be exclusively about unique_ptr cloning, then this function would be in private section

	std::unique_ptr<Vehicle> cloneUnique() const {
		return std::unique_ptr<Vehicle>(this->cloneRaw());
	}

	virtual void describe() const = 0;

protected:
	int fuelCapacity;

	void describe(std::string vehicleType) const {
		cout << vehicleType << ";" << this->fuelCapacity << endl;
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

	typedef Clonable<Plane, Vehicle> PlaneBaseClass;
	explicit Plane(int fuelCapacity) : PlaneBaseClass(fuelCapacity) {}

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
    Vehicle* plane = new Plane;
    Vehicle* newPlane = plane->cloneRaw();
    Vehicle* cargoPlane = new CargoPlane(20);
    Vehicle* newCargoPlane = cargoPlane->cloneRaw();
    std::unique_ptr<Vehicle> newCar = car->cloneUnique();

    car->describe();
    plane->describe();
    newPlane->describe();
    cargoPlane->describe();
    newCargoPlane->describe();
    newCar->describe();

    for(auto pointer : {car, plane, newPlane, cargoPlane, newCargoPlane}) {
        delete pointer;
        pointer = nullptr;
    }
}
