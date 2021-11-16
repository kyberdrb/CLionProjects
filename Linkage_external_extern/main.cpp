// Internal and External Linkage in C++: http://www.goldsborough.me/c/c++/linker/2016/03/30/19-34-25-internal_and_external_linkage_in_c++/

extern int x;   // declaration of a non-const global variable - 'extern' by default - stored in 'bss' part of the Data Segment in memory
extern int f(); // declaration of a function - 'extern' by default

int y;
//extern int y{}; // error: redefinition of 'int y'

int main() {
    return 0;
}
