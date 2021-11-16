#include <iostream>

// Argument-Dependent Lookup: https://abseil.io/tips/49

namespace aspace {
    struct A {};

    template <typename T> struct AGeneric {};

    void func(const A&) {}

    template <typename T> void find_me(const T&) {}
}

namespace bspace {
    typedef aspace::A AliasForA;

    struct B : aspace::A {};

    template <typename T> struct BGeneric {};

    void test() {
        func(B());  // ok: base class namespace searched.
        find_me(BGeneric<aspace::A>()); // ok: template parameter namespace searched.
        find_me(aspace::AGeneric<int>());   // ok: template namespace searched.
    }
}

int main() {
    using bspace::test;

    test();

    return 0;
}
