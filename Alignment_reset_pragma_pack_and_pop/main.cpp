#include <cstdint>
#include <iostream>
#include <iomanip>
#include <sstream>

#pragma pack(1)
class FooAlignedToSingleBytes {
    char c;
    uint32_t i;
};
#pragma pack()

class FooUnaligned_DefaultAlignedRestoredByPragmaPack {
    char c;
    uint32_t i;
};

#pragma pack(1)
class FooAlignedToSingleBytesAfterPragmaPack {
    char c;
    uint32_t i;
};
#pragma pop

class FooUnaligned_DefaultAlignedRestoredByPragmaPop {
    char c;
    uint32_t i;
};

template <typename T>
void printAlignmentAndSize(T type) {
    std::cout << alignof(T) << std::endl;
    std::cout << sizeof(T) << std::endl;
    std::cout << std::endl;
}

std::string padText(int16_t padding) {
    std::ostringstream stream;
    stream << std::setw(padding) << std::setfill(' ') << "";
    return stream.str();
}

template <typename... Args>
void printAlignmentAndSize(Args&&... args) {
    int16_t numOfCharsInRow = 62;
    ( (
        std::cout
//            << "alignof(" << typeid(args).name() << ") = " << std::setw(numOfCharsInRow - std::string("alignof(").size() - std::string(typeid(args).name()).size() - std::string(") = ").size() ) << alignof(args) << '\n'
//            << "sizeof(" << typeid(args).name() << ") = " << std::setw(numOfCharsInRow - std::string("sizeof(").size() - std::string(typeid(args).name()).size() - std::string(") = ").size() ) << sizeof(args) << '\n'
            << "alignof(" << typeid(args).name() << ") = "
                << padText(
                        numOfCharsInRow - std::string("alignof(").size() - std::string(typeid(args).name()).size() - std::string(") = ").size()) << alignof(args) << '\n'
            << "sizeof(" << typeid(args).name() << ") = "
                << padText(
                        numOfCharsInRow - std::string("sizeof(").size() - std::string(typeid(args).name()).size() - std::string(") = ").size()) << sizeof(args) << '\n'
            << '\n'
    ), ...); // clang-tidy: Parameter expansion is a C++ extension; GCC: warning: fold-expressions only available with ‘-std=c++17’ or ‘-std=gnu++17’ [-Wc++17-extensions]
}

int main() {
    {
        std::cout << "instance aligned to by 'pragma pack(1)'" << std::endl;
        FooAlignedToSingleBytes fooAlignedToSingleBytes;
        printAlignmentAndSize(fooAlignedToSingleBytes);
    }

    {
        std::cout << "instance defaultly aligned by 'pragma pack()'" << std::endl;
        FooUnaligned_DefaultAlignedRestoredByPragmaPack fooUnalignedDefaultAlignedRestoredByPragmaPack;
        printAlignmentAndSize(fooUnalignedDefaultAlignedRestoredByPragmaPack);
    }

    {
        std::cout << "instance aligned to single bytes again by 'pragma pack(1)'" << std::endl;
        FooAlignedToSingleBytesAfterPragmaPack fooAlignedToSingleBytesAfterPragmaPack;
        printAlignmentAndSize(fooAlignedToSingleBytesAfterPragmaPack);
    }

    {
        std::cout << "instance defaultly aligned by 'pragma pop'" << std::endl;
        FooUnaligned_DefaultAlignedRestoredByPragmaPop fooUnalignedDefaultAlignedRestoredByPragmaPop;
        printAlignmentAndSize(fooUnalignedDefaultAlignedRestoredByPragmaPop);
    }

    FooAlignedToSingleBytes fooAlignedToSingleBytes;
    FooUnaligned_DefaultAlignedRestoredByPragmaPack fooUnalignedDefaultAlignedRestoredByPragmaPack;
    FooAlignedToSingleBytesAfterPragmaPack fooAlignedToSingleBytesAfterPragmaPack;
    FooUnaligned_DefaultAlignedRestoredByPragmaPop fooUnalignedDefaultAlignedRestoredByPragmaPop;
    printAlignmentAndSize(fooAlignedToSingleBytes, fooUnalignedDefaultAlignedRestoredByPragmaPack, fooAlignedToSingleBytesAfterPragmaPack, fooUnalignedDefaultAlignedRestoredByPragmaPop);

    return 0;
}
