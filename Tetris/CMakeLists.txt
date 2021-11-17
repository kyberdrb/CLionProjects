cmake_minimum_required(VERSION 3.20)
project(Tetris)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tetris main.cpp src/Game.cpp src/Game.h src/ConstructionSite.cpp src/ConstructionSite.h src/Brick.cpp src/Brick.h)
