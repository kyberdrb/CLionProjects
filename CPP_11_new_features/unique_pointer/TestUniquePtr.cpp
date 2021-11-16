//
// Created by laptop on 7/30/19.
//

#include "TestUniquePtr.h"

TestUniquePtr::TestUniquePtr() {
    std::cout << "created" << std::endl;
}

void TestUniquePtr::greet() {
    std::cout << "Hello" << std::endl;
}

TestUniquePtr::~TestUniquePtr() {
    std::cout << "destroyed" << std::endl;
}