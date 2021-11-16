#/bin/bash

g++ -E file1.cpp > file1_preprocessed.cpp
g++ -E file2.cpp > file2_preprocessed.cpp
g++ -E source.cpp > source_preprocessed.cpp
g++ -E main.cpp > main_preprocessed.cpp
