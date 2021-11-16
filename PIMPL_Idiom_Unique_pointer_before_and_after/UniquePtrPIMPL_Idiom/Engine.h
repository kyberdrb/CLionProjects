#pragma once

#include <iostream>

class Engine {
public:
    Engine() = default;

    void start() {
        std::cout << "Startin' the engine..." << std::endl;
    }
};