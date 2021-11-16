#ifndef ABSTRACT_FACTORY_TEA_H
#define ABSTRACT_FACTORY_TEA_H

#include <iostream>
#include "HotDrink.h"

class Tea : public HotDrink {
public:
    HotDrink& prepare() override {
        std::cout << "Preparing tea..." << std::endl;
        return *this;
    }
};

#endif //ABSTRACT_FACTORY_TEA_H
