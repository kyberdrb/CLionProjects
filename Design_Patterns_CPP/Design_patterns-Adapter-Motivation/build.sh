#!/bin/sh

clear

SCRIPT_FULL_PATH=$(realpath "$0")
PROJECT_FULL_PATH=$(dirname "$SCRIPT_FULL_PATH")

# remove core dumps from Valgrind
rm $PROJECT_FULL_PATH/vgcore.*

BUILD_DIR_FULL_PATH="${PROJECT_FULL_PATH}/build"

rm -rf "$BUILD_DIR_FULL_PATH"
mkdir -p "$BUILD_DIR_FULL_PATH"

EXECUTABLE_NAME=$(basename "$PROJECT_FULL_PATH" | tr -s '[:upper:]' '[:lower:]')

# With g++
#g++ -ggdb -o "${BUILD_DIR_FULL_PATH}/${EXECUTABLE_NAME}" "${PROJECT_FULL_PATH}/main.cpp" "${PROJECT_FULL_PATH}/src/Employee.cpp"

# With CMake
cmake -S "$PROJECT_FULL_PATH" -B "$BUILD_DIR_FULL_PATH"    # 'Generate a Project Buildsystem', i.e. initialize CMake project; this generates CMakeCache.txt file which is necessary for the 'cmake --build' command, otherwise the cmake compilation will fail
cmake --build "${BUILD_DIR_FULL_PATH}" --target ${EXECUTABLE_NAME} # 'Build a Project'

echo "==========================================="
echo "             EXECUTABLE OUTPUT"
echo "==========================================="

"${BUILD_DIR_FULL_PATH}/${EXECUTABLE_NAME}"

echo "==========================================="
echo "             MEMCHECK (mêmčëk)"
echo "==========================================="

valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all "${BUILD_DIR_FULL_PATH}/${EXECUTABLE_NAME}"
