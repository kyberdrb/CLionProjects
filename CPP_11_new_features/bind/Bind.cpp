//
// Created by laptop on 7/30/19.
//

#include <iostream>
#include <functional>
#include "Bind.h"
#include "Test.h"

struct Foo
{
    void foo_nonstatic(int, int) {}
    static int foo_static(int, int, int) { return 42;}
};

int add(int a, int b, int c) {
    std::cout << a << ", " << b << ", " << c << std::endl;
    return a + b + c;
}

int run(std::function<int(int, int)> func) {
    return func(7, 3);
}

void Bind::exercise() {
    auto calculate_1 = std::bind(add, 3, 4, 5);
    std::cout << calculate_1() << std::endl;

    std::cout << std::endl;
    auto calculate_1_1 = std::bind(&add, 2, 4, 8);
    std::cout << calculate_1_1() << std::endl;

    std::cout << std::endl;
    auto calculate_2 = std::bind(add,
            std::placeholders::_1,
            std::placeholders::_2,
            std::placeholders::_3);
    std::cout << calculate_2(10, 20, 30) << std::endl;

    std::cout << std::endl;
    auto calculate_3 = std::bind(add,
            std::placeholders::_2,
            std::placeholders::_1,
            100);
    std::cout << calculate_3(10, 20) << std::endl;

    std::cout << std::endl;
    auto calculate_3_1 = std::bind(add,
            std::placeholders::_2,
            std::placeholders::_1,
            100);
    std::cout << run(calculate_3_1) << std::endl;

    std::cout << std::endl;
    auto calculate_5 = std::bind(add,
            std::placeholders::_2,
            std::placeholders::_3,
            std::placeholders::_1);
    std::cout << calculate_5(10, 20, 30) << std::endl;

    std::cout << std::endl;
    auto calculate_6 = std::bind(add,
            std::placeholders::_2,
            std::placeholders::_3,
            std::placeholders::_1);
    std::cout << calculate_6(10, 20, 30) << std::endl;

    std::cout << std::endl;
    Test test;
    auto calculate_7 = std::bind(
            &Test::add,
            test,
            20,
            40,
            60);
    std::cout << calculate_7() << std::endl;

    std::cout << std::endl;
    std::cout << run(calculate_7) << std::endl;

    std::cout << std::endl;
    auto calculate_8 = std::bind(
            (int (*) (int, int, int)) &Test::staticAdd,
            15,
            25,
            35);
    std::cout << calculate_8() << std::endl;
}
