#pragma once

#include <cstdint>

class EndiannessConverter {
public:
    void deconstructNumberByBytesInLittleEndian(uint32_t number, uint8_t arrayForNumberDeconstructionByBytes[4]);

    uint32_t littleToBigEndian(uint32_t littleEndianNumber);
    void littleToBigEndian(uint32_t littleEndianNumber, uint8_t bigEndianNumberArrayOutput[4]);

    uint32_t littleToBigEndian(uint8_t  littleEndianNumberArray[4]);




    uint32_t bigToLittleEndian(uint32_t bigEndianNumber);
    uint32_t bigToLittleEndian(uint8_t  bigEndianNumberArray[4]);
};
