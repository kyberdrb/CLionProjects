#include <stdio.h>
#include <stdint.h>
#include <assert.h>

void convertNumberToBitsGrouppedByFour(size_t number, size_t sizeOfNumberInBytes) {
    const uint8_t NUMBER_OF_BITS_IN_BYTE = 8;
    size_t numberOfBitsInNumber = sizeOfNumberInBytes * NUMBER_OF_BITS_IN_BYTE;
    for (   size_t bitPositionFromRight = numberOfBitsInNumber;
            bitPositionFromRight > 0; 
            --bitPositionFromRight)
    {
        printf("%d", (number >> bitPositionFromRight - 1) & 1);

        if ((bitPositionFromRight - 1) % 4 == 0) {
            printf(" ");
        }
    }
    
}

int main() {
    uint32_t number = 0x12345678;

    printf("Abstraction test #1:\n");
    printf("%d", (number >> 31) & 1);
    printf("%d", (number >> 30) & 1);
    printf("%d", (number >> 29) & 1);
    printf("%d", (number >> 28) & 1);

    printf("\n\n");

    printf("Abstraction test #2:\n");
    assert(31 == sizeof(number) * 8 - 1);

    printf("%d", (number >> sizeof(number) * 8 - 1) & 1);
    printf("%d", (number >> sizeof(number) * 8 - 2) & 1);
    printf("%d", (number >> sizeof(number) * 8 - 3) & 1);
    printf("%d", (number >> sizeof(number) * 8 - 4) & 1);

    printf("\n\n"); 

    printf("for-loop binary interpretation:\n");
    printf("sizeof(size_t):\t%zu\n", sizeof(size_t));
    printf("sizeof(number):\t%zu\n", sizeof(number));

    
    const uint8_t NUMBER_OF_BITS_IN_BYTE = 8;
    size_t numberOfBitsInNumber = sizeof(number) * NUMBER_OF_BITS_IN_BYTE;
    for (   size_t bitPositionFromRight = numberOfBitsInNumber;
            bitPositionFromRight > 0; 
            --bitPositionFromRight)
    {
        printf("%d", (number >> bitPositionFromRight - 1) & 1);

        if ((bitPositionFromRight - 1) % 4 == 0) {
            printf(" ");
        }
    }
    
    printf("\n"); 

    size_t biggerNumber = 0x0123456789ABCDEF;
    numberOfBitsInNumber = sizeof(biggerNumber) * NUMBER_OF_BITS_IN_BYTE;
    for (   size_t bitPositionFromRight = numberOfBitsInNumber;
            bitPositionFromRight > 0; 
            --bitPositionFromRight)
    {
        printf("%d", (biggerNumber >> bitPositionFromRight - 1) & 1);

        if ((bitPositionFromRight - 1) % 4 == 0) {
            printf(" ");
        }
    }
    
    printf("\n\n"); 

    printf("uint32_t number:\t");
    convertNumberToBitsGrouppedByFour(number, sizeof(number));

    printf("\n"); 

    printf("size_t number:\t\t");
    convertNumberToBitsGrouppedByFour(biggerNumber, sizeof(biggerNumber));

    printf("\n"); 

    double doublePrecisionNumber = 123456789.987654321;
    printf("double number:\t\t");
    convertNumberToBitsGrouppedByFour(doublePrecisionNumber, sizeof(doublePrecisionNumber));

    printf("\n"); 

    float singlePrecisionNumber = 12345.6789;
    printf("float number:\t\t");
    convertNumberToBitsGrouppedByFour(singlePrecisionNumber, sizeof(singlePrecisionNumber));

    printf("\n\n"); 

    size_t a[10];
    for (size_t i = 0; i != 10; ++i)
        a[i] = i;

    for (size_t i = 10 - 1; i < 10; --i)    // warum ist die Bedingung bei dieser Schleife so komisch? Warum nicht i<=0? Weil 'size_t' 'unsigned' ist?
         printf("%d ", a[i]);

    printf("\n\n"); 

    for (size_t i = 2, j = 0; j < 5; --i, ++j) {    // checking why the condition for an unsigned integer in the for loop's stopping condition
                                                    // is different than with signed integers;
                                                    // but now I see, why I was wondering about the stopping condition in the for loop with unsigned integer (size_t) etc.:
                                                    //   we use the fact that the unsigned integer overflows/underflows. When it underflows, the number goes from
                                                    //   0 to its maximum value. When it overflows, the number goes from its maximum value to 0.
                                                    // This behavior is defined by the standard, and this behavior is expected and consistent.
                                                    // On the other hand, overflow and underflow with signed integers results in Undefined Behavior (UB).
        if (i > 2) {
            printf("underflow occured - possible risk of infinite loop\n");
        }        

        printf("%u\n", i);
    }

    printf("\n"); 

    return 0;
}

