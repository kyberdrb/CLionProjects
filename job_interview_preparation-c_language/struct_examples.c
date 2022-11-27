//
// Created by laptop on 11/27/22.
//

#include "struct_examples.h"

#include <malloc.h>
#include <string.h>

void test_passing_by_value_and_pointer() {
    beispiel_struct_t beispielStruct_1;
    beispielStruct_1.humidity = 87;
    beispielStruct_1.temperature = 5.2;
    strcpy(beispielStruct_1.state, "Slovakia");

    uint32_t cityNameLegth = 100;
    uint32_t cityNameLegthWithNullTerminator = 100 + 1;
    beispielStruct_1.city = malloc(cityNameLegthWithNullTerminator * sizeof(char));
    memset(beispielStruct_1.city, 0, cityNameLegthWithNullTerminator);
    strcpy(beispielStruct_1.city, "Zilina");
    free(beispielStruct_1.city);
}
