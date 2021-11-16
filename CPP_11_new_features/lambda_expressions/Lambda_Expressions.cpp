//
// Created by laptop on 7/24/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "Lambda_Expressions.h"
#include "Test.h"
#include "Check.h"

bool match(const std::string& word) {
    return word.length() == 3;
}

void Lambda_Expressions::exercise() {
    auto func = [](){std::cout << "Hello" << std::endl; };
    func();

    std::cout << std::endl;
    test(func);

    std::cout << std::endl;
    test([] () { std::cout << "Hello there" << std::endl; } );

    std::cout << std::endl;
    [](){ std::cout << "Direct lambda call" << std::endl; }();

    std::cout << std::endl;
    auto pGreet = [](const std::string& name){ std::cout << "Hello, " << name << std::endl; };
    pGreet("Greg");
    testGreet(pGreet);

    auto pDivide = [](double a, double b) -> double {
        if (b == 0) {
            return 0;
        }
        return a/b;
    };

    std::cout << std::endl;
    std::cout << pDivide(-8.8, 4) << std::endl;
    std::cout << pDivide(7, 0) << std::endl;
    runDivide(pDivide);

    std::cout << std::endl;
    uint_fast32_t one = 1;
    uint_fast32_t two = 2;
    uint_fast32_t three = 3;

    // Capture selected local variables by value
    [one, two](){ std::cout << one << "; " << two << std::endl; } ();

    // Capture all local variables by value
    [=](){ std::cout << one << "; " << two << "; " << three << std::endl; } ();

    // Capture all local variables by value, and specify variables passed by reference
    [=, &three]() {
        three = 7;
        std::cout << one << "; " << two << "; " << three << std::endl;
    } ();
    std::cout << one << "; " << two << "; " << three << std::endl;

    // Capture all local variables by reference
    [&]() {
        one = 4;
        std::cout << one << "; " << two << "; " << three << std::endl;
    } ();
    std::cout << one << "; " << two << "; " << three << std::endl;

    // Capture all local variables by reference, and specify variables passed by value
    [&, two, three]() {
        one = 1;
        std::cout << one << "; " << two << "; " << three << std::endl;
    } ();

    std::cout << std::endl;
    Test test;
    test.run();

    std::cout << std::endl;
    uint_fast32_t size = 5;
    std::vector<std::string> numbers{"one", "two", "three"};
    auto lambda = [size](std::string& test) { return test.size() == size; };
    uint_fast32_t occurences = std::count_if(numbers.begin(), numbers.end(), lambda);
    std::cout << occurences << std::endl;

    // Class member function as Predicate for count_if is rejected
    occurences = std::count_if(numbers.begin(), numbers.end(), match);
    std::cout << occurences << std::endl;

    Check checkFunctor;
    occurences = std::count_if(numbers.begin(), numbers.end(), checkFunctor);
    std::cout << occurences << std::endl;

    run(lambda);
    run(checkFunctor);
    run(match);

    std::function<int(int, int)> add = [](int a, int b) { return a + b; };
    std::cout << add(4, 7) << std::endl;

    std::cout << std::endl;
    uint_fast32_t cats = 5;
    [cats]() mutable {
        cats = 8;
        std::cout << cats << std::endl;
    } ();

    std::cout << cats << std::endl;
}

void Lambda_Expressions::test(void (*pFunc)()) {
    pFunc();
}

void Lambda_Expressions::testGreet(void (*pGreet)(const std::string&)) {
    pGreet("Phil");
}

void Lambda_Expressions::runDivide(double (*pDivide)(double, double)) {
    auto divisionResult = pDivide(10, 4);
    std::cout << divisionResult << std::endl;
}

bool Lambda_Expressions::check(std::string& word) {
    return word.size() == 3;
}

void Lambda_Expressions::run(std::function<bool(std::string&)> checkFunction) {
    std::string word = "stars";
    std::cout << checkFunction(word) << std::endl;
}
