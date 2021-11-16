//
// Created by laptop on 7/25/19.
//

#include <iostream>
#include "Test.h"

void Test::run() {
    uint_fast32_t three{3};
    uint_fast32_t four{4};

    auto pLambdaLocalVars = [three, four]() {
        std::cout << three << "; " << four << std::endl;
    };
    pLambdaLocalVars();

    auto pLambdaLocalAndInstanceVars = [this, three, four]() {
        std::cout << one << "; " << two << "; " << three << "; " << four << std::endl;
    };
    pLambdaLocalAndInstanceVars();

    auto pLambdaLocalAndInstanceVarsReferenceDemo = [three, this, four]() {
        one = 111;
        std::cout << one << "; " << two << "; " << three << "; " << four << std::endl;
    };
    pLambdaLocalAndInstanceVarsReferenceDemo();
    std::cout << one << "; " << two << "; " << three << "; " << four << std::endl;

    auto pLambdaLocalsByValueAndInstanceVarsByReference = [=, this]() {
        one = 1111;
        std::cout << one << "; " << two << "; " << three << "; " << four << std::endl;
    };
    pLambdaLocalsByValueAndInstanceVarsByReference();
    std::cout << one << "; " << two << "; " << three << "; " << four << std::endl;

    auto pLambdaLocalsByReferenceAndInstanceVarsByReference = [&, this]() {
        one = 11111;
        std::cout << one << "; " << two << "; " << three << "; " << four << std::endl;
    };
    pLambdaLocalsByReferenceAndInstanceVarsByReference();
    std::cout << one << "; " << two << "; " << three << "; " << four << std::endl;
}
