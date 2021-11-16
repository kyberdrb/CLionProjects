#!/bin/sh

clear

rm --force type_punning_aka_aliasing_solution_union

gcc -fstrict-aliasing -Wstrict-aliasing=1 -o type_punning_aka_aliasing_solution_union main.cpp
./type_punning_aka_aliasing_solution_union

