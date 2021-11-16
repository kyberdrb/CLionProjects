#include "file.h"

int main() {
    getNumber();
    getDecimal();   // the function has been only defined in the file.h not defined, 
                    // therefore when we call it, the linker reports an error 'undefined reference'
    return 0;
}

