cmake_minimum_required(VERSION 3.28)
project(conditional_inclusion_with_preprocessor_directives)

set(CMAKE_CXX_STANDARD 17)

add_executable(conditional_inclusion_with_preprocessor_directives main.cpp)

#if (OUTSIDE_CMAKE_VARIABLE)
IF( DEFINED OUTSIDE_CMAKE_VARIABLE_INTO_CMAKE_FROM_COMMAND_LINE )
    MESSAGE(STATUS "CMake variable with name 'OUTSIDE_CMAKE_VARIABLE_INTO_CMAKE_FROM_COMMAND_LINE' is defined and passed from command line to compiler, i. e. to source code, with value '${OUTSIDE_CMAKE_VARIABLE_INTO_CMAKE_FROM_COMMAND_LINE}'")
    target_compile_definitions(conditional_inclusion_with_preprocessor_directives PRIVATE OUTSIDE_CMAKE_VARIABLE_PASSED_TO_SOURCE_CODE_FROM_CMAKE=${OUTSIDE_CMAKE_VARIABLE_INTO_CMAKE_FROM_COMMAND_LINE})
endif ()

# Disable 'assert' statements evaluation with 'NDEBUG' macro
target_compile_definitions(conditional_inclusion_with_preprocessor_directives PRIVATE NDEBUG)
