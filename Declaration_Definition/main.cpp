// Internal and External Linkage in C++: http://www.goldsborough.me/c/c++/linker/2016/03/30/19-34-25-internal_and_external_linkage_in_c++/

int f();                // declaration
int f();
int f();
int f();
int f();
int f();                // we can use as many forward declarations as we want, ...
int f() { return 42; }; // as long as we define it only once.
//int f() { return 13; }; // When we define the same function,
                          // i.e. function with the same signature/header,
                          // i.e. function with the same name and number, type and order of arguments
                          // multiple times it's a violation of the
                          // ODR - One Definition Rule

extern int i;   // declaration
int i{};        // definition, i.e. initialization - more precisely, value initialization or default initialization
int k = 0;      // definition: same as before with value initialization

extern int j = 5;   // declaration with definition; the same as (optimized)
int m = 5;


int main() {
    return 0;
}
