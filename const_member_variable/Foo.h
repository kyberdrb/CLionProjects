#pragma once

class Foo {
    const int constMember;   // const member deletes default constructor

public:
    // Foo() {
    //     this->constMember = 0;   // error: uninitialized const member in ‘const int’
    // }                            //   const member variable cannot be initialized in constructor's body

    Foo(int constMember) : constMember(constMember) {}

    int getConstMember() const {
        return this->constMember;
    }
};
