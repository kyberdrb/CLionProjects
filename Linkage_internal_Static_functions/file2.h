#pragma once

//int foo() {       // file1.h translation unit has one 'static' definition of the function foo(), and here, in file2.h
//    return 13;    // we provide another 'global' definition of the foo() function
//}                 // static foo() is available only in file1 translation unit at linking stage
                    // global foo() is available for all translation units at linking stage
                    // Therefore, linker conflict occurs - multiple definitions of the same symbol 'foo()'.
                    // The conflict occurs even when we don't include file1.h and file2.h in one file.

static int foo() {
    return 13;
}

int doSomethingElse();