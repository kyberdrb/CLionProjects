#include <memory>
#include <iostream>
#include <cassert>

// Appropriate smart pointer for composition: https://stackoverflow.com/questions/28595337/appropriate-smart-pointer-for-composition/28595486#28595486

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

    explicit C(std::weak_ptr<A> a) : a(a) {}
};

int main() {
    std::shared_ptr<A> b = std::make_shared<B>();
    C c(b);

    std::cout << c.a.expired() << std::endl;
    assert(c.a.expired() == 0);

    c.a.lock()->doSomething();

    b.reset();
    assert(b == nullptr);
    b->doSomething();   // I really don't know what is happening. Dereferencing null pointer and the program still goes on...

    assert(c.a.expired() == 1);
    std::cout << c.a.expired() << std::endl;
    assert(c.a.lock() == nullptr);
    std::cout << "\tweak ptr automatically set to nullptr after resetting the original shared ptr" << std::endl;

    auto anotherB = c.a.lock();
    assert(anotherB == nullptr);
    anotherB->doSomething();
    c.a.lock()->doSomething();
    std::cout << "\tHow is this possible that I can access the weak ptr after I resetted the original shared ptr without crashing the program?" << std::endl;
    std::cout << "\tThe shared ptr got resetted to nullptr, as expected. The shared pointer received from the lock function was initialized to nullptr, as expected." << std::endl;
    std::cout << "\tBut the weak ptr wasn't automatically set to nullptr afterwards." << std::endl;
    std::cout << "\tIs this some kind undefined behavior?" << std::endl;

    return 0;
}
