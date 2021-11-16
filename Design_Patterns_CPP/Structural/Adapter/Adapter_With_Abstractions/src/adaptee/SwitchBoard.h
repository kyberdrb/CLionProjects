#pragma once

#include <iostream>
#include "AbstractSwitchBoard.h"

class SwitchBoard : public AbstractSwitchBoard {
    std::string flatPin() override;
    std::string pinCount() override;
};