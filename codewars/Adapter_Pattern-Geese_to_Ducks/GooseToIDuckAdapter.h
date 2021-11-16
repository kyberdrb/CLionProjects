#pragma once

#include <iostream>
#include "IDuck.h"

#include <iostream>

#include <iostream>

class GooseToIDuckAdapter : IDuck
{
    Goose &_goose;

public:
    GooseToIDuckAdapter(Goose &goose) : _goose(goose) { }

    std::string Quack() override {
        return _goose.Honk();
    }

    void Fly() override {
        _goose.Fly();
    }
};