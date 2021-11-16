// Common C++ Error Messages #2 – Undefined reference: No definition: https://latedev.wordpress.com/2014/04/22/common-c-error-messages-2-unresolved-reference/

int foo();

int main() {
    foo();  // linker error: undefined reference to `foo()'
            //  no definition provided
    return 0;
}
