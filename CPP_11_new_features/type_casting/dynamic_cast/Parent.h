//
// Created by laptop on 7/29/19.
//

#ifndef CPP_11_NEW_FEATURES_PARENT_H
#define CPP_11_NEW_FEATURES_PARENT_H


#include <iostream>

class Parent {
public:
    virtual void speak() {
        std::cout << "parent!" << std::endl;
    }
};


#endif //CPP_11_NEW_FEATURES_PARENT_H
