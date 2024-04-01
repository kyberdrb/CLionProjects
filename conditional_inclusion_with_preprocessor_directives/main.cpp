// define macro internally, i. e. in the source code
#ifndef DEBUG_LOGGING
#define DEBUG_LOGGING

#define STRINGIZE(x) #x
#define STRINGIZE_VALUE(x) STRINGIZE(x)

#include <cassert>
#include <iostream>

int main() {
    std::cout << "Examples of conditional inclusion of code and macro value printing" << std::endl;

#ifdef DEBUG_LOGGING
    std::cout << "main.cpp: log ouput message for debug build" << std::endl;
#endif

    // define macro externally, i. e. outside of the source code - from the CMake makefile generator command
#ifdef OUTSIDE_CMAKE_VARIABLE_PASSED_TO_SOURCE_CODE_FROM_CMAKE
    std::cout << "Custom output message passed from 'cmake' command line as an parameter with '-DOUTSIDE_CMAKE_VARIABLE_PASSED_TO_SOURCE_CODE_FROM_CMAKE'" << std::endl;
    std::cout << "  Printing the value of macro 'OUTSIDE_CMAKE_VARIABLE_PASSED_TO_SOURCE_CODE_FROM_CMAKE' with 'stringizing', " << std::endl;
    std::cout << "    i.e. transformation of macro to 'string' with preprocessor's 'stringizing' operator '#'" << std::endl;
    std::cout << "  " << STRINGIZE(OUTSIDE_CMAKE_VARIABLE_PASSED_TO_SOURCE_CODE_FROM_CMAKE) << " -> " << STRINGIZE_VALUE(OUTSIDE_CMAKE_VARIABLE_PASSED_TO_SOURCE_CODE_FROM_CMAKE) << std::endl;
    std::cout << "  stringized macro name:  " << STRINGIZE(OUTSIDE_CMAKE_VARIABLE_PASSED_TO_SOURCE_CODE_FROM_CMAKE) << std::endl;
    std::cout << "  stringized macro value: " << STRINGIZE_VALUE(OUTSIDE_CMAKE_VARIABLE_PASSED_TO_SOURCE_CODE_FROM_CMAKE) << std::endl;
#endif

#ifdef NDEBUG
    std::cout << "Disabling 'assert' macros by passing '-DNDEBUG' to compiler:" << std::endl;
    std::cout << "  NDEBUG = " << STRINGIZE_VALUE(NDEBUG) << std::endl;
#endif
    // define macro externally, i. e. outside of the source code - from the CMakeLists.txt via 'target_compile_definitions'
    assert(1 == 2);

    return 0;
}
#endif
