cmake_minimum_required(VERSION 3.16)
project(Linkage_internal_multiple_static_functions_with_same_name)

set(CMAKE_CXX_STANDARD 14)

add_executable(Linkage_internal_multiple_static_functions_with_same_name main.cpp file1.cpp file1.h file2.cpp file2.h)