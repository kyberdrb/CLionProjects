// Internal and External Linkage in C++: http://www.goldsborough.me/c/c++/linker/2016/03/30/19-34-25-internal_and_external_linkage_in_c++/
// C++ static local function vs global function: https://stackoverflow.com/questions/14742664/c-static-local-function-vs-global-function/14742679#14742679

// Each translation unit which includes a header file with a global static variable receives its own copy of the global
// static variable. Each translation unit then modifies a copy of the global static variable, i.e. the static variable
// is not shared.
// The value of a global static variable in a translation unit after changing its value stays valid after exitting
// out of the block of the function ( e.g. function3(), or value change in main.cpp ). Changes of a global static variable in one translation unit
// affect only this one translation unit.

// So when and why would one make use of internal linkage?
// For objects, it is probably most often a very bad idea to make use of it. The memory cost can be very high for large
// objects given that each translation unit gets its own copy. But mainly, it can really just cause odd, unexpected
// behavior.
// Imagine you had a singleton (a class of which you instantiate only a single instance), and would suddenly end up
// having multiple instances of your “singleton” (one for every translation unit).

#include "file1.h"
#include "file2.h"
#include "header.h"

#include <iostream>

int main() {
    std::cout << function1() << std::endl;
    std::cout << variable << std::endl;

    std::cout << function2() << std::endl;
    std::cout << variable << std::endl;

    std::cout << function3() << std::endl;
    std::cout << variable << std::endl;
    variable = 43;
    std::cout << variable << std::endl;
    return 0;
}
