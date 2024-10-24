//
// Created by laptop on 11/29/22.
//

#include "string_factory.h"

#include <malloc.h>
#include <string.h>

/// creates a string on the heap with the size of 'numberOfCharacters' + NULL terminator char
char* create_empty_string(uint32_t numberOfCharacters) {
    uint64_t numberOfCharactersWithNullTerminatorCharacter = numberOfCharacters + 1;
    size_t totalAllocatedSpaceInBytes = numberOfCharactersWithNullTerminatorCharacter * sizeof(char);
    char* text = malloc(totalAllocatedSpaceInBytes);
    memset(text, 0, totalAllocatedSpaceInBytes);
    return text;
}

//void destroy_string(char* text) {
//    if (text != NULL) {   // because deallocating NULL pointer leads to undefined behavior
//        free(text);
//        //text = NULL; // DOESN'T ACTUALLY SANITIZES THE DANGLING POINTER: ONLY SETS A COPY OF THE POINTER TO NULL INSTEAD OF THE ORIGINAL POINTER -
//        // MAYBE USE A POINTER TO POINTER WHEN PASSING THE 'TEXT' PARAMETER AS THE PARAMETER TYPE?
//    }
//}

void destroy_string(char** text) {
    if (*text != NULL) {   // because deallocating NULL pointer leads to undefined behavior
        free(*text);
        *text = NULL;
    }
}
