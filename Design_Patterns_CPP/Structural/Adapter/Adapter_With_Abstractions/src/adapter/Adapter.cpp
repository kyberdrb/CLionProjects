#include "Adapter.h"

Adapter::Adapter(AbstractSwitchBoard &switchBoard) : _switchBoard(switchBoard) {}

std::string Adapter::roundPin() {
    return _switchBoard.flatPin();
}

std::string Adapter::pinCount() {
    return _switchBoard.pinCount();
}
