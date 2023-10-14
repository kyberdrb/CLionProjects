//
// Created by laptop on 10/14/23.
//

#pragma once

#include "Item.h"

class Laptop : public Item {
public:
    explicit Laptop(std::string name) :
        Item(std::move(name))
    {}

    ~Laptop() override = default;
};
