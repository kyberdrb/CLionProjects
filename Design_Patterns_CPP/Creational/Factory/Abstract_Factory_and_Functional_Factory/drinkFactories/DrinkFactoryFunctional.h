#ifndef ABSTRACT_FACTORY_DRINKFACTORYFUNCTIONAL_H
#define ABSTRACT_FACTORY_DRINKFACTORYFUNCTIONAL_H

#include <string>
#include <bits/unique_ptr.h>
#include <map>
#include <functional>
#include "../hotDrinkProducts/HotDrink.h"
#include "../hotDrinkProducts/Tea.h"

class DrinkFactoryFunctional {
    std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> hotDrinkFunctionalFactories;

public:
    DrinkFactoryFunctional() {
        hotDrinkFunctionalFactories["tea"] = [] {
            auto tea = std::make_unique<Tea>();
            return tea;
        };
        hotDrinkFunctionalFactories["coffee"] = [] {
            auto coffee = std::make_unique<Coffee>();
            return coffee;
        };
    }

    std::unique_ptr<HotDrink> makeDrink(const std::string& drinkName) {
        return hotDrinkFunctionalFactories[drinkName]();
    }
};

#endif //ABSTRACT_FACTORY_DRINKFACTORYFUNCTIONAL_H
