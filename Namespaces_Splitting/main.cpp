#include <iostream>

// Name visibility: Namespaces: http://www.cplusplus.com/doc/tutorial/namespaces/

namespace foo {
    int a = 1;
}

namespace bar {
    int b = 2;
}

void someFunction() {
    // only variable a from foo namespace is accessible
    std::cout << foo::a << "\n";
    std::cout << bar::b << "\n";
}

namespace foo {
    int c = 3;
}

int main() {
    someFunction();

    std::cout << "\n";

    std::cout << foo::a << std::endl;
    std::cout << foo::c << std::endl;
    std::cout << bar::b << std::endl;

    return 0;
}
