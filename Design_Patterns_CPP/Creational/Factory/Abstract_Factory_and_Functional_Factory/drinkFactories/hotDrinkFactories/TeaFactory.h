#ifndef ABSTRACT_FACTORY_TEAFACTORY_H
#define ABSTRACT_FACTORY_TEAFACTORY_H

#include "HotDrinkFactory.h"
#include "../../hotDrinkProducts/Tea.h"

class TeaFactory : public HotDrinkFactory {
public:
    std::unique_ptr<HotDrink> make() const override {
        return std::make_unique<Tea>();
    }
};

#endif //ABSTRACT_FACTORY_TEAFACTORY_H
