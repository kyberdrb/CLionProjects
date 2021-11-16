cmake_minimum_required(VERSION 3.15)
project(PIMPL_Idiom_Raw_pointer_before_and_after)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Werror -Wall -Wextra -fwrapv -fno-strict-aliasing -Wno-unused-parameter -Wpedantic")

add_executable(PIMPL_Idiom_Raw_pointer_before_and_after main.cpp Fridge.h Engine.h PIMPL_Fridge/AnotherFridge.cpp PIMPL_Fridge/AnotherFridge.h PIMPL_Fridge/AnotherEngine.h)