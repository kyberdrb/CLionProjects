#include <stdio.h>
#include <stdalign.h>
#include <stdint.h>

struct Foo {
    char c;
    int n;
};

// align to single bytes
#pragma pack(1)
struct Bar {
    char c;
    int n;
};

// align to 8 bytes
#pragma pop
#pragma pack(8)
struct BarAlignedTo8Bytes {
    char c;
    int n;
};

// restore packing
#pragma pop

struct Baz {
    char c;
    int n;
};

struct Qux {
    char c;                 // 4 bytes - 1 byte data, 3 bytes padding
    alignas(128) int n;     // 4 bytes - 4 bytes data, no padding - alignas() is effective only on arrays
    alignas(32) float data[4]; // 
};

// every object of type struct sse_t will be aligned to 16-byte boundary
// (note: needs support for DR 444)
struct sse_t
{
  alignas(16) float sse_data[4];    // assuming IEEE-754 for float (4 bytes) - array of 4 floats = 4*4=16 bytes aligned to 16 byte boundaries
};

#pragma pack(16)
struct sse_t_pragma_pack_16
{
  float sse_data[4];
  short s;
  char c;
};

#pragma pack(32)
struct sse_t_pragma_pack_32
{
  float sse_data[4];
};

#pragma pack(4)
 
// every object of type struct data will be aligned to 128-byte boundary
struct data {
  char x;
  alignas(128) char cacheline[128]; // over-aligned array of char, 
                                    // not array of over-aligned chars
};

// GNU member packing
struct PackedStruct {
    char text[21];
    float decimal;
}__attribute__((__packed__));

struct test
{
    unsigned char  field1 __attribute__((__packed__)); // packing for char is ignored
    unsigned short field2 __attribute__((__packed__));
    unsigned long  field3 __attribute__((__packed__));
} var1, var2;

struct test2
{
    unsigned char  field1 __attribute__((__packed__));
    unsigned short field2 __attribute__((__packed__));
    unsigned long  field3;  // all members needs to be marked for packing in order for the
                            // '__attribute__((__packed__))' directive to be effective
                            // When some of the members have this attribute and one of them doesn't
                            // the packing has no effect - it aligns the members to the default alignment value
};

// struct and its members are aligned in the memory addresses
// that are multiples of 4 because the alignment is set to 4 bytes
// => 4 bytes/signs in one row
struct fooWith4ByteAlignment { 
    int a;      // a a a a 
    char b;     // b . . .
    float c;    // c c c c
    double d;   // d d d d
                // d d d d
    bool e;     // b . . .
};

// 8 byte alignment => 8 bytes/signs in one row
struct alignas(8) fooWith8ByteAlignment { 
    int a;      // a a a a 
    char b;     //         b . . .
    float c;    // c c c c 
    double d;   //         d d d d
                // d d d d
    bool e;     //         e . . .
};

struct fooWith8ByteAlignmentAndPadding 
{ 
    int a;         // 4 bytes 
    char b;        // 1 byte 
    char _pad0[3]; // 3 bytes padding to put c on a 8-byte boundary  
    float c;       // 4 bytes 
    char _pad1[4]; // 4 bytes padding to put d on a 8-byte boundary 
    double d;      // 8 bytes 
    bool e;        // 1 byte 
    char _pad2[7]; // 7 bytes padding to make sizeof struct multiple of 8 
};

#pragma pack(1)
struct TestPragmaPack1
{
   char AA;
   int BB;
   char CC;
};

#pragma pop
#pragma pack(4)
struct TestPragmaPack4
{
   char AA;
   int BB;
   char CC;
};

#pragma pop
#pragma pack(8)
struct alignas(8) TestPragmaPack8
{
   char AA;
   int BB;
   char CC;
};

#pragma pop
struct alignas(8) TestAlignas8
{
   char AA;
   int BB;
   char CC;
};

#pragma pack(8)
struct alignas(8) TestPragmaPack8AlignAs8
{
   char AA;
   int BB;
   char CC;
};

#pragma pop

int main() {
    printf("alignof(struct{char c; int n;}) =\t%zu\n", alignof(struct Foo)); 
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct Foo)); 

    printf("pragma pack(1) - alignment to single bytes\n");
    printf("alignof(struct{char c; int n;}) =\t%zu\n", alignof(struct Bar)); 
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct Bar)); 

    printf("pragma pack(8) - alignment to 8 bytes\n");
    printf("alignof(struct{char c; int n;}) =\t%zu\n", alignof(struct BarAlignedTo8Bytes)); 
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct BarAlignedTo8Bytes)); 

    printf("pragma pack(4) - restored packing - alignas() alignment to single bytes\n");
    printf("alignof(struct{char c; int n;}) =\t%zu\n", alignof(struct Baz)); 
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct Baz)); 

    printf("alignof(struct{char c; int n;}) =\t%zu\n", alignof(struct Qux)); 
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct Qux)); 

    printf("alignof(data) =\t%zu\n", alignof(struct data)); 
    printf("sizeof(data) = %zu (1 byte + 127 bytes padding + 128-byte array)\n",
           sizeof(struct data));
 
    printf("\n");
    printf("alignment of sse_t is %zu\n", alignof(struct sse_t));
    printf("size of sse_t is %zu\n", sizeof(struct sse_t));
 
    printf("\n");
    printf("alignment of sse_t_pragma_pack_16 is %zu\n", alignof(sse_t_pragma_pack_16));
    printf("size of sse_t_pragma_pack_16 is %zu\n", sizeof(struct sse_t_pragma_pack_16));

    printf("\n");
    printf("alignment of sse_t_pragma_pack_32 is %zu\n", alignof(sse_t_pragma_pack_32));
    printf("size of sse_t_pragma_pack_32 is %zu\n", sizeof(struct sse_t_pragma_pack_32));

    printf("\n");
    alignas(2048) struct data d; // this instance of data is aligned even stricter
    printf("alignment of instance 'd' is %zu\n", alignof(d));   // alignof() changes alignment, 
    printf("size of instance 'd' is %zu\n\n", sizeof(d));

    printf("__attribute__((__packed__)) automatically aligns the entire struct to single bytes, i.e. with one byte granularity\n");
    printf("alignof(struct {char text[21]; float decimal;}) =\t%zu\n", alignof(struct PackedStruct)); 
    printf("sizeof(struct {char text[21]; float decimal;}) =\t%zu\n\n", sizeof(struct PackedStruct)); 

    printf("__attribute__((__packed__)) automatically aligns the specific members of the struct to single bytes, i.e. with one byte granularity\n");
    printf("alignof(struct {char(packed), short(packed), long}) =\t%zu\n", alignof(struct test)); 
    printf("sizeof(struct {char(packed), short(packed), long}) =\t%zu\n\n", sizeof(struct test)); 

    printf( "__attribute__((__packed__)) is ineffective when at least one of the members wasn't marked for packing"
            "even when the rest of them was marked for packing\n");
    printf("alignof(struct {char(packed), short(packed), long}) =\t%zu\n", alignof(struct test2)); 
    printf("sizeof(struct {char(packed), short(packed), long}) =\t%zu\n\n", sizeof(struct test2)); 

    printf("alignment of fooWith4ByteAlignment: struct{int, char, float, double, bool} is %zu\n", alignof(fooWith4ByteAlignment));
    printf("size of fooWith4ByteAlignment: struct{int, char, float, double, bool} is %zu\n\n", sizeof(fooWith4ByteAlignment));

    printf("alignment of fooWith8ByteAlignment: struct{int, char, float, double, bool} is %zu\n", alignof(fooWith8ByteAlignment));
    printf("size of fooWith8ByteAlignment: struct{int, char, float, double, bool} is %zu\n\n", sizeof(fooWith8ByteAlignment));

    printf("alignment of fooWith8ByteAlignmentAndPadding: struct{int, char, float, double, bool} is %zu\n", alignof(fooWith8ByteAlignmentAndPadding));
    printf("size of fooWith8ByteAlignmentAndPadding: struct{int, char, float, double, bool} is %zu\n\n", sizeof(fooWith8ByteAlignmentAndPadding));

    alignas(8)   int a;     // force alignment of variables in memory to the required number of bytes
                            // so that each beginning address of a variable will be divisible with the value (number of bytes)
                            // we aligned the variable/member/struct/class to
                            // Valid aligns are always powers of 2: 1, 2, 4, 8 ...
                            // Alignment of 0 is alway ignored.
    printf("sizeof(int) aligned to 8 bytes with alignas(8):\t\t%zu\n", sizeof(a));
    printf("alignof(int) aligned to 8 bytes with alignas(8):\t%zu\n", alignof(a));
    printf("address of 'a':\t%p\n", &a); // eg. 0000006C0D9EF908
    printf("sizeof(&a):\t%zu\n", sizeof(&a));
    uint64_t addressOfA_AsNumber = reinterpret_cast<uint64_t>(&a);
    printf("address of 'a':\t%zu\n\n", addressOfA_AsNumber);

    alignas(256) long b[4]; 
    printf("%p\n\n", &b); // eg. 0000006C0D9EFA00

    alignas(16) int aa[4];
    alignas(4096) int bb[4];
    printf("&aa[0]:\t%p\t<- address is aligned to 16 (16^1) byte boundary, therefore the first digit is 0 - divisible by 16\n", aa);
    printf("&bb[0]:\t%p\t<- address is aligned to 256 (16^3) byte boundary, therefore the first three digits are 0 - divisible by 4096\n\n", bb);

    printf("#pragma pack(1)\n");
    printf("alignof(struct{char, int, char}) =\t%zu\n", alignof(struct TestPragmaPack1));
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct TestPragmaPack1)); 

    printf("#pragma pack(4)\n");
    printf("alignof(struct{char, int, char}) =\t%zu\n", alignof(struct TestPragmaPack4)); 
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct TestPragmaPack4)); 

    printf("#pragma pack(8)\n");
    printf("alignof(struct{char, int, char}) =\t%zu\n", alignof(struct TestPragmaPack8));
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct TestPragmaPack8)); 

    printf("struct alignas(8)\n");
    printf("alignof(struct{char, int, char}) =\t%zu\n", alignof(struct TestAlignas8)); 
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct TestAlignas8)); 

    printf("#pragma pack(8) + struct alignas(8)\n");
    printf("alignof(struct{char, int, char}) =\t%zu\n", alignof(struct TestPragmaPack8AlignAs8));
    printf("sizeof(struct{char c; int n;}) =\t%zu\n\n", sizeof(struct TestPragmaPack8AlignAs8)); 

    return 0;
}

