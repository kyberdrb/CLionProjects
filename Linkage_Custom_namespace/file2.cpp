#include "header.h"

int function2() {
    customNamespace::variable = 10;
    return customNamespace::variable;
}

int function3() {
    return customNamespace::variable;
}