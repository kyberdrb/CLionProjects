#include "header.h"

float qux = 1.3;

void foo(float number) {
    number += 1.0;
}

int main() {
    foo(qux);
    return 0;
}

