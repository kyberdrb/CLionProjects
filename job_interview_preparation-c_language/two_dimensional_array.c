//
// Created by laptop on 12/8/22.
//

#include "two_dimensional_array.h"

#include "delimiter.h"

#include <stdio.h>

void test_two_dimensional_arrays() {
    int32_t numbers[3][4] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {8, 6, 4, 2}
    };

    printf("%s: %d\n", "numbers[0][0]", numbers[0][0]);
    printf("%s: %d\n", "**numbers", **numbers);
    printf("%s: %d\n", "numbers[1][2]", numbers[1][2]);
    printf("%s: %d\n", "*(*(numbers + 1) + 2)", *(*(numbers + 1) + 2));

    uint32_t rows = 3;
    uint32_t columns = 4;
    print_2d_numbers_by_address((int32_t**) numbers, rows, columns);

    print_delimiter();
}

void print_2d_numbers_by_address(int32_t** numbers, uint32_t rows, uint32_t columns) {
    //TODO
}