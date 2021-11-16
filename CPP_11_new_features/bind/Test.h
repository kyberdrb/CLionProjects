//
// Created by laptop on 7/30/19.
//

#ifndef CPP_11_NEW_FEATURES_TEST_H
#define CPP_11_NEW_FEATURES_TEST_H


#include <iostream>

class Test {
public:
    int add(int a, int b, int c) {
        std::cout << a << ", " << b << ", " << c << std::endl;
        return a + b + c;
    }

    static int staticAdd(int a, int b, int c) {
        std::cout << a << ", " << b << ", " << c << std::endl;
        return a + b + c;
    }
};


#endif //CPP_11_NEW_FEATURES_TEST_H
