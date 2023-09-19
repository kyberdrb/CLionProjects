//
// Created by admin on 18. 9. 2023.
//

#include "EndiannessConverter.h"

#include <cassert>

void EndiannessConverter::deconstructNumberByBytesInLittleEndian(
        uint32_t number,
        uint8_t arrayForNumberDeconstructionByBytes[4])
{
    arrayForNumberDeconstructionByBytes[0] =  number        & 0xFF;
    arrayForNumberDeconstructionByBytes[1] = (number >>  8) & 0xFF;
    arrayForNumberDeconstructionByBytes[2] = (number >> 16) & 0xFF;
    arrayForNumberDeconstructionByBytes[3] =  number >> 24;
}

uint32_t EndiannessConverter::littleToBigEndian(uint32_t littleEndianNumber) {
    uint8_t numberConvertedFromLittleToBigEndianArray[4] {0};
    assert(sizeof(uint32_t) == 4);

    numberConvertedFromLittleToBigEndianArray[0] =  littleEndianNumber >> 24;
    numberConvertedFromLittleToBigEndianArray[1] = (littleEndianNumber >> 16) & 0xFF;
    numberConvertedFromLittleToBigEndianArray[2] = (littleEndianNumber >>  8) & 0xFF;
    numberConvertedFromLittleToBigEndianArray[3] =  littleEndianNumber        & 0xFF;

    uint32_t numberConvertedFromLittleToBigEndian = *(reinterpret_cast<uint32_t*>(numberConvertedFromLittleToBigEndianArray) );
    return numberConvertedFromLittleToBigEndian;
}

void EndiannessConverter::littleToBigEndian(uint32_t littleEndianNumber, uint8_t bigEndianNumberArrayOutput[4]) {
    bigEndianNumberArrayOutput[0] =  littleEndianNumber >> 24;
    bigEndianNumberArrayOutput[1] = (littleEndianNumber >> 16) & 0xFF;
    bigEndianNumberArrayOutput[2] = (littleEndianNumber >>  8) & 0xFF;
    bigEndianNumberArrayOutput[3] =  littleEndianNumber        & 0xFF;
}

uint32_t EndiannessConverter::littleToBigEndian(uint8_t *littleEndianNumberArray) {
    return 0;
}

uint32_t EndiannessConverter::bigToLittleEndian(uint32_t bigEndianNumber) {
    return 0;
}

uint32_t EndiannessConverter::bigToLittleEndian(uint8_t *bigEndianNumberArray) {
    return 0;
}
