//
// Created by laptop on 11/27/22.
//

#include "realloc_example.h"

#include "delimiter.h"

#include <malloc.h>
#include <string.h>

void string_realloc_example() {
    char *str;

    /* Initial memory allocation */
    str = (char *) malloc(15);
    strcpy(str, "tutorialspoint");
    printf("String = %s,  Address = %u\n", str, str);

    /* Reallocating memory */
    str = (char *) realloc(str, 25);
    strcat(str, ".com");
    printf("String = %s,  Address = %u\n", str, str);

    free(str);

    print_delimiter();
}