cmake_minimum_required(VERSION 3.15)
project(UniquePtrCustomDeletersMoreExpressive)

set(CMAKE_CXX_STANDARD 14)
# -Wall flag producess error message when a variable is not used
set(CMAKE_CXX_FLAGS "-Werror -Wall -Wextra -fwrapv -fno-strict-aliasing -Wno-unused-parameter")

add_executable(UniquePtrCustomDeletersMoreExpressive main.cpp Computer.h NamespacedComputer.h ProblematicUniquePtrDeleterSigns.h MoreExpressiveUniquePtrDeleter.h)