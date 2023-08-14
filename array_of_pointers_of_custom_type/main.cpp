#include <iostream>

struct VIN {
    char vin[17];
};

int main() {
    VIN* vins[5];

    VIN vin_1;
    //vin_1.vin = "12345678912345678"; // Compiler error: Array of 'char[17]' is not assignable
    vin_1.vin[0] = '0';
    uint8_t vinChar = 0;
    for (uint8_t vinPartNum = 0; vinPartNum < 17; ++vinPartNum) {
        vin_1.vin[vinPartNum] = vinChar + '1';
        ++vinChar;
        vinChar %= 9;
    }

    vins[0] = &vin_1;
    vins[1] = nullptr;

    for (int i = 0; i < 17; ++i) {
        printf("%c", vins[0]->vin[i]);
    }
    printf("\n");

    if (vins[1] == nullptr) {
        printf("%s\n", "VIN uninitialized");
    }

    return 0;
}
