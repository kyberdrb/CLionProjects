//
// Created by laptop on 7/30/19.
//

#include <memory>
#include <iostream>
#include "Shared_Pointer.h"
#include "Test_Shared_Ptr.h"

void Shared_Pointer::exercise() {
//    std::shared_ptr<Test_Shared_Ptr> pTest(new Test_Shared_Ptr);

    std::cout << std::endl;
    std::shared_ptr<Test_Shared_Ptr> pTest2(nullptr);

    {
        // Recommended and more efficient way to create a shared pointer
        // is by using make_shared function
        std::shared_ptr<Test_Shared_Ptr> pTest1 = std::make_shared<Test_Shared_Ptr>();

        pTest2 = pTest1;

        auto pTest3 = pTest2;
    }

    std::cout << "Finished" << std::endl;
}
