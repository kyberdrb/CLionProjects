//
// Created by laptop on 7/24/19.
//

#include <iostream>
#include <vector>
#include "Initialization_CPP_98.h"

class C {
public:
    std::string text;
    uint_fast32_t id;
};

struct S {
    std::string text;
    uint_fast32_t id;
};

struct R {
    std::string text;
    uint_fast32_t id;
} r1 = {"Hello", 7}, r2 = {"Hi", 9};

void Initialization_CPP_98::exercise() {
    int values[] = {1, 4, 5};
    std::cout << values[0] << std::endl;

    std::cout << std::endl;
    C c1 = {"Hello", 7};
    std::cout << c1.text << std::endl;

    std::cout << std::endl;
    S s1 = {"Hello", 7};
    std::cout << s1.text << std::endl;

    std::cout << std::endl;
    std::cout << r1.text << std::endl;
    std::cout << r2.text << std::endl;

    std::cout << std::endl;
    std::vector<std::string> strings;
    strings.emplace_back("One");
    strings.emplace_back("Two");
    strings.emplace_back("Three");
}
