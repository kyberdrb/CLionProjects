#include "header.h"

#include <iostream>

int Foo::staticVariableInitializedOutsideClassOutsideHeaderInsideSource = 256;

// When a function is only declared and not called, everything compiles and links.
// When a function is declared and called, everything compiles, but the linker reports an error 'undefined reference'
//  because when we call a function, the linker needs the definition of the function (the function body) to link it to our final executable.

void Foo::function3() {
    std::cout << Foo::staticVariableInitializedOutsideClassOutsideHeader << "\n"
              << Foo::staticVariableInitializedOutsideClassOutsideHeaderInsideSource << "\n"
              << Foo::constStaticVariableInitInClass << "\n"
              << Foo::constexprNonintegralStaticVariableInitInClass << "\n"
              << std::endl;
}
