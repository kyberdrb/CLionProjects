#!/bin/sh

clear

rm --force type_punning_aka_aliasing_with_struct_thecherno

gcc -fstrict-aliasing -Wstrict-aliasing=1 -o type_punning_aka_aliasing_with_struct_thecherno main.cpp
./type_punning_aka_aliasing_with_struct_thecherno

