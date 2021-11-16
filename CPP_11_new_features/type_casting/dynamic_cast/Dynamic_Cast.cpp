//
// Created by laptop on 7/29/19.
//

#include "Dynamic_Cast.h"
#include "Parent.h"

class Brother : public Parent {};

class Sister : public Parent {};

void Dynamic_Cast::exercise() {
    Parent parent;
    Brother brother;

    Parent* ppb = &parent;      // Dynamic cast fails
//    Parent* ppb = &brother;     // Dynamic cast works

    // Dynamic cast works at runtime, not compile time.
    // In order for dynamic cast to work
    // is to make at least one function in the class virtual.
    // Also we need to enable RTTI in the compiler beacuse
    // dynamic cast deduces type of a variable at
    // runtime using RTTI - Run-time Type Identification
    Brother* pbb = dynamic_cast<Brother*>(ppb);

    if (pbb == nullptr) {
        std::cout << "Invalid cast: trying to dynamically cast pointer of a superclass type\n"
                     "to a pointer of a subclass type i.e. trying to downcast Brother to Parent.\n"
                     "That's unsafe, beacuse then we could call methods that Brother has on a Parent\n"
                     "but Parent is missing those methods." << std::endl;
    } else {
        std::cout << pbb << std::endl;
    }
}