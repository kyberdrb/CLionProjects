#pragma once

class Foo {
    static const int constMember = 2;   // const member deletes default constructor

public:
    Foo() {
    //    constMember = 0;
    }

    //Foo(int constMember) : constMember(constMember) {}

    static int getConstMember() {
        return constMember;
    }
};
