#ifndef DEBUG
#define DEBUG

#include <cassert>
#include <iostream>

int main() {
    std::cout << "ouput message for release build" << std::endl;
#ifdef DEBUG
    std::cout << "main.cpp: log ouput message for debug build" << std::endl;
#endif
#ifdef OUTSIDE_CMAKE_VARIABLE
    std::cout << "custom ouput message passed from 'cmake' command line as an parameter with '-DOUTSIDE_CMAKE_VARIABLE=EXAMPLE_VALUE'" << std::endl;
#endif
    assert(1 == 2);
    return 0;
}
#endif
