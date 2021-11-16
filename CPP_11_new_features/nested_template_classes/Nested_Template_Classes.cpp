//
// Created by laptop on 7/23/19.
//

#include <string>
#include <iostream>
#include "Nested_Template_Classes.h"
#include "ring.h"

void Nested_Template_Classes::exercise() {
//    ring<std::string> testRing(3);
//
//    testRing.add("one");
//    testRing.add("two");
//    testRing.add("three");
//    testRing.add("four");
//    testRing.add("five");

    ring<std::string> testRing {"one", "two", "three", "four"};

    for(int wordIndex = 0; wordIndex < testRing.size(); wordIndex++) {
        std::cout << testRing.get(wordIndex) << std::endl;
    }

    std::cout << std::endl;

    for (ring<std::string>::iterator word = testRing.begin(); word != testRing.end(); word++) {
        std::cout << *word << std::endl;
    }

    std::cout << std::endl;

    for (const auto& word : testRing) {
        std::cout << word << std::endl;
    }
}

