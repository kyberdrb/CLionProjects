Common C++ Error Messages #2 – Undefined reference: Didn’t Link Object File: https://latedev.wordpress.com/2014/04/22/common-c-error-messages-2-unresolved-reference/

If you compile f1.cpp on its own you get this:

    $ g++ f1.cpp -o myprog

    /usr/bin/ld: /tmp/cceW84rh.o: in function `main':
    f1.cpp:(.text+0x5): undefined reference to `foo()'
    collect2: error: ld returned 1 exit status

and if you compile f2.cpp on its own, you get this even more frightening one:

    $ g++ f2.cpp -o myprog

    /usr/bin/ld: /usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/../../../../lib/Scrt1.o: in function `_start':
    (.text+0x24): undefined reference to `main'
    collect2: error: ld returned 1 exit status

In this situation, you need to compile both the the source files on the same command line, for example, using GCC:

    $ g++ f1.cpp f2.cpp -o myprog

which produces the final executable.