#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cassert>

// Type punning: https://en.wikipedia.org/wiki/Type_punning

bool isNegative(float decimalNumber);

int main() {
    printf("\n---------------------------------------------------\n");
    
    printf("sizeof(unsigned int) =\t%d\n", sizeof(unsigned int));
    printf("sizeof(float) =\t\t%d\n", sizeof(float));

    assert(sizeof(unsigned int) == sizeof(float));

    printf("---------------------------------------------------");
    printf("\nWe're lucky. No undefined behavior occurs\nbecause 'unsigned int' and 'float' have the same size on this platform.\n");
    printf("---------------------------------------------------\n\n");

    float positiveDecimal = 1.2;
    printf("%d\n", isNegative(positiveDecimal));

    float negativeDecimal = -3.4;
    printf("%d\n", isNegative(negativeDecimal));

    return 0;
}

bool isNegative(float decimalNumber) {
    unsigned int* naturalNumber = reinterpret_cast<unsigned int*>(&decimalNumber);  // type punning, i.e. strict aliasing rule broken
    return *naturalNumber & 0x80000000;    // assuming that the floating point number is in the IEEE-754 bit-representation
}

