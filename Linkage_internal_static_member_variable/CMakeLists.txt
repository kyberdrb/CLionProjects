cmake_minimum_required(VERSION 3.16)
project(Linkage_internal_static_member_variable)

set(CMAKE_CXX_STANDARD 14)

add_executable(Linkage_internal_static_member_variable main.cpp file1.cpp file1.h file2.cpp file2.h header.h source.cpp)