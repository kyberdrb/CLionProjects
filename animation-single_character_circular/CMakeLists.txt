cmake_minimum_required(VERSION 3.26)
project(animation_single_character_circular)

set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(animation_single_character_circular main.cpp AnimationInNCurses.cpp AnimationInNCurses.h)

target_link_libraries(animation_single_character_circular ${CURSES_LIBRARIES})
