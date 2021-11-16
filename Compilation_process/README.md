# C++ Compilation Process - Phases of Translation

What's behind the command

    gcc -o hello hello.cpp

## Beginning

- source and header files

## Preprocessing

- Input: source and header files
    - human readable C/C++ code

- Commands:

        cpp hello.cpp > hello.i

    or

        gcc -E hello.cpp > hello.i

- Phase 1

- Phase 2

- Phase 3

- Phase 4

- Output: translation units
    - human readable C/C++ code

- Example output - translation unit `hello.i` (same for either of the mentioned commands):

        $ cat hello.i

        # 1 "hello.cpp"
        # 1 "<built-in>"
        # 1 "<command-line>"
        # 1 "/usr/include/stdc-predef.h" 1 3 4
        # 1 "<command-line>" 2
        # 1 "hello.cpp"
        # 1 "header.h" 1
            

        extern float qux;
        # 2 "hello.cpp" 2

        float qux = 1.3;

        void foo(float number) {
            number += 1.0;
        }

        int main() {
            foo(qux);
            return 0;
        }

## Compilation

- Input: translation units
    - human readable C/C++ code

- Commands:

        gcc -S hello.i
        # produces a file with the same name ans the input file with an '.s' extension

    or

        gcc -S -o hello.s hello.cpp

- Phase 5

- Phase 6

- Phase 7

- Phase 8 (missing in C language compilation process, therefore the C language has 8 translation phases)
    - instantiation of templates

- Output: assembler files
    - human readable assembly code for each translation unit

- Example output (same for either of the commands):

        $ cat hello.s

            .file	"hello.cpp"
            .text
            .globl	qux
            .data
            .align 4
            .type	qux, @object
            .size	qux, 4
        qux:
            .long	1067869798
            .text
            .globl	foo
            .type	foo, @function
        foo:
        .LFB0:
            .cfi_startproc
            pushq	%rbp
            .cfi_def_cfa_offset 16
            .cfi_offset 6, -16
            movq	%rsp, %rbp
            .cfi_def_cfa_register 6
            movss	%xmm0, -4(%rbp)
            movss	-4(%rbp), %xmm1
            movss	.LC0(%rip), %xmm0
            addss	%xmm1, %xmm0
            movss	%xmm0, -4(%rbp)
            nop
            popq	%rbp
            .cfi_def_cfa 7, 8
            ret
            .cfi_endproc
        .LFE0:
            .size	foo, .-foo
            .globl	main
            .type	main, @function
        main:
        .LFB1:
            .cfi_startproc
            pushq	%rbp
            .cfi_def_cfa_offset 16
            .cfi_offset 6, -16
            movq	%rsp, %rbp
            .cfi_def_cfa_register 6
            movl	qux(%rip), %eax
            movd	%eax, %xmm0
            call	foo
            movl	$0, %eax
            popq	%rbp
            .cfi_def_cfa 7, 8
            ret
            .cfi_endproc
        .LFE1:
            .size	main, .-main
            .section	.rodata
            .align 4
        .LC0:
            .long	1065353216
            .ident	"GCC: (Arch Linux 9.3.0-1) 9.3.0"
            .section	.note.GNU-stack,"",@progbits

## Assembly

- Input: assembler files
    - human readable assembly code for each translation unit

- Commands:

        as -o hello.o hello.s

    or

        gcc -c -o hello.o hello.cpp

    or (with debugging information `-g` or `-ggdb` which can be useful for `nm` or `objdump` utilities)

        gcc -c -ggdb -o OBJECT_FILE SOURCE.cpp

    the `-c` flag stopps compilation before linking

- Output: object/machine/binary/byte/ELF code without resolved external dependencies, e.g. libraries
    - human unreadable code for each translation unit

- Example output for `as` utility. The output is printed out with `hexdump` utility with options `-C` for a separate column with ASCII characters, and `-v` for displaying full binary output of the object file. Very similar output can be achieved with the utility `xxd` as well:

        $ as -o hello.o hello.s
        $ hexdump -C -v hello.o

        00000000  7f 45 4c 46 02 01 01 00  00 00 00 00 00 00 00 00  |.ELF............|
        00000010  01 00 3e 00 01 00 00 00  00 00 00 00 00 00 00 00  |..>.............|
        00000020  00 00 00 00 00 00 00 00  18 03 00 00 00 00 00 00  |................|
        00000030  00 00 00 00 40 00 00 00  00 00 40 00 0d 00 0c 00  |....@.....@.....|
        00000040  55 48 89 e5 f3 0f 11 45  fc f3 0f 10 4d fc f3 0f  |UH.....E....M...|
        00000050  10 05 00 00 00 00 f3 0f  58 c1 f3 0f 11 45 fc 90  |........X....E..|
        00000060  5d c3 55 48 89 e5 8b 05  00 00 00 00 66 0f 6e c0  |].UH........f.n.|
        00000070  e8 00 00 00 00 b8 00 00  00 00 5d c3 66 66 a6 3f  |..........].ff.?|
        00000080  00 00 80 3f 00 47 43 43  3a 20 28 41 72 63 68 20  |...?.GCC: (Arch |
        00000090  4c 69 6e 75 78 20 39 2e  33 2e 30 2d 31 29 20 39  |Linux 9.3.0-1) 9|
        000000a0  2e 33 2e 30 00 00 00 00  14 00 00 00 00 00 00 00  |.3.0............|
        000000b0  01 7a 52 00 01 78 10 01  1b 0c 07 08 90 01 00 00  |.zR..x..........|
        000000c0  1c 00 00 00 1c 00 00 00  00 00 00 00 22 00 00 00  |............"...|
        000000d0  00 41 0e 10 86 02 43 0d  06 5d 0c 07 08 00 00 00  |.A....C..]......|
        000000e0  1c 00 00 00 3c 00 00 00  00 00 00 00 1a 00 00 00  |....<...........|
        000000f0  00 41 0e 10 86 02 43 0d  06 55 0c 07 08 00 00 00  |.A....C..U......|
        00000100  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        00000110  00 00 00 00 00 00 00 00  01 00 00 00 04 00 f1 ff  |................|
        00000120  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        00000130  00 00 00 00 03 00 01 00  00 00 00 00 00 00 00 00  |................|
        00000140  00 00 00 00 00 00 00 00  00 00 00 00 03 00 03 00  |................|
        00000150  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        00000160  00 00 00 00 03 00 04 00  00 00 00 00 00 00 00 00  |................|
        00000170  00 00 00 00 00 00 00 00  00 00 00 00 03 00 05 00  |................|
        00000180  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        00000190  00 00 00 00 03 00 07 00  00 00 00 00 00 00 00 00  |................|
        000001a0  00 00 00 00 00 00 00 00  00 00 00 00 03 00 08 00  |................|
        000001b0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        000001c0  00 00 00 00 03 00 06 00  00 00 00 00 00 00 00 00  |................|
        000001d0  00 00 00 00 00 00 00 00  0b 00 00 00 11 00 03 00  |................|
        000001e0  00 00 00 00 00 00 00 00  04 00 00 00 00 00 00 00  |................|
        000001f0  0f 00 00 00 12 00 01 00  00 00 00 00 00 00 00 00  |................|
        00000200  22 00 00 00 00 00 00 00  13 00 00 00 12 00 01 00  |"...............|
        00000210  22 00 00 00 00 00 00 00  1a 00 00 00 00 00 00 00  |"...............|
        00000220  00 68 65 6c 6c 6f 2e 63  70 70 00 71 75 78 00 66  |.hello.cpp.qux.f|
        00000230  6f 6f 00 6d 61 69 6e 00  12 00 00 00 00 00 00 00  |oo.main.........|
        00000240  02 00 00 00 05 00 00 00  fc ff ff ff ff ff ff ff  |................|
        00000250  28 00 00 00 00 00 00 00  02 00 00 00 09 00 00 00  |(...............|
        00000260  fc ff ff ff ff ff ff ff  31 00 00 00 00 00 00 00  |........1.......|
        00000270  04 00 00 00 0a 00 00 00  fc ff ff ff ff ff ff ff  |................|
        00000280  20 00 00 00 00 00 00 00  02 00 00 00 02 00 00 00  | ...............|
        00000290  00 00 00 00 00 00 00 00  40 00 00 00 00 00 00 00  |........@.......|
        000002a0  02 00 00 00 02 00 00 00  22 00 00 00 00 00 00 00  |........".......|
        000002b0  00 2e 73 79 6d 74 61 62  00 2e 73 74 72 74 61 62  |..symtab..strtab|
        000002c0  00 2e 73 68 73 74 72 74  61 62 00 2e 72 65 6c 61  |..shstrtab..rela|
        000002d0  2e 74 65 78 74 00 2e 64  61 74 61 00 2e 62 73 73  |.text..data..bss|
        000002e0  00 2e 72 6f 64 61 74 61  00 2e 63 6f 6d 6d 65 6e  |..rodata..commen|
        000002f0  74 00 2e 6e 6f 74 65 2e  47 4e 55 2d 73 74 61 63  |t..note.GNU-stac|
        00000300  6b 00 2e 72 65 6c 61 2e  65 68 5f 66 72 61 6d 65  |k..rela.eh_frame|
        00000310  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        00000320  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        00000330  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        00000340  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        00000350  00 00 00 00 00 00 00 00  20 00 00 00 01 00 00 00  |........ .......|
        00000360  06 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        00000370  40 00 00 00 00 00 00 00  3c 00 00 00 00 00 00 00  |@.......<.......|
        00000380  00 00 00 00 00 00 00 00  01 00 00 00 00 00 00 00  |................|
        00000390  00 00 00 00 00 00 00 00  1b 00 00 00 04 00 00 00  |................|
        000003a0  40 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |@...............|
        000003b0  38 02 00 00 00 00 00 00  48 00 00 00 00 00 00 00  |8.......H.......|
        000003c0  0a 00 00 00 01 00 00 00  08 00 00 00 00 00 00 00  |................|
        000003d0  18 00 00 00 00 00 00 00  26 00 00 00 01 00 00 00  |........&.......|
        000003e0  03 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        000003f0  7c 00 00 00 00 00 00 00  04 00 00 00 00 00 00 00  ||...............|
        00000400  00 00 00 00 00 00 00 00  04 00 00 00 00 00 00 00  |................|
        00000410  00 00 00 00 00 00 00 00  2c 00 00 00 08 00 00 00  |........,.......|
        00000420  03 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        00000430  80 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        00000440  00 00 00 00 00 00 00 00  01 00 00 00 00 00 00 00  |................|
        00000450  00 00 00 00 00 00 00 00  31 00 00 00 01 00 00 00  |........1.......|
        00000460  02 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        00000470  80 00 00 00 00 00 00 00  04 00 00 00 00 00 00 00  |................|
        00000480  00 00 00 00 00 00 00 00  04 00 00 00 00 00 00 00  |................|
        00000490  00 00 00 00 00 00 00 00  39 00 00 00 01 00 00 00  |........9.......|
        000004a0  30 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |0...............|
        000004b0  84 00 00 00 00 00 00 00  21 00 00 00 00 00 00 00  |........!.......|
        000004c0  00 00 00 00 00 00 00 00  01 00 00 00 00 00 00 00  |................|
        000004d0  01 00 00 00 00 00 00 00  42 00 00 00 01 00 00 00  |........B.......|
        000004e0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        000004f0  a5 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        00000500  00 00 00 00 00 00 00 00  01 00 00 00 00 00 00 00  |................|
        00000510  00 00 00 00 00 00 00 00  57 00 00 00 01 00 00 00  |........W.......|
        00000520  02 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        00000530  a8 00 00 00 00 00 00 00  58 00 00 00 00 00 00 00  |........X.......|
        00000540  00 00 00 00 00 00 00 00  08 00 00 00 00 00 00 00  |................|
        00000550  00 00 00 00 00 00 00 00  52 00 00 00 04 00 00 00  |........R.......|
        00000560  40 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |@...............|
        00000570  80 02 00 00 00 00 00 00  30 00 00 00 00 00 00 00  |........0.......|
        00000580  0a 00 00 00 08 00 00 00  08 00 00 00 00 00 00 00  |................|
        00000590  18 00 00 00 00 00 00 00  01 00 00 00 02 00 00 00  |................|
        000005a0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        000005b0  00 01 00 00 00 00 00 00  20 01 00 00 00 00 00 00  |........ .......|
        000005c0  0b 00 00 00 09 00 00 00  08 00 00 00 00 00 00 00  |................|
        000005d0  18 00 00 00 00 00 00 00  09 00 00 00 03 00 00 00  |................|
        000005e0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        000005f0  20 02 00 00 00 00 00 00  18 00 00 00 00 00 00 00  | ...............|
        00000600  00 00 00 00 00 00 00 00  01 00 00 00 00 00 00 00  |................|
        00000610  00 00 00 00 00 00 00 00  11 00 00 00 03 00 00 00  |................|
        00000620  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
        00000630  b0 02 00 00 00 00 00 00  61 00 00 00 00 00 00 00  |........a.......|
        00000640  00 00 00 00 00 00 00 00  01 00 00 00 00 00 00 00  |................|
        00000650  00 00 00 00 00 00 00 00                           |........|
        00000658

- Example output for `gcc -c`. The output may differ from the one produced with the `as` utility. The output is printed out with `xxd` utility which has very similar output as `hexdump`:

        $ gcc -c -o hello.o hello.cpp
        $ xxd hello.o

        00000000: 7f45 4c46 0201 0100 0000 0000 0000 0000  .ELF............
        00000010: 0100 3e00 0100 0000 0000 0000 0000 0000  ..>.............
        00000020: 0000 0000 0000 0000 2003 0000 0000 0000  ........ .......
        00000030: 0000 0000 4000 0000 0000 4000 0d00 0c00  ....@.....@.....
        00000040: 5548 89e5 f30f 1145 fcf3 0f10 4dfc f30f  UH.....E....M...
        00000050: 1005 0000 0000 f30f 58c1 f30f 1145 fc90  ........X....E..
        00000060: 5dc3 5548 89e5 8b05 0000 0000 660f 6ec0  ].UH........f.n.
        00000070: e800 0000 00b8 0000 0000 5dc3 6666 a63f  ..........].ff.?
        00000080: 0000 803f 0047 4343 3a20 2841 7263 6820  ...?.GCC: (Arch 
        00000090: 4c69 6e75 7820 392e 332e 302d 3129 2039  Linux 9.3.0-1) 9
        000000a0: 2e33 2e30 0000 0000 1400 0000 0000 0000  .3.0............
        000000b0: 017a 5200 0178 1001 1b0c 0708 9001 0000  .zR..x..........
        000000c0: 1c00 0000 1c00 0000 0000 0000 2200 0000  ............"...
        000000d0: 0041 0e10 8602 430d 065d 0c07 0800 0000  .A....C..]......
        000000e0: 1c00 0000 3c00 0000 0000 0000 1a00 0000  ....<...........
        000000f0: 0041 0e10 8602 430d 0655 0c07 0800 0000  .A....C..U......
        00000100: 0000 0000 0000 0000 0000 0000 0000 0000  ................
        00000110: 0000 0000 0000 0000 0100 0000 0400 f1ff  ................
        00000120: 0000 0000 0000 0000 0000 0000 0000 0000  ................
        00000130: 0000 0000 0300 0100 0000 0000 0000 0000  ................
        00000140: 0000 0000 0000 0000 0000 0000 0300 0300  ................
        00000150: 0000 0000 0000 0000 0000 0000 0000 0000  ................
        00000160: 0000 0000 0300 0400 0000 0000 0000 0000  ................
        00000170: 0000 0000 0000 0000 0000 0000 0300 0500  ................
        00000180: 0000 0000 0000 0000 0000 0000 0000 0000  ................
        00000190: 0000 0000 0300 0700 0000 0000 0000 0000  ................
        000001a0: 0000 0000 0000 0000 0000 0000 0300 0800  ................
        000001b0: 0000 0000 0000 0000 0000 0000 0000 0000  ................
        000001c0: 0000 0000 0300 0600 0000 0000 0000 0000  ................
        000001d0: 0000 0000 0000 0000 0b00 0000 1100 0300  ................
        000001e0: 0000 0000 0000 0000 0400 0000 0000 0000  ................
        000001f0: 0f00 0000 1200 0100 0000 0000 0000 0000  ................
        00000200: 2200 0000 0000 0000 1700 0000 1200 0100  "...............
        00000210: 2200 0000 0000 0000 1a00 0000 0000 0000  "...............
        00000220: 0068 656c 6c6f 2e63 7070 0071 7578 005f  .hello.cpp.qux._
        00000230: 5a33 666f 6f66 006d 6169 6e00 0000 0000  Z3foof.main.....
        00000240: 1200 0000 0000 0000 0200 0000 0500 0000  ................
        00000250: fcff ffff ffff ffff 2800 0000 0000 0000  ........(.......
        00000260: 0200 0000 0900 0000 fcff ffff ffff ffff  ................
        00000270: 3100 0000 0000 0000 0400 0000 0a00 0000  1...............
        00000280: fcff ffff ffff ffff 2000 0000 0000 0000  ........ .......
        00000290: 0200 0000 0200 0000 0000 0000 0000 0000  ................
        000002a0: 4000 0000 0000 0000 0200 0000 0200 0000  @...............
        000002b0: 2200 0000 0000 0000 002e 7379 6d74 6162  ".........symtab
        000002c0: 002e 7374 7274 6162 002e 7368 7374 7274  ..strtab..shstrt
        000002d0: 6162 002e 7265 6c61 2e74 6578 7400 2e64  ab..rela.text..d
        000002e0: 6174 6100 2e62 7373 002e 726f 6461 7461  ata..bss..rodata
        000002f0: 002e 636f 6d6d 656e 7400 2e6e 6f74 652e  ..comment..note.
        00000300: 474e 552d 7374 6163 6b00 2e72 656c 612e  GNU-stack..rela.
        00000310: 6568 5f66 7261 6d65 0000 0000 0000 0000  eh_frame........
        00000320: 0000 0000 0000 0000 0000 0000 0000 0000  ................
        00000330: 0000 0000 0000 0000 0000 0000 0000 0000  ................
        00000340: 0000 0000 0000 0000 0000 0000 0000 0000  ................
        00000350: 0000 0000 0000 0000 0000 0000 0000 0000  ................
        00000360: 2000 0000 0100 0000 0600 0000 0000 0000   ...............
        00000370: 0000 0000 0000 0000 4000 0000 0000 0000  ........@.......
        00000380: 3c00 0000 0000 0000 0000 0000 0000 0000  <...............
        00000390: 0100 0000 0000 0000 0000 0000 0000 0000  ................
        000003a0: 1b00 0000 0400 0000 4000 0000 0000 0000  ........@.......
        000003b0: 0000 0000 0000 0000 4002 0000 0000 0000  ........@.......
        000003c0: 4800 0000 0000 0000 0a00 0000 0100 0000  H...............
        000003d0: 0800 0000 0000 0000 1800 0000 0000 0000  ................
        000003e0: 2600 0000 0100 0000 0300 0000 0000 0000  &...............
        000003f0: 0000 0000 0000 0000 7c00 0000 0000 0000  ........|.......
        00000400: 0400 0000 0000 0000 0000 0000 0000 0000  ................
        00000410: 0400 0000 0000 0000 0000 0000 0000 0000  ................
        00000420: 2c00 0000 0800 0000 0300 0000 0000 0000  ,...............
        00000430: 0000 0000 0000 0000 8000 0000 0000 0000  ................
        00000440: 0000 0000 0000 0000 0000 0000 0000 0000  ................
        00000450: 0100 0000 0000 0000 0000 0000 0000 0000  ................
        00000460: 3100 0000 0100 0000 0200 0000 0000 0000  1...............
        00000470: 0000 0000 0000 0000 8000 0000 0000 0000  ................
        00000480: 0400 0000 0000 0000 0000 0000 0000 0000  ................
        00000490: 0400 0000 0000 0000 0000 0000 0000 0000  ................
        000004a0: 3900 0000 0100 0000 3000 0000 0000 0000  9.......0.......
        000004b0: 0000 0000 0000 0000 8400 0000 0000 0000  ................
        000004c0: 2100 0000 0000 0000 0000 0000 0000 0000  !...............
        000004d0: 0100 0000 0000 0000 0100 0000 0000 0000  ................
        000004e0: 4200 0000 0100 0000 0000 0000 0000 0000  B...............
        000004f0: 0000 0000 0000 0000 a500 0000 0000 0000  ................
        00000500: 0000 0000 0000 0000 0000 0000 0000 0000  ................
        00000510: 0100 0000 0000 0000 0000 0000 0000 0000  ................
        00000520: 5700 0000 0100 0000 0200 0000 0000 0000  W...............
        00000530: 0000 0000 0000 0000 a800 0000 0000 0000  ................
        00000540: 5800 0000 0000 0000 0000 0000 0000 0000  X...............
        00000550: 0800 0000 0000 0000 0000 0000 0000 0000  ................
        00000560: 5200 0000 0400 0000 4000 0000 0000 0000  R.......@.......
        00000570: 0000 0000 0000 0000 8802 0000 0000 0000  ................
        00000580: 3000 0000 0000 0000 0a00 0000 0800 0000  0...............
        00000590: 0800 0000 0000 0000 1800 0000 0000 0000  ................
        000005a0: 0100 0000 0200 0000 0000 0000 0000 0000  ................
        000005b0: 0000 0000 0000 0000 0001 0000 0000 0000  ................
        000005c0: 2001 0000 0000 0000 0b00 0000 0900 0000   ...............
        000005d0: 0800 0000 0000 0000 1800 0000 0000 0000  ................
        000005e0: 0900 0000 0300 0000 0000 0000 0000 0000  ................
        000005f0: 0000 0000 0000 0000 2002 0000 0000 0000  ........ .......
        00000600: 1c00 0000 0000 0000 0000 0000 0000 0000  ................
        00000610: 0100 0000 0000 0000 0000 0000 0000 0000  ................
        00000620: 1100 0000 0300 0000 0000 0000 0000 0000  ................
        00000630: 0000 0000 0000 0000 b802 0000 0000 0000  ................
        00000640: 6100 0000 0000 0000 0000 0000 0000 0000  a...............
        00000650: 0100 0000 0000 0000 0000 0000 0000 0000  ................

- Commands for analyzing final executable files

        $ nm --demangle OBJECT_FILE_OR_EXECUTABLE
        $ objdump --source --reloc OBJECT_FILE

    `objdump` options:
    - `-r` / `--reloc`

        Print the relocation entries of the file.  If used with -d or -D, the relocations are printed
           interspersed with the disassembly.
    - `-S` / `--source`

        Display source code intermixed with disassembly, if possible.  Implies -d.

    These commands can show location of global, static and const variables

## Linking

- Input: object/machine/binary/byte/ELF code
    - human unreadable code for each translation unit

- Commands:

        ld -o hello hello.o -lLibrary1 -lLibrary2 ... -lLibraryN

    or [this produces an executable more reliably - the executable can actually be executed without segmentaton error]

        gcc -o hello hello.cpp

- Phase 9

- Output: final executable
    - machine/binary/byte code with resolved dependencies to external libraries
    - this code is executed directly on CPU

- Example output for linked executable `hello` with command `ld -o hello hello.o`:

        ld: warning: cannot find entry symbol _start; defaulting to 0000000000401000

    Ooops :/ sooo this works in the theory, but not in the real world. I see.

        $ ./hello

        Segmentation fault (core dumped)

- Commands for analyzing final executable files

        $ size executable_name
        $ valgrind executable_name
        $ gdb executable_name
        $ file executable_name

## Summary

### Step-by-step execution

1. Preprocessing

    Transform source files into translation units: expand macros and other preprocessor directive. Translation units are human readable.

        cpp source.cpp source.i

    Output is a translation unit with resolved preprocessor directives, i.e. pure C/C++ source code.

1. Compilation

    Transform translation units with C/C++ code into files with corresponding assembly code. Assembly code is human readable.

        gcc -S source.i # generates source.s

1. Assembling

    Transform files with assembly code into files with binary code. Binary code isn't intended to be read by humans, but for CPUs.

        as -o source.o source.s

1. Linking

    Transform binary files into binary files with resolved external dependencies, e.g. libraries.

        ld -o executable source.o

At the end of this process I couldn't execute the executable file. It was either incompatible or crashed with segfault at runtime.

### Makefile-like steps [PREFERRED]

1. Preprocessing + Compilation + Assembling

        gcc -o source.o source.cpp

1. Linking
    
        gcc -o executable source.o

At the end of this process I got an executable file which run correctly.

### Simple compilation [PREFERRED]

One of the simplest way to build an executable from a simple project:

    gcc -o hello hello.cpp

Let's observe the compilation process more closely with a verbose output

    gcc -v -o hello hello.cpp

Here's an example output:

    Using built-in specs.
    COLLECT_GCC=gcc
    COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/lto-wrapper
    Target: x86_64-pc-linux-gnu
    Configured with: /build/gcc/src/gcc/configure --prefix=/usr --libdir=/usr/lib --libexecdir=/usr/lib --mandir=/usr/share/man --infodir=/usr/share/info --with-pkgversion='Arch Linux 9.3.0-1' --with-bugurl=https://bugs.archlinux.org/ --enable-languages=c,c++,ada,fortran,go,lto,objc,obj-c++,d --enable-shared --enable-threads=posix --with-system-zlib --with-isl --enable-__cxa_atexit --disable-libunwind-exceptions --enable-clocale=gnu --disable-libstdcxx-pch --disable-libssp --enable-gnu-unique-object --enable-linker-build-id --enable-lto --enable-plugin --enable-install-libiberty --with-linker-hash-style=gnu --enable-gnu-indirect-function --enable-multilib --disable-werror --enable-checking=release --enable-default-pie --enable-default-ssp --enable-cet=auto gdc_include_dir=/usr/include/dlang/gdc
    Thread model: posix
    gcc version 9.3.0 (Arch Linux 9.3.0-1) 
    COLLECT_GCC_OPTIONS='-v' '-o' 'hello' '-mtune=generic' '-march=x86-64'
    /usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/cc1plus -quiet -v -D_GNU_SOURCE hello.cpp -quiet -dumpbase hello.cpp -mtune=generic -march=x86-64 -auxbase hello -version -o /tmp/ccCdow8q.s
    GNU C++14 (Arch Linux 9.3.0-1) version 9.3.0 (x86_64-pc-linux-gnu)
        compiled by GNU C version 9.3.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.21-GMP

    GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
    ignoring nonexistent directory "/usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/../../../../x86_64-pc-linux-gnu/include"
    #include "..." search starts here:
    #include <...> search starts here:
    /usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/../../../../include/c++/9.3.0
    /usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/../../../../include/c++/9.3.0/x86_64-pc-linux-gnu
    /usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/../../../../include/c++/9.3.0/backward
    /usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/include
    /usr/local/include
    /usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/include-fixed
    /usr/include
    End of search list.
    GNU C++14 (Arch Linux 9.3.0-1) version 9.3.0 (x86_64-pc-linux-gnu)
        compiled by GNU C version 9.3.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.21-GMP

    GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
    Compiler executable checksum: 814040b5981cd30c081565ed9d15a61c
    COLLECT_GCC_OPTIONS='-v' '-o' 'hello' '-mtune=generic' '-march=x86-64'
    as -v --64 -o /tmp/ccMa3hAq.o /tmp/ccCdow8q.s
    GNU assembler version 2.34 (x86_64-pc-linux-gnu) using BFD version (GNU Binutils) 2.34
    COMPILER_PATH=/usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/:/usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/:/usr/lib/gcc/x86_64-pc-linux-gnu/:/usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/:/usr/lib/gcc/x86_64-pc-linux-gnu/
    LIBRARY_PATH=/usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/:/usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/../../../../lib/:/lib/../lib/:/usr/lib/../lib/:/usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/../../../:/lib/:/usr/lib/
    COLLECT_GCC_OPTIONS='-v' '-o' 'hello' '-mtune=generic' '-march=x86-64'
    /usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/collect2 -plugin /usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/liblto_plugin.so -plugin-opt=/usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/lto-wrapper -plugin-opt=-fresolution=/tmp/cciGMpLt.res -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lgcc_s -plugin-opt=-pass-through=-lc -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lgcc_s --build-id --eh-frame-hdr --hash-style=gnu -m elf_x86_64 -dynamic-linker /lib64/ld-linux-x86-64.so.2 -pie -o hello /usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/../../../../lib/Scrt1.o /usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/../../../../lib/crti.o /usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/crtbeginS.o -L/usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0 -L/usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/../../../../lib -L/lib/../lib -L/usr/lib/../lib -L/usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/../../.. /tmp/ccMa3hAq.o -lgcc --push-state --as-needed -lgcc_s --pop-state -lc -lgcc --push-state --as-needed -lgcc_s --pop-state /usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/crtendS.o /usr/lib/gcc/x86_64-pc-linux-gnu/9.3.0/../../../../lib/crtn.o
    COLLECT_GCC_OPTIONS='-v' '-o' 'hello' '-mtune=generic' '-march=x86-64'

We see that the linker `ld`, or more specifically `/lib64/ld-linux-x86-64.so.2` is being executed with more parameters than in the simplified step-by-step introduction at the beginning of this document. Therefore, I suspect, that the build failed to link and/or execute because of these flags passed to the linker.

#### Sources

- https://stackoverflow.com/questions/6264249/how-does-the-compilation-linking-process-work/51819170#51819170
- https://gcc.gnu.org/onlinedocs/cpp/Invocation.html
- https://stackoverflow.com/questions/6264249/how-does-the-compilation-linking-process-work
- https://en.cppreference.com/w/cpp/language/translation_phases
- https://en.cppreference.com/w/c/language/translation_phases
- https://stackoverflow.com/questions/466790/assembly-code-vs-machine-code-vs-object-code/466811#466811
- https://en.wikipedia.org/wiki/Translation_unit_(programming) - mainly the first sentence in the _Context_ part
- https://en.wikipedia.org/wiki/Assembly_language
- https://de.wikipedia.org/wiki/Executable_and_Linking_Format
- https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html
- https://www.linuxquestions.org/questions/programming-9/ld-warning-cannot-find-entry-symbol-_start-833944/
- https://superuser.com/questions/494245/what-does-an-asterisk-mean-in-hexdump-output/494613#494613
- https://unix.stackexchange.com/questions/282215/how-to-view-a-binary-file
