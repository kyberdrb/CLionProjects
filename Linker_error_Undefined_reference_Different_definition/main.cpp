// Common C++ Error Messages #2 – Undefined reference: Wrong definition: https://latedev.wordpress.com/2014/04/22/common-c-error-messages-2-unresolved-reference/

int foo();

int main() {
    foo();  // linker error: undefined reference to `foo()'
            //  reference to 'foo()' function is missing
            //  function 'foo()' is declared, but
            //  function 'foo(int n)' is defined => mismatch which couses the linker to fail
    return 0;
}

int foo(int n) {
    return n;
}
