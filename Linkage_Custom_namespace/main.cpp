// Internal and External Linkage in C++: http://www.goldsborough.me/c/c++/linker/2016/03/30/19-34-25-internal_and_external_linkage_in_c++/

// Global customNamespace::variable in an anonymous namespace behaves the same as a global static customNamespace::variable.
// Each translation unit which includes a header file with a customNamespace::variable in an anonymous namespace receives its own copy
// of this customNamespace::variable. Each translation unit then modifies a copy of the customNamespace::variable in an anonymous namespace, i.e. the
// customNamespace::variable in an anonymous namespace is not shared.
// The value of a customNamespace::variable in an anonymous namespace in a translation unit after changing its value stays valid after
// exitting out of the block of the function ( e.g. function3(), or value change in main.cpp ). Changes of a customNamespace::variable
// in an anonymous namespace in one translation unit affect only this one translation unit.

#include "file1.h"
#include "file2.h"
#include "header.h"

#include <iostream>

// Because the global variable in a custom namespace is exter, i.e. only declared
// in order to use it we need to define/initialize it. We need to do in from the global namespace like this:
//namespace customNamespace {
//    int variable = 13;  // without initialization
//}

// ...or like this
int customNamespace::variable = 13; // this is definition for a global variable in a custom namespace

int main() {
//    customNamespace::variable = 13; // linker error: undefined reference to `customNamespace::variable'
                                    // we need to define/initialize the variable in the global scope
//    int customNamespace::variable = 13; // compiler error: qualified-id in declaration before ‘=’ token

    std::cout << function1() << std::endl;
    std::cout << customNamespace::variable << std::endl;

    std::cout << function2() << std::endl;
    std::cout << customNamespace::variable << std::endl;

    std::cout << function3() << std::endl;
    std::cout << customNamespace::variable << std::endl;
    customNamespace::variable = 43;
    std::cout << customNamespace::variable << std::endl;
    return 0;
}
