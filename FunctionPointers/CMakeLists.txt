cmake_minimum_required(VERSION 3.14)
project(PassingFunctionToFunction)

set(CMAKE_CXX_STANDARD 11)

add_executable(PassingFunctionToFunction main.cpp Parent.h Child.h AbstractClassesPureVirtualFunctions/Animal.h AbstractClassesPureVirtualFunctions/Dog.h AbstractClassesPureVirtualFunctions/Labrador.h Functors/Test.h Functors/MatchTest.h)