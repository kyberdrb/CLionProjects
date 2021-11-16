#include <iostream>

// https://wiki.c2.com/?CstyleCasts

// The C-style cast in C++ is incredibly broken, and switching to reinterpret_cast fixes nothing.

// The C-style cast in C++ is defined as:
//   If one of the types is a base class of the other type, then its effect is that of a static_cast.
//   Otherwise its effect is that of a reinterpret_cast. This is why the C-style cast is evil in C++.
//   Its behavior may silently change depending on if it sees the full definitions of the types
//   or just forward declarations of the types.

// Here are some possible scenarios:

// Lines 1, 2, and 3 will compile and will compile to the same code.
// Answer: single inheritance and the full definitions of the types are in scope.

// Lines 1, 2, and 3 will compile. 1 and 2 will compile to the same code, but 3 will compile differently.
// Answer: multiple inheritance, the full definitions of the types are in scope, and luck as sometimes 3 will be the
// same as 1 and 2, sometimes it won't.

// Lines 1 and 3 will compile and compile to the same code. Line 2 will not compile.
// Answer: The types are forward declared. The best part about this is that if later the full definitions come into
// scope, like if someone added a header to another header which your cpp includes, the behavior of the c-style cast
// can silently change. THIS IS WHY YOU NEVER USE THE C-STYLE CAST IN C++ CODE.

// Line 3 will compile. Lines 1 and 2 will not compile.
// Answer 1: It's an ambiguous cast from derived to base, multiple inheritance of the same base class, and not virtually.
// Answer 2: It's a down cast going across virtual inheritance.

// Recommendations:

// 1- Never ever use C-style casts in C++, ever. Ever. I mean it.
// 2- Use reinterpret_casts only if you know what you're doing, specifically if you understand the StrictAliasingRule
//    of C and C++ and how casts are not no-ops when working with multiple or virtual inheritance.

class A {};

class B : public A {};

B* make_new_b() {
    return new B;
}

int main() {
    B* b = make_new_b();

    A* a = (A*) b;   // line 1

    A* a_static_casted = static_cast<A*>(b);    // line 2

    A* a_reinterpret_casted = reinterpret_cast<A*>(b);  // line 3

    delete b;

    return 0;
}
