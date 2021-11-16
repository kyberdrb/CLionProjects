// Common C++ Error Messages #2 – Undefined reference: No definition: https://latedev.wordpress.com/2014/04/22/common-c-error-messages-2-unresolved-reference/

int foo();

int main() {
    foo();  // we fixed the linker error: undefined reference to `foo()' ...
            //  linker now finds the definition to the 'foo()' function
    return 0;
}

int foo() {
    return 42;
}
