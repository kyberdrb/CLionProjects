#!/bin/sh

clear
rm const_member_variable-static_global
g++ -o const_member_variable-static_global main.cpp 

echo "==========================================="
echo "             EXECUTABLE OUTPUT" 
echo "==========================================="

./const_member_variable-static_global

echo "==========================================="
echo "             MEMCHECK (memček)" 
echo "==========================================="

valgrind --show-error-list=yes ./const_member_variable-static_global

