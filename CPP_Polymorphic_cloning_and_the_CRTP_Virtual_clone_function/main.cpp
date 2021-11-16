#include <iostream>

// C++: Polymorphic cloning and the CRTP (Curiously Recurring Template Pattern): Polymorphic cloning: https://katyscode.wordpress.com/2013/08/22/c-polymorphic-cloning-and-the-crtp-curiously-recurring-template-pattern/


using std::cout;
using std::endl;

class Vehicle {
public:
    virtual ~Vehicle() = default;
    virtual Vehicle* clone() const = 0;
    virtual void describe() const = 0;
};

class Car : public Vehicle {
public:
    Vehicle* clone() const override {
        return new Car(*this);
    }

    void describe() const override {
        cout << "car" << endl;
    }
};

class Plane : public Vehicle {
public:
    Vehicle* clone() const override {
        return new Plane(*this);
    }

    void describe() const override {
        cout << "plane" << endl;
    }
};

class FighterPlane : public Plane {
public:
    Vehicle* clone() const override {
        return new FighterPlane(*this);
    }

    void describe() const override {
        cout << "fighter plane" << endl;
    }
};

int main() {
    Vehicle* car = new Car();
    Vehicle* plane = new Plane();
    Vehicle* fighterplane = new FighterPlane();

    car->describe();
    plane->describe();
    fighterplane->describe();

    Vehicle* anotherVehicle = plane->clone();
    anotherVehicle->describe();

    Vehicle* yetAnotherVehicle = fighterplane->clone();
    yetAnotherVehicle->describe();

    delete car;
    delete plane;
    delete fighterplane;
    delete anotherVehicle;
    delete yetAnotherVehicle;

    return 0;
}
