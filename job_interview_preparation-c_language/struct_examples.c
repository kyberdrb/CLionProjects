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
    uint32_t cityNameLengthWithNullTerminator = cityNameLegth + 1;
    size_t allocatedSpaceForCityName = cityNameLengthWithNullTerminator * sizeof(char);
    beispielStruct_1.city = malloc(allocatedSpaceForCityName);
    memset(beispielStruct_1.city, 0, cityNameLengthWithNullTerminator);
    strcpy(beispielStruct_1.city, "Zilina");

    printf("%s\t", "Struct before modification in caller/invokation code: ");
    print_beispiel_struct_instance_passed_by_value(beispielStruct_1);

    printf("%s\n", "TEST MODIFICATION WHEN PASSING INSTANCE OF STRUCT BY VALUE:");
    modify_struct_passed_by_value(beispielStruct_1);

    printf("%s\t", "Struct after modification in caller/invokation code: ");
    print_beispiel_struct_instance_passed_by_address(&beispielStruct_1);

    printf("%s\n", "TEST MODIFICATION WHEN PASSING INSTANCE OF STRUCT BY POINTER:");
    modify_struct_passed_by_pointer(&beispielStruct_1);

    printf("%s\t", "Struct after modification in caller/invokation code: ");
    print_beispiel_struct_instance_passed_by_address(&beispielStruct_1);

    // destructor
    free(beispielStruct_1.city);

    print_delimiter();
}

void print_beispiel_struct_instance_passed_by_address(const struct beispiel_struct* const beispielStruct) {
    printf("city: %s; state: %s; temperature: %.1f; humidity: %d\n",
           beispielStruct->city, beispielStruct->state, beispielStruct->temperature, (*beispielStruct).humidity);
}

void modify_struct_passed_by_value(beispiel_struct_t beispielStruct) {
    beispielStruct.humidity = 65;
    beispielStruct.temperature = 7.3;
    strcpy(beispielStruct.state, "Czechia");

    printf("%s\t", "Struct after modification in calling/external code: ");
    print_beispiel_struct_instance_passed_by_address(&beispielStruct);
}

void modify_struct_passed_by_pointer(beispiel_struct_t* beispielStruct) {
    beispielStruct->humidity = 65;
    (*beispielStruct).temperature = 7.3;
    strcpy(beispielStruct->state, "Czechia");

    printf("%s\t", "Struct after modification in calling/external code: ");
    print_beispiel_struct_instance_passed_by_address(beispielStruct);
}

void print_beispiel_struct_instance_passed_by_value(struct beispiel_struct beispielStruct) {
    printf("city: %s; state: %s; temperature: %.1f; humidity: %d\n",
           beispielStruct.city, beispielStruct.state, beispielStruct.temperature, beispielStruct.humidity);
}

void test_passing_heap_allocated_structs_by_value_and_pointer() {
    // constructor
    beispiel_struct_t* beispielStruct_2 = malloc(sizeof(beispiel_struct_t));

    printf("%s:\t\t%lu\n", "sizeof(beispiel_struct_t)", sizeof(beispiel_struct_t));
    printf("%s:\t%lu\n", "sizeof(struct beispiel_struct)", sizeof(struct beispiel_struct));

    uint8_t cityNameLength = 100;
    uint8_t cityNameLengthWithNullTerminator = cityNameLength + 1;
    size_t allocatedSpaceForCityName = cityNameLengthWithNullTerminator * sizeof(char);
    beispielStruct_2->city = malloc(allocatedSpaceForCityName);
    memset(beispielStruct_2->city, 0, allocatedSpaceForCityName);
    strcpy(beispielStruct_2->city, "Zilina");
    // constructor continuation
    strcpy(beispielStruct_2->state, "Slovakia");
    beispielStruct_2->temperature = 0.2;
    (*beispielStruct_2).humidity = 74;

    printf("%s\t", "Struct before modification in caller/invokation code: ");
    print_beispiel_struct_instance_passed_by_value(*beispielStruct_2);

    printf("%s\n", "TEST MODIFICATION WHEN PASSING INSTANCE OF STRUCT BY VALUE:");
    modify_struct_passed_by_value(*beispielStruct_2);

    printf("%s\t", "Struct after modification in caller/invokation code: ");
    print_beispiel_struct_instance_passed_by_address(beispielStruct_2);

    printf("%s\n", "TEST MODIFICATION WHEN PASSING INSTANCE OF STRUCT BY POINTER:");
    modify_struct_passed_by_pointer(beispielStruct_2);

    printf("%s\t", "Struct after modification in caller/invokation code: ");
    print_beispiel_struct_instance_passed_by_address(beispielStruct_2);

    // destructor
    free(beispielStruct_2->city);
    free(beispielStruct_2);

    print_delimiter();
}
