#/bin/bash

g++ -E a.cpp > a_translation_unit.cpp
g++ -E b.cpp > b_translation_unit.cpp

