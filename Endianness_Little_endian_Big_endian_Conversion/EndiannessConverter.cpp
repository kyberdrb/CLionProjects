//
// Created by admin on 18. 9. 2023.
//

#include "EndiannessConverter.h"

#include "NumberUnion.h"

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

uint32_t EndiannessConverter::reconstructNumberAsLittleEndianFromByteArray(const uint8_t numberByteArray[4]) {
    NumberUnion numberUnionLittleEndian{};

    std::cout << "Reconstruct number as little endian:\n";
    for (int16_t byteNumber = 0; byteNumber < 4; ++byteNumber) {
        std::cout << "Byte " << byteNumber << ": " << static_cast<const void*>( &(numberByteArray[byteNumber] ) ) << ": " << "0x" << std::hex << static_cast<uint16_t>(numberByteArray[byteNumber]) << std::dec << "\n";
        numberUnionLittleEndian.array[byteNumber] = numberByteArray[byteNumber];
    }

    // little endian number reconstructed using reinterpret_cast
    const uint32_t reconstructedNumberWithReinterpretCast = *reinterpret_cast<const uint32_t*>(numberByteArray);

    // little endian number reconstructed using union
    const uint32_t reconstructedNumberWithUnion = numberUnionLittleEndian.raw;
    assert(reconstructedNumberWithReinterpretCast == reconstructedNumberWithUnion);
    return reconstructedNumberWithReinterpretCast;
}

uint32_t EndiannessConverter::littleToBigEndian(uint32_t littleEndianNumber) {
    uint8_t numberConvertedFromLittleToBigEndianArray[4] {0};
    assert(sizeof(uint32_t) == 4);

    numberConvertedFromLittleToBigEndianArray[0] =  littleEndianNumber >> 24;
    numberConvertedFromLittleToBigEndianArray[1] = (littleEndianNumber >> 16) & 0xFF;
    numberConvertedFromLittleToBigEndianArray[2] = (littleEndianNumber >>  8) & 0xFF;
    numberConvertedFromLittleToBigEndianArray[3] =  littleEndianNumber        & 0xFF;

    // little endian number converted to big endian using reinterpret_cast
    uint32_t numberConvertedFromLittleToBigEndian = *(reinterpret_cast<uint32_t*>(numberConvertedFromLittleToBigEndianArray) );

    // little endian number converted to big endian using union
    NumberUnion numberConvertedFromLittleToBigEndianUnion{};
    numberConvertedFromLittleToBigEndianUnion.array[0] = numberConvertedFromLittleToBigEndianArray[0];
    numberConvertedFromLittleToBigEndianUnion.array[1] = numberConvertedFromLittleToBigEndianArray[1];
    numberConvertedFromLittleToBigEndianUnion.array[2] = numberConvertedFromLittleToBigEndianArray[2];
    numberConvertedFromLittleToBigEndianUnion.array[3] = numberConvertedFromLittleToBigEndianArray[3];

    assert(numberConvertedFromLittleToBigEndianUnion.raw == numberConvertedFromLittleToBigEndian);

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

uint32_t EndiannessConverter::reconstructNumberAsBigEndianFromByteArray(const uint8_t numberByteArray[4]) {
    std::cout << "Byte 0: " << static_cast<const void*>( &(numberByteArray[0]) ) << ": " << std::hex << "0x" << static_cast<uint16_t>(numberByteArray[0]) << "\n";
    std::cout << "Byte 1: " << static_cast<const void*>( &(numberByteArray[1]) ) << ": " << std::hex << "0x" << static_cast<uint16_t>(numberByteArray[1]) << "\n";
    std::cout << "Byte 2: " << static_cast<const void*>( &(numberByteArray[2]) ) << ": " << std::hex << "0x" << static_cast<uint16_t>(numberByteArray[2]) << "\n";
    std::cout << "Byte 3: " << static_cast<const void*>( &(numberByteArray[3]) ) << ": " << std::hex << "0x" << static_cast<uint16_t>(numberByteArray[3]) << "\n";

    std::cout << "\n";

    // big endian number reconstructed using reinterpret_cast
    uint32_t bigEndianNumber = *(reinterpret_cast<const uint32_t*>(numberByteArray) );

    // big endian number reconstructed using union
    NumberUnion bigEndianNumberUnion{};
    bigEndianNumberUnion.array[0] = numberByteArray[0];
    bigEndianNumberUnion.array[1] = numberByteArray[1];
    bigEndianNumberUnion.array[2] = numberByteArray[2];
    bigEndianNumberUnion.array[3] = numberByteArray[3];

    assert(bigEndianNumberUnion.raw == bigEndianNumber);
    
    return bigEndianNumber;
}

uint32_t EndiannessConverter::bigToLittleEndian(uint32_t bigEndianNumber) {
    uint8_t littleEndianNumberArray[4] {};

    littleEndianNumberArray[0] =  bigEndianNumber & 0xFF;
    littleEndianNumberArray[1] = (bigEndianNumber >> 8) & 0xFF;
    littleEndianNumberArray[2] = (bigEndianNumber >> 16) & 0xFF;
    littleEndianNumberArray[3] =  bigEndianNumber >> 24;

    // big endian number converted to little endian using reinterpret_cast
    uint32_t littleEndianNumber = *(reinterpret_cast<uint32_t*>(littleEndianNumberArray) );

    // big endian number converted to little endian using union
    NumberUnion littleEndianNumberUnion{};
    littleEndianNumberUnion.array[0] = littleEndianNumberArray[0];
    littleEndianNumberUnion.array[1] = littleEndianNumberArray[1];
    littleEndianNumberUnion.array[2] = littleEndianNumberArray[2];
    littleEndianNumberUnion.array[3] = littleEndianNumberArray[3];

    assert(littleEndianNumberUnion.raw == littleEndianNumber);

    return littleEndianNumber;
}

void EndiannessConverter::bigToLittleEndian(uint32_t bigEndianNumber, uint8_t littleEndianNumberArrayOutput[4]) {
    littleEndianNumberArrayOutput[0] =  bigEndianNumber >> 24;
    littleEndianNumberArrayOutput[1] = (bigEndianNumber >> 16) & 0xFF;
    littleEndianNumberArrayOutput[2] = (bigEndianNumber >>  8) & 0xFF;
    littleEndianNumberArrayOutput[3] =  bigEndianNumber & 0xFF;
}
