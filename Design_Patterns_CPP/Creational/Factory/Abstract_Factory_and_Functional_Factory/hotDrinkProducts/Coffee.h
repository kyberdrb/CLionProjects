#ifndef ABSTRACT_FACTORY_COFFEE_H
#define ABSTRACT_FACTORY_COFFEE_H

#include <iostream>
#include "HotDrink.h"

class Coffee : public HotDrink {
public:
    HotDrink &prepare() override {
        std::cout << "Preparing coffee..." << std::endl;
        return *this;
    }
};

#endif //ABSTRACT_FACTORY_COFFEE_H
