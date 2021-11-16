#include <iostream>

// Modern C++ Features – Inherited and Delegating Constructors: Inheriting constructors: https://arne-mertz.de/2015/08/new-c-features-inherited-and-delegating-constructors/

class Dependency {};

class Base {
    Dependency* myDependency{};

public:
    //explicit
    Base(Dependency* dep) : myDependency(dep) {}

    virtual ~Base() {
        delete myDependency;
    }
};

class Derived : public Base {
    // In C++11 there is a solution to this annoyance: using directives for base class constructors.
    //  Instead of writing a complete constructor, you just inherit the base class constructors and are ready to use them.
    // As you see, I have not used `public` before the using declaration.
    //  That is ok, since inheriting constructors are implicitly declared with the same access as the inherited base class constructors.
    using Base::Base;
};

int main() {
    auto dependency = new Dependency;
    Base* derived = new Derived(dependency);
    delete derived;

    Derived d = new Dependency; // in order to disable implicit conversion, mark the constructor in the Base class as 'explicit'

    return 0;
}
