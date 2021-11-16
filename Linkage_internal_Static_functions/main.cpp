// Internal and External Linkage in C++: http://www.goldsborough.me/c/c++/linker/2016/03/30/19-34-25-internal_and_external_linkage_in_c++/

//#include "file1.h"
//#include "file2.h"
#include "file1_user.h"
#include "file2_user.h"

#include <iostream>

// However, one interesting use case could be to hide translation-unit-local helper functions from the global scope.
// Imagine you have a helper function foo in your file1.hpp which you use in file1.cpp, but then you also have a helper
// function foo in your file2.hpp which you use in file2.cpp.
// The first foo does something completely different than the second foo, but you cannot think of a better name for
// them. So, you can declare them both static. Unless you include both file1.hpp and file2.hpp in some same translation
// unit, this will hide the respective foos from each other. If you don’t declare them static, they will implicitly
// have external linkage and the first foo’s definition will collide with the second foos definition and cause a linker
// error due to a violation of the one-definition-rule.

int main() {
    std::cout << foo() << std::endl;
    std::cout << doSomething() << std::endl;
    std::cout << bar() << std::endl;
//    std::cout << doSomethingElse() << std::endl;
    return 0;
}
