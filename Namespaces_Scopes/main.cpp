#include <iostream>

// Name visibility: Scopes: http://www.cplusplus.com/doc/tutorial/namespaces/

int foo;

void localScope() {
    int bar;
    bar = 0;
}

void otherLocalScope() {
    foo = 1;
    bar = 2;    // error: ‘bar’ was not declared in this scope
}

int main() {

    return 0;
}
