cmake_minimum_required(VERSION 3.28)
project(conditional_inclusion_with_preprocessor_directives)

set(CMAKE_CXX_STANDARD 17)

add_executable(conditional_inclusion_with_preprocessor_directives main.cpp)

#if (OUTSIDE_CMAKE_VARIABLE)
IF( DEFINED OUTSIDE_CMAKE_VARIABLE )
    MESSAGE(STATUS "variable 'OUTSIDE_CMAKE_VARIABLE' is defined with value ${OUTSIDE_CMAKE_VARIABLE}")
    target_compile_definitions(conditional_inclusion_with_preprocessor_directives PRIVATE OUTSIDE_CMAKE_VARIABLE)
endif ()
