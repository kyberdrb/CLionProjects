//
// Created by laptop on 12/8/22.
//

#include "one_dimensional_array.h"

#include "delimiter.h"

#include <stdio.h>

void test_one_dimensional_arrays() {
    int32_t numbers[] = {1, 2, 3, 4, 5, 6};

    size_t sizeOfArrayInMemory = sizeof(numbers);
    printf("%s: %lu bytes\n", "sizeOfArrayInMemory: ", sizeOfArrayInMemory);

    size_t numberOfNumbers = sizeOfArrayInMemory / sizeof(numbers[0]);
    printf("%s: %lu elements\n", "numberOfNumbers: ", numberOfNumbers);
    size_t numberOfNumbers2 = sizeOfArrayInMemory / sizeof(int32_t);
    printf("%s: %lu elements\n", "numberOfNumbers2: ", numberOfNumbers2);

    print_1d_numbers_by_address(numbers, numberOfNumbers);

    // dereference by pointer arithmetic
    printf("%s: %d\n", "*(numbers + 1) = numbers[1]", *(numbers + 1));

    size_t indexOfLastNumber = numberOfNumbers - 1;
    printf("%s: %ld\n", "&numbers[indexOfLastNumber] - &numbers[0] + 1", &numbers[indexOfLastNumber] - &numbers[0] + 1);

    print_delimiter();
}

void print_1d_numbers_by_address(int32_t* numbersPassedByAddress, size_t numberOfElements) {
    printf("|");
    for (int i = 0; i < numberOfElements; ++i) {
        printf("%d|", *numbersPassedByAddress);
        numbersPassedByAddress++;
    }
    printf("\n");
}

void print_numbers_by_array(int32_t numbersPassedByArray[], size_t numberOfElements) {

}