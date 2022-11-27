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
    const char* stringOnStack = "string allocated with calloc";
    char* stringAllocatedOnHeapWithCalloc = calloc((strlen(stringOnStack) + 1), sizeof(char));
    strcpy(stringAllocatedOnHeapWithCalloc, stringOnStack);
    printf("%s\n", stringOnStack);
    printf("%s\n", stringAllocatedOnHeapWithCalloc);

//    stringAllocatedOnHeapWithCalloc = realloc()

    free(stringAllocatedOnHeapWithCalloc);
    stringAllocatedOnHeapWithCalloc = NULL;
}

void custom_malloc_example() {
    char* originalStringForMallocOnStack = "string allocated With Malloc";

    int32_t numberOfCharacters = strlen(originalStringForMallocOnStack);
    printf("%s%d\n", "numberOfCharacters: ", numberOfCharacters);
    printf("%s%p\n", "address of numberOfCharacters: ", &numberOfCharacters);
    printf("%s%lu\n", "sizeof(&numberOfCharacters): ", sizeof(&numberOfCharacters));
    printf("%s: %lu\n", "sizeof(numberOfCharacters)", sizeof(numberOfCharacters));
    printf("\n");

    char* stringAllocatedWithMalloc = malloc(sizeof(char) * strlen(originalStringForMallocOnStack) + 1);

    printf("%s: %p\n", "pointer to stringAllocatedWithMalloc", stringAllocatedWithMalloc);
    printf("%s: %p\n", "pointer to stringAllocatedWithMalloc", &stringAllocatedWithMalloc);
    printf("%s: %lu\n", "sizeof(char)", sizeof(char));
    printf("%s: %lu\n", "sizeof(stringAllocatedWithMalloc)", sizeof(stringAllocatedWithMalloc));
    printf("%s: %lu\n", "sizeof(*stringAllocatedWithMalloc)", sizeof(*stringAllocatedWithMalloc));

    // zero-out allocated memory to increase security, i.e. to prevent leaking of sensitive information: passwords, credit card numbers etc.
    memset(stringAllocatedWithMalloc, 0, sizeof(*stringAllocatedWithMalloc));

//    stringAllocatedWithMalloc = realloc(stringAllocatedWithMalloc, sizeof(char) * (strlen(originalStringForMallocOnStack) + 1));

//    strcpy(stringAllocatedWithMalloc, "string Allocated With Malloc");    // SIGSEGV - segmentation fault - program crash and memory leak
//    strcpy(stringAllocatedWithMalloc, originalStringForMallocOnStack);

//    printf("%s\n", *originalStringForMallocOnStack);
//    printf("%s\n", *stringAllocatedWithMalloc);

    free(stringAllocatedWithMalloc);    // sanitize memory leak
    stringAllocatedWithMalloc = NULL;   // sanitize dangling pointer
}

void custom_calloc_example() {
    char* originalStringForCallocOnStack = "string allocated With Calloc";

    int32_t numberOfCharacters = strlen(originalStringForCallocOnStack);

    char* stringAllocatedWithCalloc = (char*) calloc(numberOfCharacters, sizeof(char));
    free(stringAllocatedWithCalloc);

    char* stringAllocatedWithCallocWithReallocation = calloc(numberOfCharacters, sizeof(char));
    stringAllocatedWithCallocWithReallocation = realloc(stringAllocatedWithCallocWithReallocation, 8 * sizeof(char));
    free(stringAllocatedWithCallocWithReallocation);
    stringAllocatedWithCallocWithReallocation = NULL;
}