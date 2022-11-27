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

void test_passing_by_value_and_pointer();
void change_something_by_value(beispiel_struct_t beispielStruct);
void change_something_by_pointer(beispiel_struct_t* beispielStruct);

#endif
