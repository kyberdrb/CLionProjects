//
// Created by laptop on 7/30/19.
//

#include <memory>
#include "Unique_Pointer.h"
#include "TestUniquePtr.h"

class Temp {
private:
    std::unique_ptr<TestUniquePtr[]> pTest;

public:
    Temp() : pTest(new TestUniquePtr[2]) {}
};

void Unique_Pointer::exercise() {
    std::unique_ptr<int> number(new int);
    *number = 7;
    std::cout << *number << std::endl;

    std::cout << std::endl;
    TestUniquePtr* test2 = new TestUniquePtr;
    delete test2;

    std::cout << std::endl;
    std::unique_ptr<TestUniquePtr> pTest(new TestUniquePtr);
    pTest->greet();

    std::cout << std::endl;
    std::unique_ptr<TestUniquePtr[]> pTests(new TestUniquePtr[2]);
    pTests[1].greet();

    // auto_ptr is an equivalent expression to unique_ptr.
    // auto_ptr was used before C++11 came out for automatic memroy deallocation.
    // Since C++11 is auto_ptr deprecated and replaced by unique_ptr.
    std::cout << std::endl;
    std::auto_ptr<TestUniquePtr> pTestAutoPtr(new TestUniquePtr);
    pTest->greet();

    // auto_ptr is unable to allocate an array of pointers
//    std::auto_ptr<TestUniquePtr[]> pTestsAutoPtr(new TestUniquePtr[2]);

    std::cout << std::endl;
    Temp temp;

    std::cout << std::endl;
}