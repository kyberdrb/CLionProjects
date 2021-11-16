#/bin/sh

g++ -E header1.h > header1_preprocessed.h
g++ -E header2.h > header2_preprocessed.h

cat header1_preprocessed.h
echo
echo "=================================================="
echo
cat header2_preprocessed.h
echo
echo "=================================================="
echo

rm header_guards_omitted
g++ -o header_guards_omitted main.cpp
