#pragma once

#include "RepeatPrintMixin.h"

#include <iostream>

class Name : public RepeatPrintMixin<Name> {
    std::string name;

public:
    explicit Name(std::string name) : name(std::move(name)) {}

    void print() const {
        std::cout << name << "\n";
    }
};