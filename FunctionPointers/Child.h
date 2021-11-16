//
// Created by laptop on 7/22/19.
//

#ifndef PASSINGFUNCTIONTOFUNCTION_CHILD_H
#define PASSINGFUNCTIONTOFUNCTION_CHILD_H


#include "Parent.h"

class Child : public Parent {
private:
    uint_fast32_t two;
public:
    Child() : two(2) {}

    virtual void print() {
        std::cout << "Hello from Child" << std::endl << std::flush;
    }
};


#endif //PASSINGFUNCTIONTOFUNCTION_CHILD_H
