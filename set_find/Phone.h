//
// Created by laptop on 10/14/23.
//

#pragma once

#include "Item.h"

class Phone : public Item {
public:
    explicit Phone(std::string name) :
        Item(std::move(name))
    {}

    ~Phone() override = default;
};
