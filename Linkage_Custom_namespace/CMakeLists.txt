cmake_minimum_required(VERSION 3.15)
project(Linkage_Custom_namespace)

set(CMAKE_CXX_STANDARD 14)

add_executable(Linkage_Custom_namespace main.cpp file1.cpp file1.h file2.cpp file2.h header.h)