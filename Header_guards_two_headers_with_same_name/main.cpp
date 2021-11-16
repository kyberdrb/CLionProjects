// In large programs, it’s possible to have two separate header files (included from different directories) 
// that end up having the same filename (e.g. directoryA\config.h and directoryB\config.h). 
// If only the filename is used for the include guard (e.g. CONFIG_H), 
// these two files may end up using the same guard name. If that happens, any file that includes 
// (directly or indirectly) both config.h files will not receive the contents of the include file to 
// be included second. This will probably cause a compilation error.
// Because of this possibility for guard name conflicts, many developers recommend using a more 
// complex/unique name in your header guards. Some good suggestions are a naming convention of 
// <PROJECT>_<PATH>_<FILE>_H , <FILE>_<LARGE RANDOM NUMBER>_H, or <FILE>_<CREATION DATE>_H

#include "dirA/header.h"
#include "dirB/header.h"

int main() {
    getNumber();
    getDecimal();   // in this case the getDecimal function in the header.h in dirB doesn't get included
                    // because the header guard in header.h in dirA has been already defined
    return 0;
}

