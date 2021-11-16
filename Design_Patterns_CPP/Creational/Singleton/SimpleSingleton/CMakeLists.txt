cmake_minimum_required(VERSION 3.14)
project(SimpleSingleton)

set(CMAKE_CXX_STANDARD 17)

add_executable(SimpleSingleton main.cpp simpleSingletonDatabase/SingletonDatabase.cpp simpleSingletonDatabase/SingletonDatabase.h)