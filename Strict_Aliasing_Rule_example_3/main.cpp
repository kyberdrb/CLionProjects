#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cassert>

// What is the strict aliasing rule?: https://stackoverflow.com/questions/98650/what-is-the-strict-aliasing-rule/99010#99010

typedef struct Msg {
    unsigned int a;
    unsigned int b;
} Msg;

void sendWord(uint32_t* buffer, size_t numberOfMembers);

int main() {
    Msg* msg = (Msg*) malloc(sizeof(Msg)); // standard allocation of Msg struct
    free(msg);
    msg = NULL;

    uint32_t* buff = (uint32_t*) malloc(sizeof(Msg));   // allocate a buffer of numberOfMembers of 32 bits (4 bytes)
    Msg* aliasedMsg = (Msg*) buff;                      // alias the buffer with the Msg struct
                                                        // Dangerous! Implicit assumption that 'int' and 'uint32_t' have the same numberOfMembers - 4 bytes
                                                        // If the types have different length, then the result is UB - Undefined Behavior
    
    printf("\n---------------------------------------------------\n");
    
    printf("sizeof(int) =\t\t%d\n", sizeof(int));
    printf("sizeof(uint32_t) =\t%d\n", sizeof(uint32_t));

    assert(sizeof(int) == sizeof(uint32_t));

    printf("---------------------------------------------------");
    printf("\nWe're lucky. No undefined behavior occurs\nbecause 'int' and 'uint32_t' have the same numberOfMembers on this platform.\n");
    printf("---------------------------------------------------\n\n");

    for (int i = 0; i < 4; ++i) {  // send a bunch of messages
        aliasedMsg->a = i;
        aliasedMsg->b = i + 1;

        sendWord(buff, 2);
        printf("\n");
    }

    free(buff);

    return 0;
}

void sendWord(uint32_t* buffer, size_t numberOfMembers) {   // this function will work as long as the members in the struct will all be of the same type
                                                            // and of the same size as the size of the element in the buffer
    for(int i = 0; i < numberOfMembers; ++i) {
        printf("Sending word:\t%d\n", buffer[i]);
    }
}
 
