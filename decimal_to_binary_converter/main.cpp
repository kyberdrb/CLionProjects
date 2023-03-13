#include <iostream>

#include <bitset>
#include <cstddef>
#include <cassert>

int main() {
    uint8_t decimalNumber = 240;
    std::bitset<8> binaryNumber{decimalNumber};
    std::cout << binaryNumber << std::endl;

//    char a = -58;
//    int8_t a = 8;
    int8_t a = 0xA;
    std::bitset<8> x(a);
    std::cout << x << '\n';

//    short c = -128;
    int16_t c = 8192;
    std::bitset<16> y(c);
    std::cout << y << '\n';

    std::cout << "---" << '\n';

    uint16_t packageOftTwo8BitDecimalNumbers{0};
    std::bitset<16> packageAsBinary_1{packageOftTwo8BitDecimalNumbers};
    std::cout << packageAsBinary_1 << '\n';

    uint8_t decimalNumberInUpperPart = 65;
    packageOftTwo8BitDecimalNumbers = decimalNumberInUpperPart;
    std::bitset<16> packageAsBinary_2{decimalNumberInUpperPart};
    packageAsBinary_2 = packageOftTwo8BitDecimalNumbers;
    std::cout << packageAsBinary_2 << '\n';

//    packageOftTwo8BitDecimalNumbers << 8;
//    std::bitset<16> packageAsBinary_3{packageOftTwo8BitDecimalNumbers};
//    std::cout << packageAsBinary_3 << '\n';

    uint8_t decimalNumberInLowerPart = 6;
    packageOftTwo8BitDecimalNumbers = (decimalNumberInUpperPart << 8) | decimalNumberInLowerPart;
    std::bitset<16>packageAsBinary_4 = packageOftTwo8BitDecimalNumbers;
    std::cout << packageAsBinary_4 << '\n';

    std::bitset<4> b3{"1111"};
    b3 &= 0b0011;
    assert(b3 == 0b0011);

    std::bitset<8> b5{"00110101"};
    b5 &= 0b00001111;
    assert(b5 == 0b00000101);

    std::bitset<16> b6{"1111000010100101"};
    b6 &= 0b0000000011111111;
    assert(b6 == 0b0000000010100101);

    // do logical AND operation
    auto packageAsBinaryLowerNibble{packageAsBinary_4};
    uint16_t maskForLowerNibble = 0b0000000011111111;
    packageAsBinaryLowerNibble &= maskForLowerNibble;
    std::cout << packageAsBinaryLowerNibble << '\n';
    uint16_t extractedNumberFromLowerPart{};
    extractedNumberFromLowerPart = packageAsBinaryLowerNibble.to_ulong();
    std::cout << extractedNumberFromLowerPart << '\n';
    uint8_t extractedNumberFromLowerPartExactFit{};
    extractedNumberFromLowerPartExactFit = packageAsBinaryLowerNibble.to_ulong();
    std::cout << +extractedNumberFromLowerPartExactFit << '\n';

    // do logical AND operation and then bitshift to the right for 8 places
    auto packageAsBinaryUpperNibble{packageAsBinary_4};
    uint16_t maskForUpperNibble = 0b1111111100000000;
    // or
    assert(maskForUpperNibble == (maskForLowerNibble ^ 0b1111111111111111));

    packageAsBinaryUpperNibble &= maskForUpperNibble;
    std::cout << packageAsBinaryUpperNibble << '\n';
    uint16_t extractedNumberFromUpperPart{};
    extractedNumberFromUpperPart = packageAsBinaryUpperNibble.to_ulong();
    std::cout << extractedNumberFromUpperPart << '\n';
    uint8_t extractedNumberFromUpperPartExactFit{};
    extractedNumberFromUpperPartExactFit = packageAsBinaryUpperNibble.to_ulong();
    std::cout << +extractedNumberFromUpperPartExactFit << '\n';

    packageAsBinaryUpperNibble >>=  8;
    std::cout << packageAsBinaryUpperNibble << '\n';
    extractedNumberFromUpperPart = packageAsBinaryUpperNibble.to_ulong();
    std::cout << extractedNumberFromUpperPart << '\n';
    extractedNumberFromUpperPartExactFit = packageAsBinaryUpperNibble.to_ulong();
    std::cout << +extractedNumberFromUpperPartExactFit << '\n';

    std::cout << "---" << '\n';

    // Compression
    uint16_t packedNumber = 65;
    std::cout << packedNumber << "\n";

    packedNumber <<= 8;
    std::cout << packedNumber << "\n";

    packedNumber |= 6;
    std::cout << packedNumber << "\n";

    // Extraction
    uint16_t lowerNibbleFromPackedNumber = packedNumber & 0b0000000011111111;
    std::cout << lowerNibbleFromPackedNumber << "\n";

    uint16_t upperNibbleFromPackedNumber = packedNumber & 0b1111111100000000;
    std::cout << upperNibbleFromPackedNumber << "\n";

    upperNibbleFromPackedNumber >>= 8;
    std::cout << upperNibbleFromPackedNumber << "\n";

    return 0;
}
