//
// Created by laptop on 7/26/19.
//

#ifndef CPP_11_NEW_FEATURES_PARENT_H
#define CPP_11_NEW_FEATURES_PARENT_H


#include <cstdint>
#include <string>
#include <iostream>

class Parent {
private:
    uint_fast32_t dogs;
    std::string text;

public:
    Parent(): Parent("hello"){
        dogs = 5;
        std::cout << "No parameter parent constructor" << std::endl;
    }

    Parent(std::string text) {
        dogs = 5;
        this->text = text;
        std::cout << "string parent constructor" << std::endl;
    }

};


#endif //CPP_11_NEW_FEATURES_PARENT_H
