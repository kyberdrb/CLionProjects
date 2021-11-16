//
// Created by laptop on 7/23/19.
//

#include <iostream>
#include <vector>
#include "Range_based_loop.h"

void Range_based_loop::exercise() {
    auto texts = {"one", "two", "three"};

    for(auto word : texts) {
        std::cout << word << std::endl;
    }

    std::cout << std::endl;
    std::vector<int> numbers;
    numbers.emplace_back(5);
    numbers.emplace_back(7);
    numbers.emplace_back(9);
    numbers.emplace_back(11);

    for(auto number : numbers) {
        std::cout << number << std::endl;
    }

    std::cout << std::endl;
    std::string greeting = "Hello";

    for(auto character : greeting) {
        std::cout << character << std::endl;
    }
}
