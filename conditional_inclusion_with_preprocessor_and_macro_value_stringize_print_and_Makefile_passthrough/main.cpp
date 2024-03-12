#include <iostream>

#define STRINGIZE(x) #x
#define STRINGIZE_VALUE(x) STRINGIZE(x)

int main() {
    std::cout << "Debug level: ";
#ifdef DEBUG_MODE
	std::cout << STRINGIZE(DEBUG_MODE) << " -> " << STRINGIZE_VALUE(DEBUG_MODE);
#else
	std::cout << "undefined";
#endif
	std::cout << std::endl;
    return 0;
}

