#ifndef ABSTRACT_FACTORY_DRINKFACTORY_H
#define ABSTRACT_FACTORY_DRINKFACTORY_H

#include <map>
#include <bits/unique_ptr.h>
#include "hotDrinkFactories/HotDrinkFactory.h"
#include "hotDrinkFactories/CoffeeFactory.h"
#include "hotDrinkFactories/TeaFactory.h"

class DrinkFactory {
    std::map<std::string, std::unique_ptr<HotDrinkFactory>> hotDrinkFactories;

public:
    DrinkFactory() {
        hotDrinkFactories["coffee"] = std::make_unique<CoffeeFactory>();
        hotDrinkFactories["tea"] = std::make_unique<TeaFactory>();
    }

    std::unique_ptr<HotDrink> makeDrink(const std::string& drinkName) {
        return hotDrinkFactories[drinkName]->make();
    }
};

#endif //ABSTRACT_FACTORY_DRINKFACTORY_H
