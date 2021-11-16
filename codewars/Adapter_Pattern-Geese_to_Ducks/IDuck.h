#pragma once

#include <string>

class IDuck
{
public:
    virtual std::string Quack() = 0;

    virtual void Fly() = 0;
};