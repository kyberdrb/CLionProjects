# Endianness

**Endianness** is a way to specify the ordering of bytes in memory.

the following statement is one advantage of using little endian:

The little-endian system has the property that the same value can be read from memory at different lengths without using different addresses (even when alignment restrictions are imposed). For example, a 32-bit memory location with content 4A 00 00 00 can be read at the same address as either 8-bit (value = 4A), 16-bit (004A), 24-bit (00004A), or 32-bit (0000004A), all of which retain the same numeric value. Although this little-endian property is rarely used directly by high-level programmers, it is often employed by code optimizers as well as by assembly language programmers.

Another reason it exists is because it seems that it wasn't standardized back in the 1960s and 1970s; some companies (such as Intel with their x86 architecture) decided to go with little-endian (possibly due to the optimization reasoning above), whereas other companies selected big-endian.

- https://stackoverflow.com/questions/1001307/detecting-endianness-programmatically-in-a-c-program/1001373#1001373
- https://en.cppreference.com/w/c/language/object
- https://en.wikipedia.org/wiki/Endianness
- Big Endian vs. Little Endian: https://www.youtube.com/watch?v=seZLUbgbB7Y

