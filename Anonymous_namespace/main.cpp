// Internal and External Linkage in C++: http://www.goldsborough.me/c/c++/linker/2016/03/30/19-34-25-internal_and_external_linkage_in_c++/
// C++ static local function vs global function: https://stackoverflow.com/questions/14742664/c-static-local-function-vs-global-function/14742679#14742679
// Are objects in anonymous namespace implicitly static?: https://stackoverflow.com/questions/13396748/are-objects-in-anonymous-namespace-implicitly-static/13396843#13396843

// Global variable in an anonymous namespace behaves the same as a global static variable.
// Each translation unit which includes a header file with a variable in an anonymous namespace receives its own copy
// of this variable. Each translation unit then modifies a copy of the variable in an anonymous namespace, i.e. the
// variable in an anonymous namespace is not shared.
// The value of a variable in an anonymous namespace in a translation unit after changing its value stays valid after
// exitting out of the block of the function ( e.g. function3(), or value change in main.cpp ). Changes of a variable
// in an anonymous namespace in one translation unit affect only this one translation unit.

#include "file1.h"
#include "file2.h"
#include "header.h"

#include <iostream>

int main() {
    std::cout << function1() << std::endl;
    std::cout << function2() << std::endl;
    std::cout << function3() << std::endl;
    std::cout << std::endl;

    std::cout << ::variable << std::endl;
    variable = 43;
    std::cout << variable << std::endl;
    return 0;
}
