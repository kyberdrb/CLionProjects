//
// Created by laptop on 11/27/22.
//

#include "string_examples.h"

// for 'malloc', 'calloc', 'realloc'
#include <malloc.h>

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

void print_delimiter() {
    printf("%c%c%c\n", '-', '-', '-');
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

void print_char_array(char* charArray, size_t arrayLength)
{
    for (size_t charIndex = 0; charIndex <= arrayLength - 2; ++charIndex) {
        printf("%c | ", charArray[charIndex]);
    }

    printf("%c |", charArray[arrayLength - 1]);
    printf("\n");
}

int char_array_example(){
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    char arr2[] = "array initialized";

    size_t stringLength = 23;
    char* arr3 = string_factory_method(stringLength);
    strcpy(arr3, "calloc-allocated string");

    print_char_array(arr, sizeof arr);
    printf("size = %lu bytes \n", sizeof arr);

    printf("\n");

    print_char_array(arr2, sizeof arr2-1);
    printf("size = %lu bytes \n", sizeof(arr2));

    printf("\n");

    print_char_array(arr3, stringLength);
    printf("size = %zu bytes \n", sizeof(*arr3));

//    free(arr3);
    custom_free(arr3);
}

void* string_factory_method(size_t stringLength) {
    return calloc(stringLength + 1, sizeof(char));
}

void custom_free(void* something) {
    free(something);
    something = NULL;
}
