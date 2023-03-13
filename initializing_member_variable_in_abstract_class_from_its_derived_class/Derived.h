//
// Created by laptop on 3/10/23.
//

#pragma once

#include "Base.h"

class Derived : public Base {
public:
    explicit Derived(int& x) : Base(x) {}

    void modifyReferenceInternalState() override;

    ~Derived() override = default;
};
