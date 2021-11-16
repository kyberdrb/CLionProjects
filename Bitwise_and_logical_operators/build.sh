#!/bin/sh

clear

rm -f bitwise_and_logical_operators
gcc -o bitwise_and_logical_operators main.cpp
gcc -S -fverbose-asm -g main.cpp -o main.disassembled

echo
echo "========================================================="
echo

cat main.disassembled | grep main.cpp:5 -A32

echo
echo "========================================================="
echo

cat main.disassembled | grep main.cpp:5 -A14 && \
echo && \
echo "\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/" && \
echo "                    snip                    " && \
echo "\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/" && \
echo && \
cat main.disassembled | grep main.cpp:16 -A6 && \
echo && \
echo "ˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇ" && \
echo "                  dead code                 " && \
echo "if the left operand of the '&&' operator    " && \
echo "('cmp' instruction), is false the evaluation" && \
echo "of the right operand is skipped" && \
echo "- - - - - - - - - - - - - - - - - - - - - - " && \
echo && \
cat main.disassembled | grep "loc 1 17 23" -B1 -A11 && \
echo && \
echo "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" && \
echo && \
cat main.disassembled | grep ".L4:" -A7

echo
echo "========================================================="
echo

./bitwise_and_logical_operators

echo

