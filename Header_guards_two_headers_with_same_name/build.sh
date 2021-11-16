#/bin/sh

clear

g++ -E dirA/header.h > dirA/header_preprocessed.h
g++ -E dirB/header.h > dirB/header_preprocessed.h

cat dirA/header_preprocessed.h
echo
echo "=================================================="
echo
cat dirB/header_preprocessed.h
echo
echo "=================================================="
echo

rm header_guards_headers_with_same_name

g++ -o header_guards_headers_with_same_name main.cpp

ls -l header_guards_headers_with_same_name
echo

