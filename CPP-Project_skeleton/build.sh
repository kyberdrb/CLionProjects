#!/bin/sh

clear

SCRIPT_FULL_PATH=$(realpath "$0")
PROJECT_FULL_PATH=$(dirname "$SCRIPT_FULL_PATH")

# remove core dumps from Valgrind
rm $PROJECT_FULL_PATH/vgcore.*

BUILD_DIR_FULL_PATH="${PROJECT_FULL_PATH}/build"

rm -rf "$BUILD_DIR_FULL_PATH"
mkdir -p "$BUILD_DIR_FULL_PATH"

EXECUTABLE_NAME=$(basename "$PROJECT_FULL_PATH")

# With g++
#g++ -ggdb -o "${BUILD_DIR_FULL_PATH}/${EXECUTABLE_NAME}" "${PROJECT_FULL_PATH}/main.cpp" "${PROJECT_FULL_PATH}/src/Employee.cpp"

cmake -DPROJECT_NAME=${EXECUTABLE_NAME} -S "$PROJECT_FULL_PATH" -B "$BUILD_DIR_FULL_PATH" # 'Generate a Project Buildsystem', i.e. initialize CMake project; this generates CMakeCache.txt file which is necessary for the 'cmake --build' command, otherwise the cmake compilation will fail
                                                                                          # - also the name of the executable in this script is passed to the cmake as the name of the project which in turn produces the executable with the same name, reducing the need for manually editing the CMakeLists.txt and automatizing and generalizing the building process for any cmake project
# CMake with clang-tidy - static analysis for inspiration and safety
#cmake -DPROJECT_NAME=${EXECUTABLE_NAME} "-DCMAKE_CXX_CLANG_TIDY=/usr/bin/clang-tidy;-checks=*;-header-filter=.*" -S "$PROJECT_FULL_PATH" -B "$BUILD_DIR_FULL_PATH"

cmake --build "${BUILD_DIR_FULL_PATH}" --target ${EXECUTABLE_NAME} # 'Build a Project'

echo "==========================================="
echo "             EXECUTABLE OUTPUT"
echo "==========================================="

"${BUILD_DIR_FULL_PATH}/${EXECUTABLE_NAME}"

echo "==========================================="
echo "             MEMCHECK (mêmčëk)"
echo "==========================================="

valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all "${BUILD_DIR_FULL_PATH}/${EXECUTABLE_NAME}"
