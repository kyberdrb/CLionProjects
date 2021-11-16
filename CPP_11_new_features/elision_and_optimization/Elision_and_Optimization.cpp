//
// Created by laptop on 7/26/19.
//

#include <iostream>
#include <vector>
#include "Elision_and_Optimization.h"
#include "TestOptimizationCandidate.h"

TestOptimizationCandidate getTest() {
    return TestOptimizationCandidate("from method");
}

void Elision_and_Optimization::exercise() {
    // To see the copy elision in action,
    //   1. go to CMakeLists.txt and uncomment the line marked for this exercise
    //   2. comment out move constructor and move assignment operator
    TestOptimizationCandidate test1 = getTest();
    std::cout << test1 << std::endl;

    std::cout << std::endl;
    std::vector<TestOptimizationCandidate> vec;
    vec.emplace_back(TestOptimizationCandidate("from vector"));
    vec.pop_back();

    // variable 'value1' is a L-Value
    // beacuse we can find out the address of (&) it
    int value1 = 7;
    int* pValue1 = &value1;

    // '7' is an R-Value
    // therefore we can not use the address of (&) operator
//    int *pValue2 = &7;

    TestOptimizationCandidate* pTest1 = &test1;

    // The return value1 of a function is an R-Value
//    TestOptimizationCandidate* pTest2 = &(getTest());

    int* pValue3 = &++value1;
    std::cout << *pValue3 << std::endl;

    // the result of the '++' operator is an temporary object
    // which is a R-Value
    // therefore we can not find out the address of the result
//    int* pValue4 = &value1++;

    // Addition is an expression, which is a R-Value
//    int* s = &(7 + value1);

    std::cout << std::endl;
    TestOptimizationCandidate& lRefTest = test1;

    // A temporary can only bind to constant reference
    // just like in copy constructor,
    // otherwise a compilation error occurs.
    // By using constant reference we can extend the lifetime of a temporary object.
//    TestOptimizationCandidate& rTestFromFunction1 = getTest();        // does not work
    const TestOptimizationCandidate& rTestFromFunction2 = getTest();

    // The constructor call is a R-Value
    TestOptimizationCandidate test2(TestOptimizationCandidate(1));

    // lvalue reference binds to a lvalue
    // i.e. to an object to which we can apply the address of operator '&'
    TestOptimizationCandidate& test3 = test2;

    TestOptimizationCandidate&& test4 = getTest();

    check(test3);
    check(test4);
    check(getTest());
    check(TestOptimizationCandidate());

    int num = 11;
    workWithLvalue(++num);
    workWithRvalue(num++);
    std::cout << num << std::endl;

    std::cout << std::endl;
    // Invoke the move constructor
    vec.emplace_back(TestOptimizationCandidate());
    TestOptimizationCandidate test5 = getTest();

    std::cout << std::endl;
    // Invoke the move assignment operator
    TestOptimizationCandidate test6;
    test6 = getTest();

    std::cout << std::endl;
}

void Elision_and_Optimization::check(const TestOptimizationCandidate &) {
    std::cout << "lvalue function called" << std::endl;
}

void Elision_and_Optimization::check(TestOptimizationCandidate &&) {
    std::cout << "rvalue function called" << std::endl;
}

void Elision_and_Optimization::workWithLvalue(int& number) {
    std::cout << "lvalue function called: " << number << std::endl;
}

void Elision_and_Optimization::workWithRvalue(int&& number) {
    std::cout << "rvalue function called: " << number << std::endl;
}
