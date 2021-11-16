#include <iostream>
#include <vector>
#include <memory>
#include <cassert>

// Appropriate smart pointer for composition: https://stackoverflow.com/questions/28595337/appropriate-smart-pointer-for-composition/28595486#28595486
// Accessing weak_ptr after deleting the original pointer: https://stackoverflow.com/questions/22823281/accessing-weak-ptr-after-deleting-the-original-pointer/22823436#22823436

class ObjectByValue {};
class OtherThings {};

struct A {
    ObjectByValue obv;

    void doSomething() {
        std::cout << "doing something" << std::endl;
    }

    virtual ~A() = default;
};

struct B : A {
    OtherThings ot;
};

struct C {
    std::weak_ptr<A> a;

    explicit C(std::weak_ptr<B> a) : a(a) {}
};

int main() {
    std::shared_ptr<B> b =  std::make_shared<B>();
    C c(b);

    std::cout << "Before Deletion\n";
    {
        auto q = c.a.lock();     // create a new owner
        assert(q != nullptr);
        std::cout << "\tItem exists" << std::endl;
    }   // owner destroyed at the end of the scope

    auto p = c.a.lock();     // create a new owner
    assert(p != nullptr);
    std::cout << "\tItem exists" << std::endl;

    // The resource that the shared pointer owns is deallocated when ALL owners are deallocated
    p.reset();
    assert(p == nullptr);
    b.reset();
    assert(b == nullptr);

    std::cout << "After Deletion\n";
    p = c.a.lock();
    assert(p == nullptr);
    std::wcout << L"\tNull object" << std::endl;
    assert(c.a.expired() == 1);
    std::wcout << L"\tObject expired" << std::endl;

    p->doSomething();
    c.a.lock()->doSomething();
    std::cout << "I still don't understand why the program doesn't crash. I'm dereferencing the null pointer after all..." << std::endl;

    return 0;
}
