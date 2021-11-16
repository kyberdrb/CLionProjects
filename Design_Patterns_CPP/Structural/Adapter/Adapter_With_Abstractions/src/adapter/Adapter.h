#pragma once

#include <string>
#include "../target/AbstractPlug.h"
#include "../adaptee/AbstractSwitchBoard.h"

// Inherit from adaptee
class Adapter : public AbstractPlug {
private:
    // aggregate the target
    AbstractSwitchBoard& _switchBoard;

public:
    Adapter(AbstractSwitchBoard &switchBoard);

    std::string roundPin() override;
    std::string pinCount() override;
};