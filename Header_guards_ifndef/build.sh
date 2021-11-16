#/bin/sh

clear

g++ -E header1.h > header1_preprocessed.h
g++ -E header2.h > header2_preprocessed.h
g++ -E main.cpp > main_preprocessed.cpp

cat header1_preprocessed.h
echo
echo "=================================================="
echo
cat header2_preprocessed.h
echo
echo "=================================================="
echo
cat main_preprocessed.cpp
echo
echo "=================================================="
echo

rm header_guards_ifndef

g++ -o header_guards_ifndef main.cpp

ls -l header_guards_ifndef
echo
