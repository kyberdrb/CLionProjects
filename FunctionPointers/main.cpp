#include <iostream>
#include <vector>
#include <algorithm>
#include "Parent.h"
#include "Child.h"
#include "AbstractClassesPureVirtualFunctions/Animal.h"
#include "AbstractClassesPureVirtualFunctions/Dog.h"
#include "AbstractClassesPureVirtualFunctions/Labrador.h"
#include "Functors/MatchTest.h"

void test(int number) {
    std::cout << "Hello: " << number << std::endl << std::flush;
}

std::string test(const std::string& word) {
    std::cout << "Hi, " << word << std::endl << std::flush;
    return "hi";
}

bool match(const std::string& word) {
//    return word == "two";
    return word.length() == 3;
}

uint_fast32_t countString(std::vector<std::string>& strings, bool (*match)(const std::string& test)) {
    uint_fast32_t matches = 0;
    for (const auto& string : strings) {
        if (match(string)) {
            matches++;
        }
    }
    return matches;
}

void printObject(Parent parent) {
    parent.print();
}

void matchText(const std::string& text, Test& matchTest) {
    std::cout << matchTest(text) << std::endl << std::flush;
}

int main() {
    test(7);
    void (*pTest)(int) = test;
    pTest(8);

    std::string (*pTestStr)(const std::string&) = test;
    std::string stringRetVal = pTestStr("Barbie");
    std::cout << stringRetVal << std::endl << std::flush;

    std::cout << std::endl << std::flush;

    std::vector<std::string> texts;
    texts.emplace_back("one");
    texts.emplace_back("two");
    texts.emplace_back("three");
    texts.emplace_back("two");
    texts.emplace_back("four");
    texts.emplace_back("two");
    texts.emplace_back("three");

    std::cout << match("one") << std::endl << std::flush;

    std::cout << std::endl << std::flush;

    uint_fast32_t matchingCount = std::count_if(texts.begin(), texts.end(), match);
    std::cout << matchingCount << std::endl << std::flush;
    std::cout << countString(texts, match) << std::endl;

    std::cout << std::endl << std::flush;

    Child child1;
    Parent& parent1 = child1;
    parent1.print();

    // Copy initialization
    Child child2;
    // Reference to child is missing,
    // therefore the Child part (e.g. private attributes etc.)
    // are hidden i.e. sliced away. This is called 'Object Slicing'.
    // The derived object behaves like its parent object.
    Parent parent2 = child2;
    parent2.print();
    printObject(child2);

    std::cout << std::endl << std::flush;

    Labrador labrador;
    Animal* animal = &labrador;
    animal->run();
    animal->speak();

    std::cout << std::endl << std::flush;

    MatchTest matchTester;
    Test& tester = matchTester;
    std::cout << matchTester("lion") << std::endl << std::flush;
    matchText("lionz", matchTester);

    return 0;
}