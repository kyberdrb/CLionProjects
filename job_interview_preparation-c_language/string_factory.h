//
// Created by laptop on 11/29/22.
//

#pragma once

#include <stdint.h>
#include <stddef.h>

char* create_empty_string(uint32_t numberOfCharacters);

//void destroy_string(char* text);
void destroy_string(char** text);