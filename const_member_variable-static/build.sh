#!/bin/sh

clear
rm const_member_variable-static > /dev/null 2>&1
g++ -o const_member_variable-static main.cpp 

echo "==========================================="
echo "             EXECUTABLE OUTPUT" 
echo "==========================================="

./const_member_variable-static

echo "==========================================="
echo "             MEMCHECK (memček)" 
echo "==========================================="

valgrind --show-error-list=yes ./const_member_variable-static

