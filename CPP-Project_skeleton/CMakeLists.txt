cmake_minimum_required (VERSION 3.0)

set(PROJECT_NAME "${PROJECT_NAME}")
message("Project name: ${PROJECT_NAME}")
project (${PROJECT_NAME})

# enable debugging for faster localization deeper inspection of the program's runtime
# and maximize stability and predictability of the program
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
    -ggdb \
    -Wall -Werror -Wextra -Wpedantic \
    -Wunused-parameter -Weffc++ -Wsign-conversion -Wconversion -Wmissing-declarations \
    -fstrict-aliasing -Wstrict-aliasing \
    -fwrapv")

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

file(GLOB_RECURSE source_files
    "src/*.h"
    "src/*.cpp"
)

add_executable(${PROJECT_NAME} src/client/main.cpp ${source_files})
