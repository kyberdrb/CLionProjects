#include "Foo.h"

#include <iostream>

int main() {
    Foo f();
    std::cout << Foo::getConstMember() << std::endl;
    return 0;
}
