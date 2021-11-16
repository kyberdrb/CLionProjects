// C++ static local function vs global function: https://stackoverflow.com/questions/14742664/c-static-local-function-vs-global-function/14742679#14742679

#include "file1.h"
//#include "file2.h"    // if we try to include a header file that has a glboal static function with the same name and
                        // some other included header file has a global function with the same signature,
                        // the compiler reports an error: redefinition of ‘int foo()’
                        // That's because we have now one static function and one global function with the same name
                        // in the same translation unit (main.cpp) imported from different header files (file1.h/cpp and file2.h/cpp)

#include <iostream>

int main() {
    std::cout << foo() << std::endl;

    return 0;
}
