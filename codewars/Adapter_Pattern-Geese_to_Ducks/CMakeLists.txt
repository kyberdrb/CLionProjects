cmake_minimum_required(VERSION 3.14)
project(Adapter_Pattern_Geese_to_Ducks)

set(CMAKE_CXX_STANDARD 14)

add_executable(Adapter_Pattern_Geese_to_Ducks main.cpp IDuck.h Goose.h GooseToIDuckAdapter.h Goose.cpp)