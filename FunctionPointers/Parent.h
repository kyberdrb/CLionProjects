//
// Created by laptop on 7/22/19.
//

#ifndef PASSINGFUNCTIONTOFUNCTION_PARENT_H
#define PASSINGFUNCTIONTOFUNCTION_PARENT_H


#include <iostream>

class Parent {
private:
    uint_fast32_t one;

public:
    Parent() : one(1) {}

    Parent(const Parent& parent) : one(1) {
        std::cout << "Copying Parent" << std::endl << std::flush;
    }

    virtual void print() {
        std::cout << "Hello from Parent" << std::endl << std::flush;
    }
};


#endif //PASSINGFUNCTIONTOFUNCTION_PARENT_H
