//
// Created by laptop on 11/27/22.
//

#include "struct_examples.h"

#include "delimiter.h"

#include <malloc.h>
#include <string.h>

void test_passing_stack_allocated_structs_by_value_and_pointer() {
    // 'init' or 'constructor'
    beispiel_struct_t beispielStruct_1;
    beispielStruct_1.humidity = 87;
    beispielStruct_1.temperature = 5.2;
    strcpy(beispielStruct_1.state, "Slovakia");

    uint32_t cityNameLegth = 100;
    uint32_t cityNameLegthWithNullTerminator = cityNameLegth + 1;
    beispielStruct_1.city = malloc(cityNameLegthWithNullTerminator * sizeof(char));
    memset(beispielStruct_1.city, 0, cityNameLegthWithNullTerminator);
    strcpy(beispielStruct_1.city, "Zilina");

    printf("%s\t", "Struct before modificatio in caller/invokation code: ");
    print_beispiel_struct_instance(&beispielStruct_1);
//    printf("Struct in caller code: city: %s; state: %s; temperature: %.1f; humidity: %d\n",
//           beispielStruct_1.city, beispielStruct_1.state, beispielStruct_1.temperature, beispielStruct_1.humidity);

    printf("%s\n", "TEST MODIFICATION WHEN PASSING INSTANCE OF STRUCT BY VALUE:");
    modify_struct_passed_by_value(beispielStruct_1);

    printf("%s\t", "Struct after modification in caller/invokation code: ");
    print_beispiel_struct_instance(&beispielStruct_1);
    
    printf("%s\n", "TEST MODIFICATION WHEN PASSING INSTANCE OF STRUCT BY POINTER:");
    modify_struct_passed_by_pointer(&beispielStruct_1);

    printf("%s\t", "Struct after modification in caller/invokation code: ");
    print_beispiel_struct_instance(&beispielStruct_1);

    // destructor
    free(beispielStruct_1.city);

    print_delimiter();
}

void print_beispiel_struct_instance(const struct beispiel_struct* const beispielStruct) {
    printf("city: %s; state: %s; temperature: %.1f; humidity: %d\n",
           beispielStruct->city, beispielStruct->state, beispielStruct->temperature, (*beispielStruct).humidity);
}

void modify_struct_passed_by_value(beispiel_struct_t beispielStruct) {
    beispielStruct.humidity = 65;
    beispielStruct.temperature = 7.3;
    strcpy(beispielStruct.state, "Czechia");

    printf("%s\t", "Struct after modification in calling/destination code: ");
    print_beispiel_struct_instance(&beispielStruct);
}

void modify_struct_passed_by_pointer(beispiel_struct_t* beispielStruct) {
    beispielStruct->humidity = 65;
    (*beispielStruct).temperature = 7.3;
    strcpy(beispielStruct->state, "Czechia");

    printf("%s\t", "Struct after modification in calling/destination code: ");
    print_beispiel_struct_instance(beispielStruct);
}