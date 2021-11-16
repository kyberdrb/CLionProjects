#include <iostream>

// https://en.cppreference.com/w/cpp/language/ub

// Signed overflow
int foo(int x) {
    std::cout << "Received value:\t" << x << std::endl;
    std::cout << "Incremented value:\t" << x+1 << std::endl;
    std::cout << "Comparison from rvalue with sum - undefined, may be true:\t" << (x+1 > x) << std::endl;

    int incrementedValue = x+1;
    std::cout << "Incremented value:\t" << incrementedValue << std::endl;
    std::cout << "Comparison from rvalue without sum - undefined, may be false:\t" << (incrementedValue > x) << std::endl;
    bool isTrue = incrementedValue > x;
    std::cout << "Comparison from lvalue - undefined, may be false:\t" << isTrue << std::endl;
    return isTrue; // either true or UB due to signed overflow
}

#include <climits>
int signed_overflow() {
    std::cout << "Signed overflow" << std::endl;
    int inputValue = INT_MAX;
    std::cout << "Input value:\t" <<inputValue << std::endl;
    int value = foo(inputValue);
    std::cout << "Returned value:\t" << value << std::endl;
    std::cout << std::endl;
    return value;
}

// Access out of bounds
bool exists_in_table(int v)
{
    int table[4] = {};
    // return true in one of the first 4 iterations or UB due to out-of-bounds access
    for (int i = 0; i <= 4; i++) {
        if (table[i] == v) return true;
    }
    return false;
}

void access_out_of_bounds() {
    std::cout << "Access out of bounds" << std::endl;
    exists_in_table(-1);
    std::cout << std::endl;
}

// Uninitialized scalar
std::size_t f(int x)
{
    std::size_t a;
    if(x) // either x nonzero or UB
        a = 42;
    return a;
}

// EXPLORE: Does this really trigger undefined behavior? Although the parameter of the function 'f' is initialized?
void unitialized_scalar_scenario_1() {
    std::cout << "Uninitialized scalar - scenario 1" << std::endl;
    f(3);
    std::cout << std::endl;
}

void unitialized_scalar_scenario_2() {
    std::cout << "Uninitialized scalar - scenario 2" << std::endl;
    bool p; // uninitialized local variable
    if(p) // UB access to uninitialized scalar
        std::puts("p is true");
    if(!p) // UB access to uninitialized scalar
        std::puts("p is false");
    std::cout << std::endl;
}

// Invalid scalar
int f() {
    bool b = true;
    unsigned char* p = reinterpret_cast<unsigned char*>(&b);
    *p = 10;
    // reading from b is now UB
    return b == 0;
}

void invalid_scalar() {
    std::cout << "Invalid scalar" << std::endl;
    f();
    std::cout << std::endl;
}

// Null pointer dereference
int foo(int* p) {
    int x = *p;         // Process finished with exit code 139 (interrupted by signal 11: SIGSEGV) - Segmentation fault
    if(!p) return x;    // Either UB above or this branch is never taken
    else return 0;
}
int bar() {
    int* p = nullptr;
    return *p;        // Unconditional UB - Process finished with exit code 139 (interrupted by signal 11: SIGSEGV) - Segmentation fault
}

int null_pointer_dereference_scenario_1() {
    std::cout << "Null pointer dereference - scenario 1" << std::endl;
    foo(nullptr);
    std::cout << std::endl;
}

int null_pointer_dereference_scenario_2() {
    std::cout << "Null pointer dereference - scenario 2" << std::endl;
    bar();
    std::cout << std::endl;
}

void access_to_pointer_passed_to_realloc() {
    //  Choose clang to observe the output shown

    #include <iostream>
    #include <cstdlib>

    int *p = (int*)std::malloc(sizeof(int));
    int *q = (int*)std::realloc(p, sizeof(int));
    *p = 1; // UB access to a pointer that was passed to realloc
    *q = 2;
    if (p == q) // UB access to a pointer that was passed to realloc
        std::cout << *p << *q << '\n';
}

// Infinite loop without side-effects
#include <iostream>
int fermat() {
    const int MAX = 1000;
    int a = 1, b = 1, c = 1;
    // Endless loop with no side effects is UB
    while (1) {
        if (((a * a * a) == ((b * b * b) + (c * c * c)))) return 1;
        a++;
        if (a > MAX) {
            a = 1;
            b++;
        }
        if (b > MAX) {
            b = 1;
            c++;
        }
        if (c > MAX) { c = 1; }
    }
    return 0;
}

void infinite_loop_without_sideeffects() {
    //  Choose clang to observe the output shown
    if (fermat())
        std::cout << "Fermat's Last Theorem has been disproved.\n";
    else
        std::cout << "Fermat's Last Theorem has not been disproved.\n";
}

int main() {
    signed_overflow();
    access_out_of_bounds();
    unitialized_scalar_scenario_1();
    unitialized_scalar_scenario_2();
    invalid_scalar();
//    null_pointer_dereference_scenario_1();  // dangerous
//    null_pointer_dereference_scenario_2();  // dangerous
    access_to_pointer_passed_to_realloc();
//    infinite_loop_without_sideeffects();    // dangerous - it has side-effects

    return 0;
}