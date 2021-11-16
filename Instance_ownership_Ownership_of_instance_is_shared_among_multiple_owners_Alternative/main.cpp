#include <memory>
#include <iostream>
#include <cassert>

// Appropriate smart pointer for composition: https://stackoverflow.com/questions/28595337/appropriate-smart-pointer-for-composition/28595486#28595486

class ObjectByValue {};
class OtherThings {};

struct A {
    ObjectByValue obv;

    void doSomething() {
        std::cout << "\tdoing something" << std::endl;
    }

    virtual ~A() = default;
};

struct B : A {
    OtherThings ot;
};

struct C {
    std::shared_ptr<A> a;

    explicit C(std::shared_ptr<A> a) : a(a) {}

    A& getA() const {
        std::cout << "C: accessing 'a'" << std::endl;
        return *a;
    }
};

struct Owner1 {
    std::shared_ptr<A> a;

    explicit Owner1(std::shared_ptr<A> a) : a(a) {}

    A& getA() const {
        std::cout << "Owner1: accessing 'a'" << std::endl;
        return *a;
    }
};

struct Owner2 {
    std::shared_ptr<A> a;

    explicit Owner2(std::shared_ptr<A> a) : a(a) {}

    A& getA() const {
        std::cout << "Owner2: accessing 'a'" << std::endl;
        return *a;
    }
};

int main() {
    std::shared_ptr<A> b = std::make_shared<B>();

    {
        C c(b);
        c.getA().doSomething();
        b.reset();  // dropping ownership of 'b' in Client, i.e. in main
        assert(b == nullptr);
    }

    Owner1 o1(b);
    assert(o1.a == nullptr);
    Owner2 o2(b);
    assert(&o2.getA() == nullptr);


    o1.getA().doSomething();
    o2.getA().doSomething();

    return 0;
}
