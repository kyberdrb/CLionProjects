#pragma once

#include <iostream>

class Keyboard {
public:
    ~Keyboard() {
        std::cout << "Keyboard destroyed" << std::endl;
    }
};