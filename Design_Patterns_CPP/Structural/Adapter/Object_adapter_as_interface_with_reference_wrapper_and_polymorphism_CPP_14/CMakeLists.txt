cmake_minimum_required(VERSION 3.26)
project(Object_adapter_as_interface_with_reference_wrapper_and_polymorphism_CPP_14)

set(CMAKE_CXX_STANDARD 17)

add_executable(Object_adapter_as_interface_with_reference_wrapper_and_polymorphism_CPP_14 main.cpp
        RoundHole.cpp
        RoundHole.h
        RoundPeg.cpp
        RoundPeg.h
        SquarePeg.cpp
        SquarePeg.h
        SquareToRoundPegAdapter.cpp
        SquareToRoundPegAdapter.h
        RoundCompatible.h)
