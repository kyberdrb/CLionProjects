#include <cassert>
#include <iostream>

float* globalNumber;
int* anotherGlobalNumber;

int main() {
    assert(globalNumber == nullptr);
    assert(anotherGlobalNumber == nullptr);
    std::cout << "globalNumber = " << globalNumber << std::endl;
    std::cout << "anotherGlobalNumber = " << anotherGlobalNumber << std::endl; 

    return 0;
}
