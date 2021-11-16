//
// Created by laptop on 7/29/19.
//

#include "Static_Cast.h"

class Brother : public Parent {};

class Sister : public Parent {};

void Static_Cast::exercise() {
    float value = 3.23;
    std::cout << (int) value << std::endl;
    std::cout << int(value) << std::endl;

    // Static cast works at compile time.
    std::cout << static_cast<int>(value) << std::endl;

    Parent parent;
    Brother brother;

    std::cout << std::endl;
    Parent* pp = &brother;
    Brother* pb = static_cast<Brother*>(&parent);

    Parent* ppb = &brother;
    Brother* pbb = static_cast<Brother*>(ppb);

    Parent&& p = Parent();
    // passing an L-Value to a variable with R-Value reference type
    Parent&& p_2 = static_cast<Parent&&>(parent);
    p.speak();

    passLvalueToRvalueParameter(static_cast<Parent&&>(parent));
}

void Static_Cast::passLvalueToRvalueParameter(Parent&& parent) {
    parent.speak();
}