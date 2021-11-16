#!/bin/sh

clear

rm strict_aliasing_rule_ex_2

# sometimes you just need to experiment with the level of "-Wstrict-aliasing" :)
gcc -fstrict-aliasing -Wstrict-aliasing=1 -o strict_aliasing_rule_ex_2 main.cpp
./strict_aliasing_rule_ex_2

