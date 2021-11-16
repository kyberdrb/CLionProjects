cmake_minimum_required(VERSION 3.15)
project(UndefinedBehavior)

SET (CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_STANDARD 14)

add_executable(UndefinedBehavior main.cpp)