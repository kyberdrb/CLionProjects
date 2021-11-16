#include <iostream>

static int* object = new int(42);   // doesn't leak

int doSomething() {
    static int foo = 3;
    return foo;
}

int doSomethingElse() {
    static int foo = 44;
    return foo;
}

int main() {
    static int* object = new int(42);   // doesn't leak

    std::cout << doSomething() << std::endl;

    std::cout << std::endl;

    int bar = doSomething();
    bar = 4;    // modifying a copy
    std::cout << bar << std::endl;
    std::cout << doSomething() << std::endl;
    std::cout << doSomething() << std::endl;
    std::cout << doSomething() << std::endl;
    std::cout << doSomething() << std::endl;
    std::cout << doSomething() << std::endl;

    return 0;
}
