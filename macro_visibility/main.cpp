#include <iostream>

void bar() {
/// The 'FOO' macro defined in one function is only accessible within the scope of that function.
///  thus it's not shared/exported.

//#define FOO 10
//    std::cout << FOO << std::endl;
}

int main() {
#define FOO 10
    std::cout << FOO << std::endl;
    return 0;
}
