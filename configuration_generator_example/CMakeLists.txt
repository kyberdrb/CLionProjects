cmake_minimum_required(VERSION 3.25)
project(did_generator_didar)

set(CMAKE_CXX_STANDARD 17)

add_executable(did_generator_didar main.cpp DID.cpp DID.h)
