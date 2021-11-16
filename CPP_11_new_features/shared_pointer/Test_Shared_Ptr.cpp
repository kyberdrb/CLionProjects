//
// Created by laptop on 7/30/19.
//

#include <iostream>
#include "Test_Shared_Ptr.h"

Test_Shared_Ptr::Test_Shared_Ptr() {
    std::cout << "created" << std::endl;
}

void Test_Shared_Ptr::greet() {
    std::cout << "Hello" << std::endl;
}

Test_Shared_Ptr::~Test_Shared_Ptr() {
    std::cout << "destroyed" << std::endl;
}