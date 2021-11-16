#include "file1.h"
#include "header.h"

int function1() {
    Foo::staticVariableInitializedOutsideClassOutsideHeader = 123;
    Foo::staticVariableInitializedOutsideClassOutsideHeaderInsideSource = 512;
    return Foo::staticVariableInitializedOutsideClassOutsideHeader;
}