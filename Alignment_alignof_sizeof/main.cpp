#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <stdalign.h>
#include <stddef.h>

// The struct is aligned by the size of the member with the largest size
// Smaller members are padded
// Members that are not multiples of the size of the largest member are padded as well to the closest multiple
struct Foo {
    char c;
    int n;
};

struct Bar {
    char a;
    char b;
};

int main() {
    printf("alignof(char) =\t%zu\n", alignof(char));   // '%zu' means 'u' - unsigned int of size 'z' - size_t
    printf("sizeof(char) =\t%zu\n\n", sizeof(char));

    printf("alignof(max_align_t) =\t%zu\n", alignof(max_align_t));   // maximum alignment/padding in bytes is defined in 'stddef.h'
    printf("sizeof(max_align_t) =\t%zu\n\n", sizeof(max_align_t)); 

    printf("alignof(float[10]) = \t%zu\n", alignof(float[10]));
    printf("sizeof(float[10]) = \t%zu\n\n", sizeof(float[10]));

    printf("alignof(struct{char c; int n;}) =\t%zu\n", alignof(struct Foo)); 
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct Foo)); 

    printf("alignof(struct{char a; char b;}) =\t%zu\n", alignof(struct Bar)); 
    printf("sizeof(struct{char a; char b;}) =\t%zu\n\n", sizeof(struct Bar)); 

    return 0;
}

