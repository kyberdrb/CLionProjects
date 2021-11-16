#!/bin/sh

clear

rm strict_aliasing_rule_ex_1

# the compiler warns about the violation of the strict aliasing only when
# the option "-fstrict-aliasing" is present 
# together with option "-Wstrict-aliasing=2" - level 1 also reports the warning, level 3, the default one, hides the warning
gcc -fstrict-aliasing -Wstrict-aliasing=2 -o strict_aliasing_rule_ex_1 main.cpp
./strict_aliasing_rule_ex_1

