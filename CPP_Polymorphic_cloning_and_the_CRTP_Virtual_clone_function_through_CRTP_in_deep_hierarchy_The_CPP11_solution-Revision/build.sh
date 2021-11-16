#!/bin/sh

clear

#POSIX or not, this is the REEEAL PAAATH!
SCRIPT_FULL_PATH=$(realpath "$0")
PROJECT_FULL_PATH=$(dirname "$SCRIPT_FULL_PATH")
EXECUTABLE_FULL_PATH="${PROJECT_FULL_PATH}/build"

mkdir -p "$EXECUTABLE_FULL_PATH"

EXECUTABLE_NAME=$(basename "$PROJECT_FULL_PATH" | tr -s '[:upper:]' '[:lower:]')
rm "${EXECUTABLE_FULL_PATH}/${EXECUTABLE_NAME}"

g++ -ggdb -o "${EXECUTABLE_FULL_PATH}/${EXECUTABLE_NAME}" "${PROJECT_FULL_PATH}/main.cpp"

echo "==========================================="
echo "             EXECUTABLE OUTPUT"
echo "==========================================="

"${EXECUTABLE_FULL_PATH}/${EXECUTABLE_NAME}"

echo "==========================================="
echo "             MEMCHECK (mêmčëk)"
echo "==========================================="

valgrind --show-error-list=yes --leak-check=full "${EXECUTABLE_FULL_PATH}/${EXECUTABLE_NAME}"
