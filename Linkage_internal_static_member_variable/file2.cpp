#include "file2.h"
#include "header.h"

int function2() {
    Foo::staticVariableInitializedOutsideClassOutsideHeader = 10;
    Foo::staticVariableInitializedOutsideClassOutsideHeaderInsideSource = 1024;
    return Foo::staticVariableInitializedOutsideClassOutsideHeader;
}
