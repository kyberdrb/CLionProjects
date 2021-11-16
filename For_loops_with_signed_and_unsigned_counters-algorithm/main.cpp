#include <stdint.h>
#include <stdio.h>

int main() {
    const size_t UPPER_BOUND = 4;
    //for loop - signed - upwards
    for (int32_t counter = 0; counter < UPPER_BOUND; ++counter) {
        printf("%d ", counter);
    }

    printf("\n\n");

    //for loop - signed - downwards
    for (int32_t counter = UPPER_BOUND - 1; counter >= 0; --counter) {
        printf("%d ", counter);
    }

    printf("\n\n");

    // unsigned integer - overflow property
    for (   uint32_t unsignedNumber = UINT32_MAX - 1, j = 0; 
            j < UPPER_BOUND; 
            ++unsignedNumber, ++j) 
    {
        printf("%u ", unsignedNumber);
    }

    printf("\n\n");

    //for loop - unsigned - upwards - continuation condition uses overflow property of unsigned integers: UINT_MAX -> 0
    for (   uint32_t counter = UINT32_MAX - 2; 
            counter >= UINT32_MAX - 2; 
            ++counter) 
    {
        printf("%u ", counter);
    }

    printf("\n\n");

    // unsigned integer - underflow property
    for (   uint32_t unsignedNumber = 1, j = 0; 
            j < UPPER_BOUND;
            --unsignedNumber, ++j)
    {
        printf("%u ", unsignedNumber);
    }

    printf("\n\n");

    //for loop - unsigned - downwards - continuation condition uses underflow property of unsigned integers: 0 -> UINT_MAX
    for (uint32_t counter = 3 - 1;  counter < 3;    --counter) {
        printf("%u ", counter);
    }
    printf("\n"); 
    for (uint32_t counter = 3;      counter > 0;    --counter) {    // relying on unsigned integer range - stopping before lower bound: 0
        printf("%u ", counter - 1);
    }
    printf("\n");
    for (uint32_t counter = 3 - 1;  counter > 0;    --counter) {    // relying on unsigned integer range - stopping before lower bound: 0
        printf("%u ", counter - 1);
    }
    printf("\n");
    //for (uint32_t counter = 3 - 1;  counter >= 0;   --counter) {    // infinite loop: counter value: [1]: 2; [2]: 1; [3]: 0; [4]: 4294967295 underflow => infinite loop
    //    printf("%u ", counter - 1);
    //}

    printf("\n");

    return 0;
}
