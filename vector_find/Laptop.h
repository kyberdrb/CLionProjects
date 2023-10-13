//
// Created by laptop on 10/12/23.
//

#pragma once

#include "Item.h"

#include <iostream>

class Laptop : public Item {
public:
    explicit Laptop(std::string name) :
        Item(std::move(name))
    {}

    void use() override {
        std::cout << "coding";
    }
};
