//
// Created by laptop on 3/10/23.
//

#include "Derived.h"

#include <iostream>

void Derived::modifyReferenceInternalState() {
    _numberReference++;
    std::cout
        << "'Derived::modifyReferenceInternalState()' called:"
        << "\n"
        << "value of reference attribute '_numberReference' = " << Base::_numberReference;
}
