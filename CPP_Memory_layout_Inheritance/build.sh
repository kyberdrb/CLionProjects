#/bin/bash

clang -o inheritance inheritance.cpp
clang -cc1 -fdump-record-layouts inheritance.cpp

echo
echo '==============================================================='

clang -o inheritance_with_virtual_function inheritance_with_virtual_function.cpp
clang -cc1 -fdump-record-layouts inheritance_with_virtual_function.cpp
