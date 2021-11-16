cmake_minimum_required(VERSION 3.14)
project(OperatorOverloading)

set(CMAKE_CXX_STANDARD 11)

add_executable(OperatorOverloading main.cpp AssignmnentOperatorAndCopyConstructor.cpp AssignmnentOperatorAndCopyConstructor.h Test.cpp Test.h LeftBitShiftOperator.cpp LeftBitShiftOperator.h ComplexNumber.cpp ComplexNumber.h ComplexNumberExercise.cpp ComplexNumberExercise.h)