#pragma once

static int variable = 42;
const float decimal = 1.2;  // const global variables have internal linkage by default
static const char* greeting =  "Willkommen";

//You can use these functions to provide shared implementation logic to other functions within the same file.
// Various helper functions specific to a file are good candidates to be declared file-static.
// All global variables and global functions in the anonymous namespace are static by default.
// All static functions and static variables are linked internally by default.
// When we include this header in multiple files, the preprocessor expands this function with its definition
// into each file because the function has been already defined in the header file.
// The code compiles successfully because of the internal linkage.
// Internal linkage means that the linker will see each new definition in the translation units as a new copy. The
// definition of the function is encapsulated within each translation unit. The linker will not export, or externalize
// this function to other translation units. Therefore it conforms to the ODR.
static void foo() {
    static_cast<void*>(nullptr);
}
