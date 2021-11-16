#pragma once

#include <bits/unique_ptr.h>
#include "Keyboard.h"

class Laptop {
    std::unique_ptr<Keyboard> _keyboard;

public:
    Laptop() {
        _keyboard = std::make_unique<Keyboard>();
    }
};