// Internal and External Linkage in C++: http://www.goldsborough.me/c/c++/linker/2016/03/30/19-34-25-internal_and_external_linkage_in_c++/
// C++ static local function vs global function: https://stackoverflow.com/questions/14742664/c-static-local-function-vs-global-function/14742679#14742679

// However, one interesting use case could be to hide translation-unit-local helper functions from the global scope.
// Imagine you have a helper function foo in your file1.hpp which you use in file1.cpp,
// but then you also have a helper function foo in your file2.hpp which you use in file2.cpp. The first foo does
// something completely different than the second foo, but you cannot think of a better name for them.
// So, you can declare them both static. Unless you include both file1.hpp and file2.hpp in some same translation unit,
// this will hide the respective foos from each other. If you don’t declare them static, they will implicitly have
// external linkage and the first foo’s definition will collide with the second foos definition and cause a linker
// error due to a violation of the one-definition-rule.

#include "file1.h"
//#include "file2.h"    // if we try to include a header file that has a static function with the same name as some
                        // already included header file, the compiler reports an error: redefinition of ‘int foo()’
                        // That's because we have now two static functions with the same name in the same translation
                        // unit (main.cpp) imported from different header files (file1.h/cpp and file2.h/cpp)

#include <iostream>

int main() {
    std::cout << foo() << std::endl;    // if I only declare a static function in a header file and define it in a cpp
                                        // file, the linker reports an error: undefined reference to `foo()'
                                        // because the file in which the header file is imported sees only the
                                        // declaration of the function, not its implementation in the entire translation
                                        // unit; when we call only a function that has only been defined, the linker
                                        // produces such an error.
                                        // therefore we need to define the function in the header file already,
                                        // and then call that function
    std::cout << useFooInFile1() << std::endl;
    //std::cout << useFooInFile2() << std::endl;
    return 0;
}
