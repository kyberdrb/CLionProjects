cmake_minimum_required(VERSION 3.14)
project(Singleton_Shared_Ptr)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -lpthread)

add_executable(Singleton_Shared_Ptr main.cpp Singleton.cpp Singleton.h)