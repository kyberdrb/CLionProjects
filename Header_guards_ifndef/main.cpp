#include "header1.h"    // header1.h has header guard which means that it will be expanded only once by the 
                        // preprocessor; the definition of the functions and global vairables will be
                        // defined multiple times which conforms to ODR - One Definition Rule
#include "header2.h"

int main() {
    getNumber();
    return 0;
}

