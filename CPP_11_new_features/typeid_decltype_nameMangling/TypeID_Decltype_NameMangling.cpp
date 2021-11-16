//
// Created by laptop on 7/23/19.
//

#include <string>
#include <iostream>
#include "TypeID_Decltype_NameMangling.h"

void TypeID_Decltype_NameMangling::exercise() {
    int zahl = 0;
    double decimalNumber = .0;
    std::string word = "Hello";

    // typeid() deduces type of a variable at
    // runtime using RTTI - Run-time Type Identification
    std::cout << typeid(zahl).name() << std::endl;
    std::cout << typeid(decimalNumber).name() << std::endl;
    std::cout << typeid(word).name() << std::endl;

    std::cout << std::endl;

    // decltype() declares a type for a variable
    // by the type of an existing variable
    decltype(word) typeName = "Bob";
    std::cout << typeid(word).name() << std::endl;
    std::cout << typeName << std::endl;

}
