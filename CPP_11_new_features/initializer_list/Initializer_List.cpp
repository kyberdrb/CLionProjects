//
// Created by laptop on 7/24/19.
//

#include <vector>
#include <iostream>
#include "Initializer_List.h"

template <typename T>
class Test {
public:
    Test(std::initializer_list<T> initList) {
        for (auto element: initList) {
            std::cout << element << std::endl;   // object 'element' needs to have overloaded '<<' operator
        }
    }

    void print(std::initializer_list<std::string> fruits) {
        for (auto fruit: fruits) {
            std::cout << fruit << std::endl;
        }
    }
};

void Initializer_List::exercise() {
    std::vector<int> numbers {1, 2, 6, 8};
    std::cout << numbers[2] << std::endl;

    std::cout << std::endl;
    Test<std::string> test({"apples", "oranges", "bananas"});

    std::cout << std::endl;
    test.print({"one", "two", "three"});
}
