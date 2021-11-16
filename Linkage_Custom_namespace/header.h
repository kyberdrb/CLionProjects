#pragma once

namespace customNamespace {
//    int variable = 13;    // multiple definition of `customNamespace::number'; CMakeFiles/Anonymous_namespace.dir/main.cpp.o:(.data+0x4): first defined here
//                        // global namespace variable defined (value initializer) at declaration
//                        // that's because the header is included, in multiple files,
//                        // and when preprocessor sees this include directive, expands it and as a consequence of this
//                        // expansion it includes also the definition of the function included in the header file
//                        // in multiple places/files which violates the
//                        // ODR - One Definition Rule. And the linker reports an error.
//                        // solution: either make it extern without definition (initialization),
//                        // or encapsulate it as a static member variable of a class or struct

    extern int variable;    // this is only declaration - definition is necessary before using this variable
}
