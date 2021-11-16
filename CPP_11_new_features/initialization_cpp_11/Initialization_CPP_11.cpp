//
// Created by laptop on 7/24/19.
//

#include <iostream>
#include <vector>
#include "Initialization_CPP_11.h"

void Initialization_CPP_11::exercise() {
    uint_fast32_t value{4};
    std::cout << value << std::endl;

    uint_fast32_t defaultValue{};
    std::cout << defaultValue << std::endl;

    std::cout << std::endl;
    std::string text{"Hello"};
    std::cout << text << std::endl;

    std::cout << std::endl;
    int values[] {1, 4, 5};
    std::cout << values[0] << std::endl;

    int numbersWithDefaultZeros[5]{};
    std::cout << numbersWithDefaultZeros[3] << std::endl;

    std::cout << std::endl;
    int* pInts = new int[3]{1, 2, 3};
    std::cout << pInts[2] << std::endl;
    delete [] pInts;

    int* pIntsDefaultNullPointer{};
    std::cout << pIntsDefaultNullPointer << std::endl;

    std::cout << std::endl;
    std::vector<std::string> strings{"one", "two", "three"};
    std::cout << strings[1] << std::endl;
}
