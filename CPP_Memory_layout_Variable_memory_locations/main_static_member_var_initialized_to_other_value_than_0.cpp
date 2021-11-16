#include <stdio.h>

struct foo {
    static int globalNumber;
};

int foo::globalNumber = 1;

int doSomething() {
    // static int i = foo::globalNumber;
    // i++;
    foo::globalNumber += 3;
    return foo::globalNumber;
}

int main() {
    foo f;
    doSomething();
    printf("%d\n", foo::globalNumber);
    return 0;
}
