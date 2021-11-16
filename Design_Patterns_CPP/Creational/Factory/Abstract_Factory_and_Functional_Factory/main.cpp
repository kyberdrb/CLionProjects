#include "hotDrinkProducts/HotDrink.h"
#include "drinkFactories/DrinkFactory.h"
#include "drinkFactories/DrinkFactoryFunctional.h"

int main() {
    std::unique_ptr<DrinkFactory> drinkFactory(new DrinkFactory);
    auto drink = drinkFactory->makeDrink("tea");
    drink->prepare();

    drink = DrinkFactory().makeDrink("coffee");
    drink->prepare();

    std::cout << std::endl;

    std::unique_ptr<DrinkFactory> drinkFactoryFunctional(new DrinkFactory);
    drink = drinkFactoryFunctional->makeDrink("tea");
    drink->prepare();

    drink = DrinkFactoryFunctional().makeDrink("coffee");
    drink->prepare();

    return 0;
}