#include <iostream>

// Name visibility: using: http://www.cplusplus.com/doc/tutorial/namespaces/

namespace first {
    int x = 5;
}

namespace second {
    double x = 3.1416;
}

int main() {
    {
        using namespace first;
        std::cout << x << std::endl;
    }

    {
        using namespace second;
        std::cout << x << std::endl;
    }
    return 0;
}
