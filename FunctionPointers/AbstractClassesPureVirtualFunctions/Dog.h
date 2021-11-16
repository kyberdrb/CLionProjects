//
// Created by laptop on 7/22/19.
//

#ifndef PASSINGFUNCTIONTOFUNCTION_DOG_H
#define PASSINGFUNCTIONTOFUNCTION_DOG_H


#include <iostream>
#include "Animal.h"

class Dog : public Animal {
    void speak() override {
        std::cout << "Woof" << std::endl << std::flush;
    }
};


#endif //PASSINGFUNCTIONTOFUNCTION_DOG_H
