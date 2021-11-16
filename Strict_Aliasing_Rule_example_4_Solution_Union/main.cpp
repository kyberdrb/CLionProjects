#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cassert>

// What is the strict aliasing rule?: https://stackoverflow.com/questions/98650/what-is-the-strict-aliasing-rule/99010#99010

typedef struct Msg {
    unsigned int a;
    unsigned int b;
} Msg;

union MsgAliasedWithBuffer{
    Msg msg;
    unsigned int asBuffer[sizeof(Msg)/sizeof(uint32_t)];
};

void sendWord(uint32_t* buffer, size_t numberOfMembers);

int main() {
    MsgAliasedWithBuffer* msgInUnion = (MsgAliasedWithBuffer*) malloc(sizeof(Msg));
    uint32_t* buff = (uint32_t*) malloc(sizeof(Msg));

    printf("\n---------------------------------------------------\n");
    
    printf("sizeof(int) =\t\t%d\n", sizeof(int));
    printf("sizeof(uint32_t) =\t%d\n", sizeof(uint32_t));

    assert(sizeof(int) == sizeof(uint32_t));

    printf("---------------------------------------------------");
    printf("\nWe're lucky. No undefined behavior occurs\nbecause 'int' and 'uint32_t' have the same numberOfMembers on this platform.\n");
    printf("---------------------------------------------------\n\n");

    for (int i = 0; i < 4; ++i) {  // send a bunch of messages
        msgInUnion->msg.a = i;
        msgInUnion->msg.b = i + 1;

        sendWord(msgInUnion->asBuffer, 2);
        printf("\n");
    }

    free(msgInUnion);
    msgInUnion = NULL;

    return 0;
}

void sendWord(uint32_t* buffer, size_t numberOfMembers) {   // this function will work as long as the element in the buffer will have the same
                                                            // size as the members in the struct 
                                                            // and all members in the struct have the same size
    for(int i = 0; i < numberOfMembers; ++i) {
        printf("Sending word:\t%d\n", buffer[i]);
    }
}
 
