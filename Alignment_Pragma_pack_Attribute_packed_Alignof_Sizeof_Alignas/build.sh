#!/bin/sh

clear

rm -f alignment_pragma_pack_attribute_packed_alignof_sizeof
gcc -o alignment_pragma_pack_attribute_packed_alignof_sizeof main.cpp
clang -E main.cpp > main_preprocessed.cpp
clang -cc1 -fdump-record-layouts main_preprocessed.cpp
./alignment_pragma_pack_attribute_packed_alignof_sizeof


