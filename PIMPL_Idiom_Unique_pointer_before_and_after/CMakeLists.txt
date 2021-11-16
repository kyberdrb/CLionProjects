cmake_minimum_required(VERSION 3.15)
project(PIMPL_Idiom_Unique_pointer_before_and_after)

set(CMAKE_CXX_STANDARD 14)

add_executable(PIMPL_Idiom_Unique_pointer_before_and_after main.cpp OldEngine.h OldFridge.h UniquePtrPIMPL_Idiom/Fridge.cpp UniquePtrPIMPL_Idiom/Fridge.h UniquePtrPIMPL_Idiom/Engine.h)