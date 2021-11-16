#pragma once

#include <iostream>

class Name {
    std::string name;

public:
    explicit Name(std::string name) : name(std::move(name)) {}

    void print() const {
        std::cout << name << "\n";
    }
};