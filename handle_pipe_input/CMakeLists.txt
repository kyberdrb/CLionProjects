cmake_minimum_required(VERSION 3.29)
project(handle_pipe_input)

message("Project name: ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
    -ggdb \
    -Wall -Werror -Wextra -Wpedantic \
    -Wunused-parameter -Weffc++ -Wsign-conversion -Wconversion -Wmissing-declarations \
    -fstrict-aliasing -Wstrict-aliasing \
    -fprofile-arcs -ftest-coverage \
    -fwrapv")

message(STATUS "CXXFLAGS: ${CMAKE_CXX_FLAGS}")

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

add_executable(handle_pipe_input main.cpp
        TerminalHelper.cpp
        TerminalHelper.h)

target_compile_definitions(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>:_DEBUG>
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Release>:NDEBUG>
)
