//
// Created by admin on 18. 9. 2023.
//

#include "EndiannessConverter.h"

#include <cassert>
#include <iomanip>
#include <iostream>

void EndiannessConverter::deconstructNumberByBytesInLittleEndian(
        uint32_t littleEndianNumber,
        uint8_t arrayForNumberDeconstructionByBytes[4])
{
    std::cout << std::setw(35) << "&arrayForNumberDeconstructionByBytes[0]:   " << static_cast<void*>(arrayForNumberDeconstructionByBytes) << "\n";

    arrayForNumberDeconstructionByBytes[0] = littleEndianNumber & 0xFF;
    arrayForNumberDeconstructionByBytes[1] = (littleEndianNumber >> 8) & 0xFF;
    arrayForNumberDeconstructionByBytes[2] = (littleEndianNumber >> 16) & 0xFF;
    arrayForNumberDeconstructionByBytes[3] =  littleEndianNumber >> 24;
}

uint32_t EndiannessConverter::littleToBigEndian(uint32_t littleEndianNumber) {
    uint8_t numberConvertedFromLittleToBigEndianArray[4] {0};
    assert(sizeof(uint32_t) == 4);

    numberConvertedFromLittleToBigEndianArray[0] =  littleEndianNumber >> 24;
    numberConvertedFromLittleToBigEndianArray[1] = (littleEndianNumber >> 16) & 0xFF;
    numberConvertedFromLittleToBigEndianArray[2] = (littleEndianNumber >>  8) & 0xFF;
    numberConvertedFromLittleToBigEndianArray[3] =  littleEndianNumber        & 0xFF;

    uint32_t numberConvertedFromLittleToBigEndian = *(reinterpret_cast<uint32_t*>(numberConvertedFromLittleToBigEndianArray) );
    // TODO recostruct with union too and assert for equality
    return numberConvertedFromLittleToBigEndian;
}

void EndiannessConverter::littleToBigEndian(uint32_t littleEndianNumber, uint8_t bigEndianNumberArrayOutput[4]) {
    bigEndianNumberArrayOutput[0] =  littleEndianNumber >> 24;
    bigEndianNumberArrayOutput[1] = (littleEndianNumber >> 16) & 0xFF;
    bigEndianNumberArrayOutput[2] = (littleEndianNumber >>  8) & 0xFF;
    bigEndianNumberArrayOutput[3] =  littleEndianNumber        & 0xFF;
}

void EndiannessConverter::deconstructNumberByBytesInBigEndian(
        uint32_t bigEndianNumber,
        uint8_t arrayForNumberDeconstructionByBytes[4])
{
    std::cout << std::setw(35) << "&arrayForNumberDeconstructionByBytes[0]: " << static_cast<void*>(arrayForNumberDeconstructionByBytes) << "\n";

    arrayForNumberDeconstructionByBytes[0] =  bigEndianNumber & 0xFF;
    arrayForNumberDeconstructionByBytes[1] = (bigEndianNumber >> 8) & 0xFF;
    arrayForNumberDeconstructionByBytes[2] = (bigEndianNumber >> 16) & 0xFF;
    arrayForNumberDeconstructionByBytes[3] =  bigEndianNumber >> 24;
}

uint32_t EndiannessConverter::bigToLittleEndian(uint32_t bigEndianNumber) {
    uint8_t littleEndianNumberArray[4] {};

    littleEndianNumberArray[0] =  bigEndianNumber & 0xFF;
    littleEndianNumberArray[1] = (bigEndianNumber >> 8) & 0xFF;
    littleEndianNumberArray[2] = (bigEndianNumber >> 16) & 0xFF;
    littleEndianNumberArray[3] =  bigEndianNumber >> 24;

    uint32_t littleEndianNumber = *(reinterpret_cast<uint32_t*>(littleEndianNumberArray) );
    return littleEndianNumber;
}

void EndiannessConverter::bigToLittleEndian(uint32_t bigEndianNumber, uint8_t littleEndianNumberArrayOutput[4]) {
    littleEndianNumberArrayOutput[0] =  bigEndianNumber >> 24;
    littleEndianNumberArrayOutput[1] = (bigEndianNumber >> 16) & 0xFF;
    littleEndianNumberArrayOutput[2] = (bigEndianNumber >>  8) & 0xFF;
    littleEndianNumberArrayOutput[3] =  bigEndianNumber & 0xFF;
}
