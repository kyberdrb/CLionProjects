#include <iostream>

// Name visibility: Namespaces: http://www.cplusplus.com/doc/tutorial/namespaces/

// Namespaces: multiple functions or variables with the same name in different contexts/scopes/modules/namespaces.

using namespace std;

namespace foo {
    int value() {
        return 5;
    };

//    double value() {    // error: ambiguating new declaration of ‘double foo::value()’
//        return 3.4;
//    }
}

namespace bar {
    const double pi = 3.1416;

    double value() {
        return 2 * pi;
    }
}

int main() {
    cout << foo::value() << "\n";
    cout << bar::value() << "\n";
    cout << bar::pi << "\n";

    return 0;
}
