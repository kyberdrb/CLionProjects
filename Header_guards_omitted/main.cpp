#include "header1.h"    // when no header guards are present in header1.h
                        // the definitions of the functions and global vairables are defined multiple times
                        // which is a violation of a ODR - One Definition Rule
#include "header2.h"

int main() {
    getNumber();
    return 0;
}

