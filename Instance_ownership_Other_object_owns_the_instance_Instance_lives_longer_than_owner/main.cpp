#include <memory>
#include <cassert>

// Appropriate smart pointer for composition: https://stackoverflow.com/questions/28595337/appropriate-smart-pointer-for-composition/28595486#28595486

class ObjectByValue {};
class OtherThings {};

struct A {
    ObjectByValue obv;

    virtual ~A() = default;
};

struct B : A {
    OtherThings ot;
};

struct C {
    A& a;

    explicit C(A& a) : a(a) {}
};

int main() {
    std::unique_ptr<A> b = std::make_unique<B>();
    assert(b != nullptr);
    C c(*b);

    return 0;
}
