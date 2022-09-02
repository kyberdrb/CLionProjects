#include <iostream>

#include "HelloWorld.h"

void HelloWorld::say_in_cpp() {
	std::cout << std::endl;
	std::cout << "Hello World" << std::endl;
	std::cout << "Enter your name" << std::endl;
	std::string name;
	std::cin >> name;
	std::cout << "Hello, " << name << std::endl;
}
