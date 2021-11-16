#pragma once

#include <string>

class AbstractSwitchBoard {
public:
    virtual std::string flatPin() = 0;
    virtual std::string pinCount() = 0;
};
