#include <iostream>

class MyBase {
public:
    MyBase(int something, float somethingElse) {}
    explicit MyBase(char someChar) {}
};

class MyDerivedOld : public MyBase {
public:
    MyDerivedOld(int a, float b) : MyBase(a, b) {}
    explicit MyDerivedOld(char c) : MyBase(c) {}
};

class MyDerivedModern : public MyBase {
public:
    using MyBase::MyBase;
};

int main() {
    MyDerivedOld myOld(1, 2.3);
    MyDerivedOld myAnotherOld('y');

    MyDerivedModern myModern(4, 5.6);
    MyDerivedModern myAnotherModern('z');

    return 0;
}
