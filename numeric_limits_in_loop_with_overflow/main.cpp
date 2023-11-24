#include <iostream>
#include <cstdint>
#include <limits>

int main() {
    uint8_t max_uint8_t = std::numeric_limits<uint8_t>::max();
    std::cout << "max:      " << static_cast<uint16_t>(max_uint8_t) << '\n';
    uint8_t safe_max_uint8_t = max_uint8_t - 1;
    std::cout << "safe max: " << static_cast<uint16_t>(safe_max_uint8_t) << '\n';

    std::cout << "iterating within safe range of the data type - finite iteration" << '\n';
    for (uint8_t number = 0; number <= safe_max_uint8_t; ++number) {
        std::cout << static_cast<uint16_t>(number) << '\n';
    }

    std::cout << std::flush;

//    std::cout << "---\n";
//    std::cout << "iterating withing full range of the data type - infinite loop caused by overflow" << '\n';
//    for (uint8_t number = 0; number <= max_uint8_t; ++number) {
//        std::cout << static_cast<uint16_t>(number) << '\n';
//    }

    return 0;
}
