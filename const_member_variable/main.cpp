#include "Foo.h"

#include <iostream>

int main() {
    Foo f(2);
    std::cout << f.getConstMember() << std::endl;
    return 0;
}
