//
// Created by laptop on 11/27/22.
//

#pragma once

#include <stddef.h>

void print_text_directly();

void print_dynamically_allocated_text_examples();
void malloc_example();
void calloc_example();
void custom_malloc_example();
void custom_calloc_example();
void print_char_array(char* charArray, size_t arrayLength);
int char_array_example();

void* string_factory_method(size_t stringLength);
void custom_free(void* something);
