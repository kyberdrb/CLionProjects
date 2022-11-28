//
// Created by laptop on 11/27/22.
//

#ifndef STRUCT_EXAMPLES_H
#define STRUCT_EXAMPLES_H

#include <stdint.h>

typedef struct beispiel_struct {
    char* city;
    char state[50];
    double temperature;
    int8_t humidity;
} beispiel_struct_t;

void print_beispiel_struct_instance(const struct beispiel_struct* const beispielStruct);
void print_beispiel_struct_instance_passed_by_value(struct beispiel_struct beispielStruct);

void test_passing_stack_allocated_structs_by_value_and_pointer();

void modify_struct_passed_by_value(beispiel_struct_t beispielStruct);
void modify_struct_passed_by_pointer(beispiel_struct_t* beispielStruct);

void test_passing_heap_allocated_structs_by_value_and_pointer();

#endif
