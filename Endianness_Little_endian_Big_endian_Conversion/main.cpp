#include <iostream>
#include <cstdint>

int main() {
    uint32_t number_raw = 0x10203040;

    std::cout << "uint32_t number_raw = " << std::hex << "0x" << number_raw << "\n";

    union NumberUnion{
        uint32_t numberRaw;
        uint8_t numberArray[4];
    };

    NumberUnion numberCurrentEndian{};
    numberCurrentEndian.numberRaw = number_raw;

    printf("'number_raw' address:          %p\n", &numberCurrentEndian.numberArray[0]);

    for (int8_t byteNumber = 0; byteNumber < 4; ++byteNumber) {
        std::cout
            << "Byte number: " << static_cast<uint16_t>(byteNumber) << " | "
            << "Byte address: " <<  static_cast<void*>(&numberCurrentEndian.numberArray[byteNumber]) << " = "
            << std::hex << "0x" << static_cast<uint16_t>(numberCurrentEndian.numberArray[byteNumber]) << "\n";
    }

    std::cout << "\n";

    if (numberCurrentEndian.numberArray[0] == 0x40) {
        std::cout << "The CPU is of little endian type, as the LSB is at the 0th byte, i. e. the lowest address.\n";
    }

    std::cout << "----\n";
    std::cout << "Convert 'number_raw' to big endian format:\n";

    uint8_t number_array_big_endian[4];
                                                           // byte:   0th      1st      2nd      3rd
                                                           // note:  (MSB)                      (LSB)
                                                           // value:  0x10     0x20     0x30     0x40
    number_array_big_endian[0] = number_raw >> 24;              //  00010000 00100000 00110000 01000000 >> 24                                                              = 00000000 00000000 00000000 00010000 = 0x10 (0th byte = MSB)
    number_array_big_endian[1] = (number_raw >> 16) & 0xFF;     // (00010000 00100000 00110000 01000000 >> 16) & 11111111 = 00000000 00000000 00010000 00100000 & 11111111 = 00000000 00000000 00000000 00100000 = 0x20 (1st byte)
    number_array_big_endian[2] = (number_raw >> 8) & 0xFF;      // (00010000 00100000 00110000 01000000 >>  8) & 11111111 = 00000000 00010000 00100000 00110000 & 11111111 = 00000000 00000000 00000000 00110000 = 0x30 (2nd byte)
    number_array_big_endian[3] = number_raw & 0xFF;             //  00010000 00100000 00110000 01000000        & 11111111                                                  = 00000000 00000000 00000000 01000000 = 0x40 (3rd byte = LSB)

    std::cout << "reading a number encoded as big endian in a big-endian-CPU-way:\n"
                 "from MSB [0th byte] to LSB [3rd byte] = DECODED AS SAME NUMBER WITH BIG ENDIAN CPU - different with little endian CPU\n";
    uint8_t big_endian_number_decoded_as_big_endian[4];
    uint8_t big_endian_number_converted_to_little_endian[4];
    uint8_t destinationByteNumber {3};

    NumberUnion big_endian_number_decoded_as_big_endian_union{};
    NumberUnion big_endian_number_converted_to_little_endian_union{};

    for (int8_t sourceByteNumber = 0; sourceByteNumber < 4; ++sourceByteNumber) {
        std::cout << std::hex << "0x" << static_cast<uint16_t>(number_array_big_endian[sourceByteNumber]) << "\n";

        big_endian_number_decoded_as_big_endian[sourceByteNumber] = number_array_big_endian[sourceByteNumber];
        big_endian_number_converted_to_little_endian[destinationByteNumber] = number_array_big_endian[sourceByteNumber];

        big_endian_number_decoded_as_big_endian_union.numberArray[sourceByteNumber] = number_array_big_endian[sourceByteNumber];
        big_endian_number_converted_to_little_endian_union.numberArray[destinationByteNumber] = number_array_big_endian[sourceByteNumber];

        --destinationByteNumber;
    }

    std::cout << "\nReconstruct number with reinterpret_cast\n";
    std::cout << std::hex << "0x" << *(reinterpret_cast<uint32_t*>(big_endian_number_decoded_as_big_endian) ) << "\n";
    std::cout << std::hex << "0x" << *(reinterpret_cast<uint32_t*>(big_endian_number_converted_to_little_endian) ) << "\n";
    std::cout << "\nReconstruct number with union\n";
    std::cout << std::hex << "0x" << big_endian_number_decoded_as_big_endian_union.numberRaw << "\n";
    std::cout << std::hex << "0x" << big_endian_number_converted_to_little_endian_union.numberRaw << "\n";

    std::cout << ":\n";

    std::cout << "reading a number encoded as little endian without conversion in a little-endian-CPU-way:\n"
                 "from MSB [3rd byte] to LSB [0th byte] = DECODED AS DIFFERENT NUMBER WITH BIG ENDIAN CPU\n";
    uint8_t big_endian_number_decoded_as_little_endian[4];
    uint8_t big_endian_number_converted_to_little_endian_2[4];
    int8_t destination_byte_number {0};

    NumberUnion big_endian_number_decoded_as_little_endian_union;
    NumberUnion big_endian_number_converted_to_little_endian_2_union;

    for (int8_t sourceByteNumber = 3; sourceByteNumber >= 0; --sourceByteNumber) {
        std::cout << std::hex << "0x" << static_cast<uint16_t>(number_array_big_endian[sourceByteNumber]) << "\n";

        big_endian_number_decoded_as_little_endian[sourceByteNumber] = number_array_big_endian[sourceByteNumber];
        big_endian_number_converted_to_little_endian_2[destination_byte_number] = number_array_big_endian[sourceByteNumber];

        big_endian_number_decoded_as_little_endian_union.numberArray[sourceByteNumber] = number_array_big_endian[sourceByteNumber];
        big_endian_number_converted_to_little_endian_2_union.numberArray[destination_byte_number] = number_array_big_endian[sourceByteNumber];

        ++destination_byte_number;
    }

    std::cout << "\nReconstruct number with reinterpret_cast\n";
    std::cout << std::hex << "0x" << *(reinterpret_cast<uint32_t*>(big_endian_number_decoded_as_little_endian) ) << "\n";
    std::cout << std::hex << "0x" << *(reinterpret_cast<uint32_t*>(big_endian_number_converted_to_little_endian_2) ) << "\n";
    std::cout << "\nReconstruct number with union\n";
    std::cout << std::hex << "0x" << big_endian_number_decoded_as_little_endian_union.numberRaw << "\n";
    std::cout << std::hex << "0x" << big_endian_number_converted_to_little_endian_2_union.numberRaw << "\n";





//    uint8_t number_array_little_endian[4];
//    number_array_little_endian[0] = number_raw & 0xFF;
//    number_array_little_endian[1] = (number_raw >> 8) & 0xFF;
//    number_array_little_endian[2] = (number_raw >> 16) & 0xFF;
//    number_array_little_endian[3] = number_raw >> 24;
//
//    NumberUnion numberUnion;
//    numberUnion.numberRaw = number_raw;
//
//    std::cout << "----\n";
//
//    for (int byteNumber = 3; byteNumber >=0 ; --byteNumber) {
//        std::cout << std::hex << "0x" << static_cast<uint16_t>(numberUnion.numberArray[byteNumber]) << "\n";
//    }
//
//    std::cout << ":\n";
//
//    uint32_t decodedNumberBigEndianDirect = *reinterpret_cast<uint32_t*>(&number_array_big_endian);
//    std::cout << std::hex << "0x" << decodedNumberBigEndianDirect << "\n";

    return 0;
}
