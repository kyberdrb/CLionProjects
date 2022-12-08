//
// Created by laptop on 12/2/22.
//

#include "algorithm_exercise.h"

#include <stdio.h>  // 'printf'
#include <stdlib.h> // 'atoll'
#include <assert.h>

void test_algorithm() {
    // 122334432: true
    // 12242: false
    // 124 false
    // 12345 true
    // 111 false
    bool result = false;

    result = algorithm_exercise(122334432);
    printf("%d: %d\n", 122334432, result); // true

    result = algorithm_exercise(12242);     // false: |2 - 4| = 2 >= 1
    printf("%d: %d\n", 12242, result);

    result = algorithm_exercise(124);       // false: |4 - 2| = 2 >= 1
    printf("%d: %d\n", 124, result);

    result = algorithm_exercise(12345);     // true:
    printf("%d: %d\n", 12345, result);

    result = algorithm_exercise(111);       // false:
    printf("%d: %d\n", 111, result);
}

// Máme funkciu ktorá vracia boolean.
// Na jej vstup ide číslo, aspoň 10 miestne . Pokiaľ sú hociktoré dve po sebe idúce čísla rozdielne o inú hodnotu ako o 1 tak sa: false.
// Inak True
//
// 122334432: true
// 12242: false
// 124 false
// 12345 true
// 111 false
bool algorithm_exercise(uint64_t inputNumber) {
    // convert input number to string
    const uint16_t numberOfDigitsOfInputNumber = snprintf(NULL, 0, "%lu", inputNumber);
    assert(numberOfDigitsOfInputNumber > 0);
    uint32_t numberOfDigitsOfInputNumberWithNullTerminator = numberOfDigitsOfInputNumber + 1;
    
    char inputNumberAsString[numberOfDigitsOfInputNumberWithNullTerminator];
//    char* inputNumberAsString = calloc(numberOfDigitsOfInputNumberWithNullTerminator, sizeof(char));
    
    int numberOfDigitsAfterConversion = snprintf(inputNumberAsString, numberOfDigitsOfInputNumber + 1, "%lu", inputNumber);
    assert(inputNumberAsString[numberOfDigitsOfInputNumber] == '\0');
    assert(numberOfDigitsAfterConversion == numberOfDigitsOfInputNumber);

    char firstCharacter = '\0';
    char secondCharacter = '\0';

//    for (uint32_t digitIndex = 0; digitIndex < numberOfDigitsOfInputNumber; digitIndex + 2) {
//        firstCharacter = digitIndex;
//        secondCharacter = digitIndex + 1;
        
        // convert first character to number
        // convert second character to number
        // subtract first number from second
        // make an absolute value from the subtraction result
        // if (result == 1)
        //     continue;
        // 
//    }

//    free(inputNumberAsString);

    return true;
}