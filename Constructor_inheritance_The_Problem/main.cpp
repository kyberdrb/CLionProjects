#include <iostream>

// Modern C++ Features – Inherited and Delegating Constructors: Inheriting constructors: https://arne-mertz.de/2015/08/new-c-features-inherited-and-delegating-constructors/

class Dependency {};

class Base {
    Dependency* myDependency{};

public:
    explicit Base(Dependency* dep) : myDependency(dep) {}    // dependency injection

    virtual ~Base() {
        delete myDependency;
    }
};

// Consider a class that derives from a base which needs some parameters to be constructed properly,
// e.g because you use dependency injection and.
// That usually means that constructors of the inheriting class need to have the same parameter
// which is often only passed to the base class.
class Derived : public Base {
public:
    Derived(Dependency* dep) : Base(dep) {}    // constructor does nothing except forwarding arguments to the base constructor
                                                        // This can get pretty annoying, especially if you have multiple
                                                        // constructors in Base and you want to support them all in the derived class.
};

int main() {
    Dependency* dependency = new Dependency;
//    Base* derived = new Derived();  // error: use of deleted function ‘Derived::Derived()’
                                    // Because we defined a custom constructor in the Base class, the Derived class has
                                    // only the custom base constructor available

    Base* derived = new Derived(dependency);
    delete derived;

    Derived d = new Dependency; // using the constructor in Derived class to convert Dependency pointer to Derived instance on the stack;
                                // example of how the converting constructor works

    return 0;
}
