#pragma once

#include "OldEngine.h"

class OldFridge {
    OldEngine engine;

public:
    void coolDown() {
        std::cout << "Cooling down..." << std::endl;
        engine.start();
    }
};