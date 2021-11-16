#pragma once

#include <string>

class AbstractPlug {
public:
    virtual std::string roundPin() = 0;
    virtual std::string pinCount() = 0;
};
