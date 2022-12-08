//
// Created by laptop on 11/27/22.
//

#include "string_examples.h"

#include "delimiter.h"

#include <assert.h>

// for 'malloc', 'calloc', 'realloc'
#include <malloc.h>

// for 'bool' data type
#include <stdbool.h>

// integer types with reliable size/length/memory requirements
#include <stdint.h>

// for 'printf'
#include <stdio.h>

// functions for working with 'string'/'char*': 'memset', 'strcpy', 'strncpy'
#include <string.h>

void print_text_directly() {
    printf("Raw text printed\n");
}

void print_dynamically_allocated_text_examples() {
    malloc_example();
    print_delimiter();

    calloc_example();
    print_delimiter();

    custom_malloc_example();
    print_delimiter();

    custom_calloc_example();
    print_delimiter();

    char_array_example();
    print_delimiter();
}

void malloc_example() {
    const char* my_str = "Content";
    char* my_copy = malloc(sizeof(char) * (strlen(my_str) + 1));
    strcpy(my_copy, my_str);
    printf("%s\n", my_str);
    printf("%s\n", my_copy);

    free(my_copy);
    my_copy = NULL;
}

void calloc_example() {
    const char* stringOnStack = "content for calloc";
    char* stringAllocatedOnHeapWithCalloc = calloc((strlen(stringOnStack) + 1), sizeof(char));
    strcpy(stringAllocatedOnHeapWithCalloc, stringOnStack);
    printf("%s\n", stringOnStack);
    printf("%s\n", stringAllocatedOnHeapWithCalloc);

//    stringAllocatedOnHeapWithCalloc = realloc()

    free(stringAllocatedOnHeapWithCalloc);
    stringAllocatedOnHeapWithCalloc = NULL;
}

void custom_malloc_example() {
    const char* originalStringForMallocOnStack = "string allocated with malloc";
    char* destinationStringAllocatedWithMalloc = malloc(sizeof(char) * (strlen(originalStringForMallocOnStack) + 1));

    // zero-out allocated memory to increase security, i.e. to prevent leaking of sensitive information: passwords, credit card numbers etc.
    memset(destinationStringAllocatedWithMalloc, 0, strlen(originalStringForMallocOnStack) + 1);

    strcpy(destinationStringAllocatedWithMalloc, originalStringForMallocOnStack);

    printf("%s\n", originalStringForMallocOnStack);
    printf("%s\n", destinationStringAllocatedWithMalloc);

    free(destinationStringAllocatedWithMalloc);
    destinationStringAllocatedWithMalloc = NULL;
}

void custom_calloc_example() {
    const char* originalStringForCallocOnStack = "string allocated with calloc";

    size_t numberOfCharacters = strlen(originalStringForCallocOnStack);
    printf("%s%lu\n", "numberOfCharacters: ", numberOfCharacters);
    printf("%s%p\n", "address of numberOfCharacters: ", &numberOfCharacters);
    printf("%s%lu\n", "sizeof(&numberOfCharacters): ", sizeof(&numberOfCharacters));
    printf("%s: %lu\n", "sizeof(numberOfCharacters)", sizeof(numberOfCharacters));
    printf("\n");

    char* destinationStringAllocatedWithCalloc = calloc(strlen(originalStringForCallocOnStack) + 1, sizeof(char));
    strcpy(destinationStringAllocatedWithCalloc, originalStringForCallocOnStack);

    for(int charIndex = 0; charIndex < strlen(originalStringForCallocOnStack); ++charIndex) {
        printf("%c", originalStringForCallocOnStack[charIndex]);
    }
    printf("\n");
    printf("\n");

    char* destinationCharPointer = destinationStringAllocatedWithCalloc;

    printf("%s: %lu\n", "sizeof(char)", sizeof(char));

    printf("%s: %p\n", "destinationStringAllocatedWithCalloc", destinationStringAllocatedWithCalloc);
    printf("%s: %p\n", "destinationCharPointer", destinationCharPointer);

    printf("%s: %p\n", "pointer to destinationStringAllocatedWithCalloc", &destinationStringAllocatedWithCalloc);
    printf("%s: %p\n", "pointer to destinationCharPointer", &destinationCharPointer);

    printf("%s: %lu\n", "strlen(*destinationStringAllocatedWithCalloc)", strlen(destinationStringAllocatedWithCalloc));
    printf("%s: %lu\n", "strlen(*destinationCharPointer)", strlen(destinationCharPointer));

    printf("%s: %lu\n", "sizeof(stringAllocatedWithMalloc)", sizeof(destinationStringAllocatedWithCalloc));
    printf("%s: %lu\n", "sizeof(*stringAllocatedWithMalloc)", sizeof(*destinationStringAllocatedWithCalloc));
    printf("%s: %lu\n", "sizeof(stringAllocatedWithMalloc)", sizeof(destinationCharPointer));
    printf("%s: %lu\n", "sizeof(*stringAllocatedWithMalloc)", sizeof(*destinationCharPointer));

    printf("%s: %c\n", "*destinationCharPointer", *destinationCharPointer);
    printf("%s: %c\n", "*(destinationCharPointer + 1)", *(destinationCharPointer + 1));

    printf("\n");

    for(
            uint32_t charIndex = 0;
            charIndex < strlen(destinationStringAllocatedWithCalloc);
            ++charIndex)
    {
        printf("%c", *(destinationCharPointer + charIndex));
    }
    printf("\n");

    free(destinationStringAllocatedWithCalloc);
    destinationStringAllocatedWithCalloc = NULL;
}

void print_char_array_by_index(char charArray[], size_t arrayLength) {
    bool isStringOpen = charArray[arrayLength - 1] != '\0';

    if (isStringOpen) {
        for (size_t charIndex = 0; charIndex <= arrayLength - 2; ++charIndex) {
            printf("%c | ", charArray[charIndex]);
        }

        printf("%c |", charArray[arrayLength - 1]);

        printf("\n");
        return;
    }

    bool isStringNullTerminated = !isStringOpen;
    if (isStringNullTerminated) {
        for (size_t charIndex = 0; charIndex <= arrayLength - 3; ++charIndex) {
            printf("%c | ", charArray[charIndex]);
        }

        printf("%c |", charArray[arrayLength - 2]);

        printf("\n");
        return;
    }
}

void print_char_array_by_pointer_arithmetics(char* charArray, size_t arrayLength) {
    char* charArrayCopy = charArray;
    for (size_t charIndex = 0; charIndex <= arrayLength - 2; ++charIndex) {
        printf("%c | ", *charArrayCopy);
        ++charArrayCopy;
    }

    printf("%c |", *charArrayCopy);
    printf("\n");
}

void print_char_array_as_string(char* charArray) {
    printf("%s: %lu\n", "sizeof(arr) inside print function", sizeof(charArray));
    printf("%s\n", charArray);
}

int char_array_example(){
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

    print_char_array_by_index(arr, sizeof arr);
    print_char_array_by_pointer_arithmetics(arr, sizeof(arr));
    printf("%s: %lu\n", "sizeof(arr)", sizeof(arr));
    printf("%s: %p\n", "arr", arr);

    // can end up with hanging forever or giving inaccurate value or doing other undefined behavior; use 'strclen' instead for OPEN STRINGS, i.e. NON-NULL-TERMINATED char arrays
//    printf("%s: %lu\n", "strlen(arr)", strlen(arr));
    printf("%s: %lu\n", "strnlen(arr, sizeof(arr))", strnlen(arr, sizeof(arr)));

    // can end up with hanging forever or giving inaccurate value or doing other undefined behavior; use 'strclen' instead for OPEN STRINGS, i.e. NON-NULL-TERMINATED char arrays
//    printf("%s: %d\n", "sizeof(arr) != strlen(arr)", sizeof(arr) != strlen(arr));

    printf("%s: %d\n", "sizeof(arr) == strnlen(arr, sizeof(arr))", sizeof(arr) == strnlen(arr, sizeof(arr)));

    // When we try to print a char array without the ending null terminator character, we can read outside of the allocated memory and risk undefined behavior
    //print_char_array_as_string(arr);

    arr[0] = 'z';
    print_char_array_by_index(arr, sizeof arr);

    char* arrCopy = arr;
    *(arrCopy + 1) = 'y';
    print_char_array_by_pointer_arithmetics(arr, sizeof arr);

    printf("\n");

    char arrWithNullTerminatorCharAtEnd[] = {'h', 'i', 'j', 'k', 'l', 'm', '\0'};
    print_char_array_as_string(arrWithNullTerminatorCharAtEnd);
    printf("%s: %lu\n", "sizeof(arrWithNullTerminatorCharAtEnd)", sizeof(arrWithNullTerminatorCharAtEnd));
    printf("%s: %p\n", "arrWithNullTerminatorCharAtEnd", arrWithNullTerminatorCharAtEnd);
    printf("%s: %ld\n", "arrWithNullTerminatorCharAtEnd - arr", arrWithNullTerminatorCharAtEnd - arr);

    arrWithNullTerminatorCharAtEnd[0] = 'x';
    print_char_array_as_string(arrWithNullTerminatorCharAtEnd);

    printf("\n");

    char arr2[] = "array initialized";

    print_char_array_by_index(arr2, sizeof arr2);
    printf("size = %lu bytes \n", sizeof(arr2));

    arr2[0] = 'y';
    print_char_array_by_pointer_arithmetics(arr2, sizeof(arr2));
    print_char_array_as_string(arr2);

    printf("\n");

    size_t stringLength = 23;
    char* arr3 = string_factory_method(stringLength);
    strcpy(arr3, "calloc-allocated string");

    print_char_array_by_index(arr3, stringLength);
    printf("size = %zu bytes \n", sizeof(*arr3));

//    free(arr3);
    free_with_dangling_pointer_sanitization((void**) &arr3);
}

void* string_factory_method(size_t stringLength) {
    size_t stringLengthWithNullTerminator = stringLength + 1;
//    void* dynamically_allocated_string = calloc(stringLengthWithNullTerminator, sizeof(char));
    void* dynamically_allocated_string = malloc(stringLengthWithNullTerminator * sizeof(char));
    memset(dynamically_allocated_string, 0, stringLengthWithNullTerminator);
    return dynamically_allocated_string;
}

void free_with_dangling_pointer_sanitization(void** something) {
    free(*something);
    *something = NULL;
}
