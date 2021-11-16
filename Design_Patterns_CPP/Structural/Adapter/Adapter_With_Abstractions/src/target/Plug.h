#pragma once

#include <iostream>
#include "AbstractPlug.h"

class Plug : public AbstractPlug {
public:
    std::string roundPin() override;
    std::string pinCount() override;
};
