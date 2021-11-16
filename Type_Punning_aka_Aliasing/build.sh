#!/bin/sh

clear

rm --force type_punning_aka_aliasing

gcc -fstrict-aliasing -Wstrict-aliasing=1 -o type_punning_aka_aliasing main.cpp
./type_punning_aka_aliasing

