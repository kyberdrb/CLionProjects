#include <stdio.h>
#include <stdint.h>

uint32_t reverseBytes(uint32_t number);
uint32_t reverseHexaDigits(uint32_t number);

int main() {
    uint32_t number = 0x12345678;
    printf("0x%X\n", number); 
    printf("0x%X\n", number = reverseBytes(number)); 
    printf("0x%X\n", number = reverseHexaDigits(number)); 
    printf("0x%X\n", number = reverseHexaDigits(number)); 
    printf("0x%X\n", number = reverseBytes(number)); 
    return 0;
}

uint32_t reverseBytes(uint32_t number) {
    uint32_t numberWithReversedBytes = number;
    numberWithReversedBytes = (numberWithReversedBytes & 0xffff0000) >> 16 | (numberWithReversedBytes & 0x0000ffff) << 16;
    numberWithReversedBytes = (numberWithReversedBytes & 0xff00ff00) >> 8 | (numberWithReversedBytes & 0x00ff00ff) << 8;
    return numberWithReversedBytes;
}

uint32_t reverseHexaDigits(uint32_t number) { 
    uint32_t numberWithReversedBytes = number;
    numberWithReversedBytes = (numberWithReversedBytes & 0x0f0f0f0f) << 4 | (numberWithReversedBytes & 0xf0f0f0f0) >> 4;
    return numberWithReversedBytes;
}

