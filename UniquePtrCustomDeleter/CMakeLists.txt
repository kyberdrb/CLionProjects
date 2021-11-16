cmake_minimum_required(VERSION 3.15)
project(UniquePtrCustomDeleter)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Werror -Wall -Wextra -fwrapv -fno-strict-aliasing -Wno-unused-parameter")

add_executable(UniquePtrCustomDeleter main.cpp)