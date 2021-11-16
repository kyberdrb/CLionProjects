#include "header.h"

int function1() {
    customNamespace::variable = 123;
    return customNamespace::variable;
}