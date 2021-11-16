#ifndef ABSTRACT_FACTORY_HOTDRINKFACTORY_H
#define ABSTRACT_FACTORY_HOTDRINKFACTORY_H

#include <string>
#include <memory>
#include "../../hotDrinkProducts/HotDrink.h"

class HotDrinkFactory {
public:
    virtual std::unique_ptr<HotDrink> make() const = 0;
};

#endif //ABSTRACT_FACTORY_HOTDRINKFACTORY_H
