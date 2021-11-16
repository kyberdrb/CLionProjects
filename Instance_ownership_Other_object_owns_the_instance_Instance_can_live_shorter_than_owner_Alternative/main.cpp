#include <iostream>
#include <vector>
#include <memory>
#include <cassert>

// Appropriate smart pointer for composition: https://stackoverflow.com/questions/28595337/appropriate-smart-pointer-for-composition/28595486#28595486
// Accessing weak_ptr after deleting the original pointer: https://stackoverflow.com/questions/22823281/accessing-weak-ptr-after-deleting-the-original-pointer/22823436#22823436

struct Test {
    int value;

    Test() : value(10) {}
};

int main() {
    std::shared_ptr<Test> pTest =  std::make_shared<Test>();
    std::weak_ptr<Test> weakTest = pTest;

    std::cout << "Before Deletion\n";
    {
        auto q = weakTest.lock();     // create a new owner
        assert(q != nullptr);
        std::cout << "\tItem not null: " << q->value << std::endl;
    }   // owner destroyed at the end of the scope

    auto p = weakTest.lock();     // create a new owner
    assert(p != nullptr);
    std::cout << "\tItem not null: " << p->value << std::endl;

    // The resource that the shared pointer owns is deallocated when ALL owners are deallocated
    p.reset();
    pTest.reset( );

    std::cout << "After Deletion\n";
    p = weakTest.lock();
    assert(p == nullptr);
    std::wcout << L"\tNull object" << std::endl;
    assert(weakTest.expired() == 1);
    std::wcout << L"\tObject expired" << std::endl;

    return 0;
}