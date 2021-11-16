#pragma once

#include "Engine.h"

class Fridge {
    Engine engine;

public:
    void coolDown() {
        std::cout << "Cooling down - implementation called" << std::endl;
    }
};