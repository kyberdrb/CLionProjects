#include <iostream>

#include "AnotherFridge.h"
#include "AnotherEngine.h"

class AnotherFridge::AnotherFridgeImpl {
    AnotherEngine engine;

public:
    AnotherFridgeImpl() : engine(500) {
        std::cout << "AnotherFridgeImpl: implementation class" << std::endl;
    }

    void coolDown() {
        std::cout << "Cooling down another fridge - implementation" << std::endl;
        engine.start();
    }
};

AnotherFridge::AnotherFridge() : pimpl(new AnotherFridgeImpl) {
    std::cout << "AnotherFridge: wrapper class around implementation class" << std::endl;
}

AnotherFridge::~AnotherFridge() {
    delete pimpl;
}

void AnotherFridge::coolDown() {
    std::cout << "Cooling down another fridge - "
                 "indirect calling of 'coolDown' function in implementation class" << std::endl;
    pimpl->coolDown();
}