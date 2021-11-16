//
// Created by laptop on 7/24/19.
//

#include <cstdint>
#include <string>
#include <ostream>
#include <iostream>
#include "Object_Initialization_Default_Delete.h"

class Test {
    uint_fast32_t id {3};
    std::string name {"Markus"};

public:
    Test() = default;
    Test(uint_fast32_t id): id(id) {}
    Test(const Test& other) = delete;
    Test& operator=(const Test& other) = delete;
    friend std::ostream& operator<<(std::ostream& os, const Test& test) {
        os << test.id << "; " << test.name;
        return os;
    }
    };

void Object_Initialization_Default_Delete::exercise() {
    Test test;
    std::cout << test << std::endl;

//    Deleted copy constructor
//    Test test2 = test;
//    std::cout << test2 << std::endl;

//    Deleted assignment operator
//    Test test3;
//    test3 = test;
//    std::cout << test3 << std::endl;
}
