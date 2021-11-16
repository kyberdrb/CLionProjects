# 1 "program.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "program.cpp"
# 1 "header.hpp" 1
       
# 11 "header.hpp"
int strlen(const char* string);
# 2 "program.cpp" 2

int strlen(const char* string)
{
 int length = 0;

 while(string[length]) ++length;

 return length + 5;
}
