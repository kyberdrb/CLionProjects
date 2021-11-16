#include <iostream>
#include <string>

// C++: Polymorphic cloning and the CRTP (Curiously Recurring Template Pattern): The Problem: https://katyscode.wordpress.com/2013/08/22/c-polymorphic-cloning-and-the-crtp-curiously-recurring-template-pattern/

using std::cout;
using std::endl;

class Vehicle {
public:
    std::string name{"vehicle"};

    virtual void foo() {}
};

class Car : public Vehicle {
public:
    int horsePower{200};

    Car() : Vehicle() {
        Vehicle::name = "car;";
    }
};

class Plane : public Vehicle {};
class Train : public Vehicle {};

Vehicle* make_a_copy(Vehicle* v) {
    return new Vehicle(*v);     // You can’t just use new Vehicle in this situation because only the base class elements
                                // (those from the Vehicle base class) will be available in the copy. Object-slicing occurs?
                                // So what do we do?
}

int main() {
    Vehicle* v = new Car();
    Vehicle* anotherCar = make_a_copy(v);

    cout << "Vehicle name - static_cast:\t" << v->name << static_cast<Car*>(v)->horsePower << endl;     // member variables are not accessible from the Vehicle interface without casting
                                                                                                        // It should be noted that dynamic_cast is safer than static_cast only if the base class defines virtual functions.
    cout << "Vehicle name - dynamic_cast;\t" << v->name << dynamic_cast<Car*>(v)->horsePower << endl;   // can't use dynamic cast when the Vehicle interface doesn't have at least one virtual function
    cout << "Cloned vehicle name:\t" << anotherCar->name << reinterpret_cast<Car*>(v)->horsePower << endl;

    delete v;
    delete anotherCar;

    return 0;
}
