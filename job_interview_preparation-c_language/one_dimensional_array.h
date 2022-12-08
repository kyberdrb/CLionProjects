//
// Created by laptop on 12/8/22.
//

#pragma once

#include <stddef.h>
#include <stdint.h>

//- 1D polia: urobit si pole int-ov: int32_t alebo int
//    - inicializacia
//    - naplnenie
//    - zistenie alokovanej veÄ¾kosti v pamÃ¤ti pre 1D pole
//        - sizeof(pole)
//        - cez rozdiel smernikov/adries posledneho a prveho prvkov
//            - &(pole[indexPoslednehoPrvku]) - &(pole[0])
//            - &pole[indexPoslednehoPrvku] - &pole[0]
//            - &pole[indexPoslednehoPrvku] - pole
//    - zistenie poÄtu prvkov:
//        - char* resp. char[] bez null terminatora
//            - sizeof(charArray)
//        - char* resp. char[] s null terminatorom
//            - strlen(charArray)
//            - strnlen(charArray, sizeof(charArray))
//        - pole prvkov, ktorych datovy typ zabera v pamati viac ako 1 bajt alebo pole vlastnych udajovych typov
//            - sizeof(customArray) / sizeof(elementDataType)
//            - sizeof(numbers) / sizeof(int32_t)
//            - sizeof(numbers) / sizeof(numbers[0])
//            - (&numbers[indexPoslednehoPrvku] - numbers) / sizeof(int32_t)
//            - (&numbers[indexPoslednehoPrvku] - numbers) / sizeof(numbers[0])
//            - (&pole[indexPoslednehoPrvku] - pole) / sizeof(int32_t)
//            - (&pole[indexPoslednehoPrvku] - pole) / sizeof(pole[0])
//    - dereferencia prvku na pozicii cez smernikovu aritmetiku
//    - vypisanie cez smernikovu aritmetiku
//    - preposlanie do funkcie cez parameter: konverzia parametra z typu pole [] na smernik na prvy prvok (1D) / smernik na pole (2D)

void test_one_dimensional_arrays();

static void print_1d_numbers_by_address(int32_t* numbersPassedByAddress, size_t numberOfElements);
static void print_numbers_by_array(int32_t numbersPassedByArray[], size_t numberOfElements);
