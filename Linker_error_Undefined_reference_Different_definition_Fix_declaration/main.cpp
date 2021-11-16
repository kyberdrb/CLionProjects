// Common C++ Error Messages #2 – Undefined reference: Wrong definition: https://latedev.wordpress.com/2014/04/22/common-c-error-messages-2-unresolved-reference/

int foo(int n);

int main() {
    foo(42);     // we fixed the linker error: undefined reference to `foo()' ...
                    //  linker now finds the definition to the 'foo' function
                    //  because the declaration and definition of the function 'foo' are now matching
    return 0;
}

int foo(int n) {
    return n;
}
