cmake_minimum_required(VERSION 3.26)
project(vector_find)

set(CMAKE_CXX_STANDARD 17)

add_executable(vector_find main.cpp
        Device.cpp
        Device.h
        Item.h
        Phone.h
        Laptop.h)
