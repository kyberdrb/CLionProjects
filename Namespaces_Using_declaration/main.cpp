#include <iostream>

// Name visibility: using: http://www.cplusplus.com/doc/tutorial/namespaces/

namespace first {
    int x = 5;
    int y = 10;
}

namespace second {
    double x = 3.1416;
    double y = 2.7183;
}

int main() {
    using first::x;
    using second::y;
    std::cout << x << std::endl;
    std::cout << y << std::endl;

    std::cout << std::endl;

    // Accessing variables in namespaces via fully qualified names
    std::cout << second::x << std::endl;
    std::cout << first::y << std::endl;

    return 0;
}
