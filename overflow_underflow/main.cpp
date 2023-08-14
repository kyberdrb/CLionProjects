#include <iostream>

#include <climits>

int main() {
    for (int i = 0; i < 3; ++i) {
        uint8_t counter = {UINT8_MAX};
        std::cout << (uint16_t) counter << std::endl;

        counter += 1;
        std::cout << (uint16_t) counter << std::endl;
    }

    std::cout << "---" << std::endl;

    for (int i = 0; i < 3; ++i) {
        int8_t counter = {INT8_MAX};
        std::cout << (int16_t) counter << std::endl;

        counter += 1;
        std::cout << (int16_t) counter << std::endl;
    }

    std::cout << "---" << std::endl;

    for (int i = 0; i < 3; ++i) {
        uint8_t counter = {0};
        std::cout << (uint16_t) counter << std::endl;

        counter -= 1;
        std::cout << (uint16_t) counter << std::endl;
    }

    std::cout << "---" << std::endl;

    for (int i = 0; i < 3; ++i) {
        int8_t counter = {INT8_MIN};
        std::cout << (int16_t) counter << std::endl;

        counter -= 1;
        std::cout << (int16_t) counter << std::endl;
    }

    return 0;
}
