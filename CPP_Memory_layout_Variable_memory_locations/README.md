# Memory Layout of C Programs

Examples of memory usage for various types of variables.

Preprocess source file
- stop compilation after preprocessor and before compiler
- creates translation units

        $ gcc -E source.cpp > source_preprocessed.cpp

Show memory layout of classes

    $ clang -cc1 -fdump-record-layouts source_preprocessed.cpp

if the source code contains `#include` statements, run the preprocessor on this source file first

    $ clang -cc1 -fdump-record-layouts source_preprocessed.cpp

Assembler output
- stop compilation after compiler, but before assembly, i.e. before generating binary object file

        $ g++ -S -o source.disassembled source.cpp

    or annotated disassembly: each line has the generated assembly code underneath

        $ g++ -S -fverbose-asm -g source.cpp -o source.disassembled
        $ as -alhnd source.disassembled > source.disassembled.annotated

Compile without linking

- Use the `-c` flag

        $ gcc -c -g -o OBJECT_FILE.o SOURCE_FILE.cpp

- Generate another assembly output from the compilation wihtout linking into the final executable

        $ objdump -d -M intel -S OBJECT_FILE.o

- Variable storage locations - ELF

        nm --demangle OBJECT_FILE_OR_EXECUTABLE

        # compile with debugging symbols for gcc, i.e. with the '-g' or '-ggdb', and stop before linking phase with '-c'
        gcc -c -ggdb -o OBJECT_FILE SOURCE.cpp
        objdump --source --reloc OBJECT_FILE

`objdump` switches
- `-r` / `--reloc`

        Print the relocation entries of the file.  If used with -d or -D, the relocations are printed
           interspersed with the disassembly.
- `-S` / `--source`

           Display source code intermixed with disassembly, if possible.  Implies -d.

- `-d` / `--disassemble`
       --disassemble=symbol
           Display the assembler mnemonics for the machine instructions from the input file.

Memory segments and their sizes
- perform full compilation: preprocessor, compilator, linker

        $ g++ -o executable_name source.cpp
        $ size executable_name

I also noticed that different compilers produce executables of different sizes. Compilers are sorted in ascending order by the executable size shown under the `dec` column in the output of the `size` utility. Total size of the executable in the output of the `size` utility is given in bytes:
1. gcc
1. clang
1. g++

## Source
- https://www.geeksforgeeks.org/memory-layout-of-c-program/
- https://www.geeksforgeeks.org/storage-classes-in-c/
- https://www.tenouk.com/ModuleZ.html
- https://stackoverflow.com/questions/4239834/global-variables-in-c-are-static-or-not/14082258#14082258
- http://www.goldsborough.me/c/c++/linker/2016/03/30/19-34-25-internal_and_external_linkage_in_c++/
- http://www.goldsborough.me/c/c++/linker/2016/03/30/19-34-25-internal_and_external_linkage_in_c++/
- http://www.it.uc3m.es/pbasanta/asng/course_notes/variables_en.html
- https://pabloariasal.github.io/2020/01/02/static-variable-initialization/
- https://en.cppreference.com/w/cpp/language/storage_duration
- https://en.cppreference.com/w/cpp/language/static
- https://stackoverflow.com/questions/8102125/is-local-static-variable-initialization-thread-safe-in-c11
- https://stackoverflow.com/questions/1661529/is-meyers-implementation-of-the-singleton-pattern-thread-safe
- https://stackoverflow.com/questions/5567529/what-makes-a-static-variable-initialize-only-once
- https://www.bogotobogo.com/cplusplus/statics.php
- https://www.learncpp.com/cpp-tutorial/811-static-member-variables/
- https://stackoverflow.com/questions/35288838/external-linkage-for-name-inside-unnamed-namespace/35291419#35291419
- https://de.wikipedia.org/wiki/Executable_and_Linking_Format
- https://stackoverflow.com/questions/13396748/are-objects-in-anonymous-namespace-implicitly-static/13396843#13396843
- https://stackoverflow.com/questions/93039/where-are-static-variables-stored-in-c-and-c
- https://stackoverflow.com/questions/32509820/address-of-static-member-in-a-class
- https://stackoverflow.com/questions/6264249/how-does-the-compilation-linking-process-work

---

- https://eli.thegreenplace.net/2012/12/17/dumping-a-c-objects-memory-layout-with-clang/
- https://stackoverflow.com/questions/137038/how-do-you-get-assembler-output-from-c-c-source-in-gcc/137479#137479
- https://unix.stackexchange.com/questions/434561/size-command-unit
- https://ma.ttias.be/grep-show-lines-before-and-after-the-match-in-linux/