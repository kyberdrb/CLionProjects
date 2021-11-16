#/bin/sh

clear

g++ -E file.cpp > file_preprocessed.cpp
g++ -E main.cpp > main_preprocessed.cpp

cat file_preprocessed.cpp
echo
echo "=================================================="
echo
cat main_preprocessed.cpp
echo
echo "=================================================="
echo

rm header_guards_multiple_includes_of_same_header

g++ -o header_guards_multiple_includes_of_same_header main.cpp

ls -l header_guards_multiple_includes_of_same_header
echo

