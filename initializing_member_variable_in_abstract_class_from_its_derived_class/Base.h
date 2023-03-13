//
// Created by laptop on 3/10/23.
//

#pragma once

class Base {
public:
    explicit Base(int& numberReference) : _numberReference(numberReference) {}

    virtual void modifyReferenceInternalState() = 0;

    virtual ~Base() = default;

    int& _numberReference;
};
