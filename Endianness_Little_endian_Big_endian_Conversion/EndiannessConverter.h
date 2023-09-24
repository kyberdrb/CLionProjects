#pragma once

#include <cstdint>

class EndiannessConverter {
public:
    void deconstructNumberByBytesInLittleEndian(uint32_t littleEndianNumber, uint8_t arrayForNumberDeconstructionByBytes[4]);
    uint32_t reconstructNumberAsLittleEndianFromByteArray(const uint8_t numberByteArray[4]);
    uint32_t littleToBigEndian(uint32_t littleEndianNumber);
    void littleToBigEndian(uint32_t littleEndianNumber, uint8_t bigEndianNumberArrayOutput[4]);

    void deconstructNumberByBytesInBigEndian(uint32_t bigEndianNumber, uint8_t arrayForNumberDeconstructionByBytes[4]);
    uint32_t reconstructNumberAsBigEndianFromByteArray(const uint8_t numberByteArray[4]);
    uint32_t bigToLittleEndian(uint32_t bigEndianNumber);
    void bigToLittleEndian(uint32_t bigEndianNumber, uint8_t littleEndianNumberArrayOutput[4]);
};
