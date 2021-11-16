#include <stdint.h>
#include <assert.h>
#include <stdio.h>

bool isBigEndian() {
    union {     // instead of type punning we use union to look at the bytes of the number
        uint32_t number;
        char bytes[sizeof(number)];
    } numberAsBytes = {0x01020304};
    // number in code =                         0x01020304
    // number in memory (big endian) =          01 02 03 04 - MSB (Most Significant Byte), 01, is at the beginning - one-to-one mapping from code to memory;
    // memory addresses order (byte indexes) -> 0  1  2  3      - decreasing numeric significance with increasing memory address
    return numberAsBytes.bytes[0] == 1;
}

bool isLittleEndian() {
    union {
        uint32_t number;
        char bytes[4];
    } numberAsBytes = {0x01020304};
    // number in code =                         0x01020304
    // number in memory (little endian) =       04 42 02 01 - LSB (Least Significant Byte), 01, is at the beginning
    // memory addresses order (byte indexes) -> 0  1  2  3      - decreasing numeric significance with increasing memory address
    return numberAsBytes.bytes[0] == 4;
}

char* detectEndianness() {
    int number = 7;
    char* numberAsByteArray = (char*)&number;   // type punning/aliasing through char* - 'char' is as large as 'byte' - 8 bits
    if (*numberAsByteArray == 7) {    // LSB first -> [0]=07 [1]=00 <- MSB last
        return "little endian";
    }

    return "big endian";    // MSB first
}

int main() {
    assert(!isBigEndian());
    assert(isLittleEndian());

    printf("\n%s\n", detectEndianness());

    return 0;
}

