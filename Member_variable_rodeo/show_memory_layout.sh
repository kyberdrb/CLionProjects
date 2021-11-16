#/bin/bash

clear
gcc -E main.cpp > main_preprocessed.cpp
clang -cc1 -fdump-record-layouts main_preprocessed.cpp
