#include <cstdio>

int main() {
    int i = 7;
    char* pointerToChar = reinterpret_cast<char*>(&i); 
    float* pointerToFloatCastedFromAddressOfInt = reinterpret_cast<float*>(&i); // aliasing through other types like 'float', although it may have the same size as 'int'
                                                                                // is undefined behavior (UB).
    float* pointerToFloatCastedFromPointerToCharPointingToAddressOfInt = reinterpret_cast<float*>(pointerToChar);   // this is valid :P
                                                                                                                    // The '-Wstrict-aliasing' doesn't report an error
                                                                                                                    // even at level 3
    float f1 = *pointerToFloatCastedFromAddressOfInt;   // Of course is not a problem that we assign address of one pointer type to another,
                                                        // but the moment of dereferencing that pointer
    float f2 = *pointerToFloatCastedFromPointerToCharPointingToAddressOfInt;    // the same situation as in the line above - UB

    printf("int i = %d\n", i);
    printf("*pointerToChar = %c\n", *pointerToChar);    // aliasing through 'char' is alright because 'char' aliases all types 

    printf("*pointerToFloatCastedFromAddressOfInt = %f\n", *pointerToFloatCastedFromAddressOfInt);

    printf("*pointerToFloatCastedFromPointerToCharPointingToAddressOfInt = %f\n", 
            *pointerToFloatCastedFromPointerToCharPointingToAddressOfInt);

    return 0;
}

