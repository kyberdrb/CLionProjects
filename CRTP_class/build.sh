#!/bin/sh

clear
rm crtp_class
g++ -o crtp_class main.cpp 

./crtp_class

echo "==========================================="
echo "             MEMCHECK (memček)" 
echo "==========================================="

valgrind --show-error-list=yes ./crtp_class

