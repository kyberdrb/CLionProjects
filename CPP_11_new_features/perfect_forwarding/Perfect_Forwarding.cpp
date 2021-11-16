//
// Created by laptop on 7/29/19.
//

#include <iostream>
#include "Perfect_Forwarding.h"

void Perfect_Forwarding::exercise() {
    Test test;

    // Scenario: Converting all references to lvalue type
    call_and_convert(test);
    call_and_convert(Test());

    // Scenario: Preserving the reference type whether it's lvalue or rvalue
    std::cout << std::endl;
    call_and_preserve_with_static_cast(test);
    call_and_preserve_with_static_cast(Test());

    std::cout << std::endl;
    call_and_preserve_with_forward(test);
    call_and_preserve_with_forward(Test());
}

template <typename T>
void Perfect_Forwarding::call_and_convert(T&& arg) {
    check(arg);
}

template <typename T>
void Perfect_Forwarding::call_and_preserve_with_static_cast(T&& arg){
    check(static_cast<T&&>(arg));
}

template <typename T>
void Perfect_Forwarding::call_and_preserve_with_forward(T&& arg){
    check(std::forward<T&&>(arg));
}

void Perfect_Forwarding::check(const Test&) {
    std::cout << "L-Value function call" << std::endl;
}

void Perfect_Forwarding::check(Test&&) {
    std::cout << "R-Value function call" << std::endl;
}
