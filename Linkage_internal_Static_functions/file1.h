#pragma once

//static int foo();   // when I include this header file into a source file and call this function, the linker will
                    // report an error: undefined reference to `foo()'
                    // because I only declared the function in the header file, but in order to call the function,
                    // the linker also needs the definition of the function

static int foo() {  // static - file scope - only (file1.h + file1.cpp) translation unit sees this function
    return 42;
}

int doSomething();  // extern - global scope - all translation units can see it