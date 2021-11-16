#/bin/bash

gcc -o invoke_linker_error a.cpp b.cpp

TRANSLATION_UNIT_A=a_preprocessed.cpp
TRANSLATION_UNIT_B=b_preprocessed.cpp

clear

g++ -E a.cpp > $TRANSLATION_UNIT_A
g++ -E b.cpp > $TRANSLATION_UNIT_B

echo
echo '==============================================================='
echo 'Compiler output'
echo 'ˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇ'
echo

g++ a.cpp b.cpp

echo
echo '==============================================================='
echo 'Header file: file.hpp'
echo 'ˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇ'
echo

cat file.h

echo
echo
echo '==============================================================='
echo 'Translation unit from a.cpp: a_preprocessed.cpp'
echo 'ˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇ'
echo

cat a_preprocessed.cpp

echo
echo
echo '==============================================================='
echo 'Translation unit from b.cpp: b_preprocessed.cpp'
echo 'ˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇˇ'
echo

cat b_preprocessed.cpp
