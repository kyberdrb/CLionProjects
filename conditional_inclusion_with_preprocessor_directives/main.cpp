// define macro internally, i. e. in the source code
#ifndef DEBUG_LOGGING
#define DEBUG_LOGGING

#include <cassert>
#include <iostream>

int main() {
    std::cout << "ouput message for release build" << std::endl;

#ifdef DEBUG_LOGGING
    std::cout << "main.cpp: log ouput message for debug build" << std::endl;
#endif

    // define macro externally, i. e. outside of the source code - from the CMake makefile generator command
#ifdef OUTSIDE_CMAKE_VARIABLE
    std::cout << "custom ouput message passed from 'cmake' command line as an parameter with '-DOUTSIDE_CMAKE_VARIABLE=EXAMPLE_VALUE'" << std::endl;
#endif

    // define macro externally, i. e. outside of the source code - from the CMakeLists.txt via 'target_compile_definitions'
    assert(1 == 2);

    return 0;
}
#endif
