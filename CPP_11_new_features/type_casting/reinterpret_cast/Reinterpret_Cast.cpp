//
// Created by laptop on 7/29/19.
//

#include <iostream>
#include "Reinterpret_Cast.h"

class Parent {
public:
    virtual void speak() {
        std::cout << "parent!" << std::endl;
    }
};

class Brother : public Parent {};

class Sister : public Parent {};

void Reinterpret_Cast::exercise() {
    Parent parent;
    Brother brother;
    Sister sister;

    Parent* ppb = &brother;

    // Reinterpret cast has even less compile time checking than static cast.
    // It has the weakest checking of all casts.
    // It does a binary translation of a class of one type to a class of another type.
    // Can be dangerous. Use sparingly. Useful for badly written APIs.
//    Sister* pbb = static_cast<Sister*>(ppb);        // Static cast works
//    Sister* pbb = dynamic_cast<Sister*>(ppb);       // Dynamic cast fails
    Sister* pbb = reinterpret_cast<Sister*>(ppb);   // Reinterpret cast works

    if (pbb == nullptr) {
        std::cout << "Invalid cast: Trying to cast subclass of one type "
                     "to a subclass of another type."
                     "Try to use reinterpret cast, but that can be dangerous, "
                     "when one class has attributes or methods that the other doesn't." << std::endl;
    } else {
        std::cout << pbb << std::endl;
    }
}
