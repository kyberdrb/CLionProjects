#ifndef ABSTRACT_FACTORY_COFFEEFACTORY_H
#define ABSTRACT_FACTORY_COFFEEFACTORY_H

#include "HotDrinkFactory.h"
#include "../../hotDrinkProducts/Coffee.h"

class CoffeeFactory : public HotDrinkFactory {
public:
    std::unique_ptr<HotDrink> make() const override {
        return std::make_unique<Coffee>();
    }
};

#endif //ABSTRACT_FACTORY_COFFEEFACTORY_H
