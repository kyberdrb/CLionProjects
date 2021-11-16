#include <cassert>
#include <iostream>

float* globalNumber = new float(1.2);
int* anotherGlobalNumber = new int{34};

int main() {
    assert(globalNumber == nullptr);
    assert(anotherGlobalNumber == nullptr);
    std::cout << "globalNumber = " << globalNumber << std::endl;
    std::cout << "anotherGlobalNumber = " << anotherGlobalNumber << std::endl; 

    delete globalNumber;
    globalNumber = nullptr;
    delete anotherGlobalNumber;
    anotherGlobalNumber = nullptr;

    return 0;
}
