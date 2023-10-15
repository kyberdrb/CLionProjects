cmake_minimum_required (VERSION 3.0)

set(PROJECT_NAME "design_paterns-adapter-implemented_as_object_adapter")
project (${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb")

file(GLOB_RECURSE source_files
    "src/*.h"
    "src/*.cpp"
)

add_executable(${PROJECT_NAME} main.cpp ${source_files})
