#/bin/sh

g++ -E grandparent.h > grandparent_preprocessed.h
g++ -E parent.h > parent_preprocessed.h
g++ -E child.cpp > child_preprocessed.cpp

cat grandparent_preprocessed.h
echo
echo "=================================================="
echo
cat parent_preprocessed.h
echo
echo "=================================================="
echo
cat child_preprocessed.cpp
echo
echo "=================================================="
echo

rm header_guards_without_pragma_once

g++ -o header_guards_without_pragma_once child.cpp

ls -l header_guards_without_pragma_once
echo
