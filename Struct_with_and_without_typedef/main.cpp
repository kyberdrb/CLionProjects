#include <assert.h>
#include <stdio.h>
#include <math.h>

struct FooWithoutTypedefWithoutInstance {
    float bar;
};

struct FooWithoutTypedefWithInstance {
    float bar;
    char c;
} fooInstance;  // 'fooInstance' is allocated on stack

typedef struct FooWithTypedefWithoutTypedefName {   // warning: ‘typedef’ was ignored in this declaration
                                                    // equivalent to 'FooWithoutTypedef'
    float bar;
};

typedef struct FooWithTypedefWithTypedefName {
    float bar;
} fooTypedef;   // 'fooTypedef' is not an instance allocated on stack,
                // but an alias to shorten the type in C where it would 
                // be 'struct FooWithTypedefWithTypedefName'
                // The typedef name is in C exported into the 'tag' namespace
                // so that it can be used in the entire application

struct FooWithExternalTypedefAndTypedefName {
    float bar;
};

typedef struct FooWithExternalTypedefAndTypedefName FooWithExternalTypedefAndTypedefName;   // this means the same as with the case where the typedef name
                                                                                            // was specified together with the struct definition;
                                                                                            // it works also the same way as in the case with the typedef
                                                                                            // specified in the struct definition

int main() {
    struct FooWithoutTypedefWithoutInstance fooWithoutTypedefWithoutInstance;   // valid in C and C++
    sizeof(struct FooWithoutTypedefWithoutInstance);
    FooWithoutTypedefWithoutInstance fooWithoutTypedefWithoutInstanceWithoutStructKeyword;  // invalid in C, valid in C++ ('struct' keyword is optional in C++) 
    sizeof(FooWithoutTypedefWithoutInstance);

    struct FooWithoutTypedefWithInstance fooWithoutTypedefWithInstance; // valid in C and C++
    FooWithoutTypedefWithInstance fooWithoutTypedefWithInstanceWithoutStructKeyword;    // invalid in C, valid in C++ ('struct' keyword is optional in C++) 
    printf("sizeof(fooInstance) =\t%d\n", sizeof(fooInstance));
    fooInstance.bar = 3.4;
    printf("fooInstance.bar =\t%f\n", fooInstance.bar);

    struct FooWithTypedefWithTypedefName fooWithTypedefWithTypedefName;   // valid in C and C++
    sizeof(struct FooWithTypedefWithTypedefName);
    sizeof(fooWithTypedefWithTypedefName);
    FooWithTypedefWithTypedefName fooWithTypedefWithTypedefNameWithoutStructKeyword;  // also valid in C 
                                                                                             // because of the 'typedef' with name in the struct declaration) 
                                                                                             // and C++ because the typedef is optional in C++
    sizeof(fooWithTypedefWithTypedefNameWithoutStructKeyword);
    sizeof(fooTypedef);

    struct FooWithExternalTypedefAndTypedefName fooWithExternalTypedefAndTypedefName;   // valid in C and C++
    sizeof(struct FooWithExternalTypedefAndTypedefName);
    sizeof(fooWithExternalTypedefAndTypedefName);
    FooWithExternalTypedefAndTypedefName fooWithExternalTypedefWithTypedefNameWithoutStructKeyword;  // also valid in C 
                                                                                             // because of the 'typedef' with name in the struct declaration) 
                                                                                             // and C++ because the typedef is optional in C++
    sizeof(FooWithExternalTypedefAndTypedefName);
    sizeof(fooWithTypedefWithTypedefNameWithoutStructKeyword);
    sizeof(fooTypedef);

    // My observation:
    // We can distinguish between 'typedef'-ed and non-typedef-ed structs with a naming convention that makes all struct's names start with a capital letter.
    // That way we can unambiguously distinguish a struct type from a primitive type.

    return 0;
}

