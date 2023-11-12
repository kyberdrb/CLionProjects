cmake_minimum_required(VERSION 3.26)
project(Class_adapter_without_reference_wrapper_without_polymorphism_with_multiple_inheritance-compile_time_CPP_14)

set(CMAKE_CXX_STANDARD 17)

add_executable(Class_adapter_without_reference_wrapper_without_polymorphism_with_multiple_inheritance-compile_time_CPP_14 main.cpp
        RoundHole.cpp
        RoundHole.h
        RoundPeg.cpp
        RoundPeg.h
        SquarePeg.cpp
        SquarePeg.h
        SquareToRoundPegAdapter.cpp
        SquareToRoundPegAdapter.h)
