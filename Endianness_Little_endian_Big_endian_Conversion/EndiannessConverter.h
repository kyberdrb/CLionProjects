#pragma once

#include <cstdint>

class EndiannessConverter {
public:
    static uint32_t littleToBigEndian(uint32_t littleEndianNumber);
    static uint32_t littleToBigEndian(uint8_t  littleEndianNumberArray[4]);

    static uint32_t bigToLittleEndian(uint32_t bigEndianNumber);
    static uint32_t bigToLittleEndian(uint8_t  bigEndianNumberArray[4]);
};
