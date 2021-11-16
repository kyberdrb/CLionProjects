//
// Created by laptop on 7/23/19.
//

#include <iostream>
#include "Auto.h"

void Auto::exercise() {
    auto number = 7;
    auto text = "word";

    std::cout << number << std::endl;
    std::cout << text << std::endl;

    std::cout << std::endl;
    std::cout << test() << std::endl;

    std::cout << std::endl;
    std::cout << templateTest("Hello there") << std::endl;

    std::cout << std::endl;
    std::cout << templateAdd(2, 8) << std::endl;

    std::cout << std::endl;
    std::cout << testGet() << std::endl;
}

auto Auto::test() -> int {
    return 100;
}

template<typename T>
auto Auto::templateTest(T value) -> decltype(value) {
    return value;
}

template<typename T, typename S>
auto Auto::templateAdd(T value1, S value2) -> decltype(value1 + value2) {
    return value1 + value2;
}

int Auto::get() {
    return 999;
}

auto Auto::testGet() -> decltype(get()) {
    return get();
}
