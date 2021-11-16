#include <iostream>

// Name visibility: Scopes: http://www.cplusplus.com/doc/tutorial/namespaces/

int main() {
    int x;
    x = 0;
    double x;   // error: conflicting declaration ‘double x’
    x = 0.0;

    return 0;
}
