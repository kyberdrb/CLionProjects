#pragma once

namespace { // everything what's inside the anonymous namespace has internal linkage by default and has static storage by default
    int variable = 42;  // internal linkage by default, just like a global static variable

    //You can use these functions to provide shared implementation logic to other functions within the same file.
    // Various helper functions specific to a file are good candidates to be declared file-static.
    // All global variables and global functions in the anonymous namespace are static by default.
    // All static functions and static variables are linked internally by default.
    // When we include this header in multiple files, the preprocessor expands this function with its definition
    // into each file because the function has been already defined in the header file.
    // The code compiles successfully because of the internal linkage.
    // Internal linkage means that the linker will see each new definition in the translation units as a new copy. The
    // definition of the function is encapsulated within each translation unit.
    void foo() {
        static_cast<void*>(nullptr);
    }
}

//namespace customNamespace {
//    int number = 13;    // multiple definition of `customNamespace::number'; CMakeFiles/Anonymous_namespace.dir/main.cpp.o:(.data+0x4): first defined here
//                        // external linkage by default
//                        // global namespace variable defined (value initializer) at declaration
//                        // that's because the header is included, thus defined, in multiple files which violates the
//                        // ODR - One Definition Rule. And the linker reports an error.
//                        // solution: either make it extern without definition (initialization),
//                        // or encapsulate it as a static member variable of a class or struct
//}
