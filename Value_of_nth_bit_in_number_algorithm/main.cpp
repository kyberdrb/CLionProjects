#include <stdio.h>
#include <stdint.h>
#include <assert.h>

int main() {
    uint32_t number = 0x12345678;

    printf("%X\n", number);

    assert(0 == (number >> 31));
    printf("Bit-shifting maintains the original value of the variable\t->\t%X\n", number);
    assert(0 == (number >> 30));
    assert(0 == (number >> 29));
    assert(1 == (number >> 28));

    assert(0 == (number & 0x00000001));
    assert(0 == (number & 0x00000002));
    assert(0 == (number & 0x00000004));
    assert(8 == (number & 0x00000008));
    assert(8 == (number & 0b00000000000000000000000000001000));
    assert(1 == ((number >> 3) & 1));
    return 0;
}

