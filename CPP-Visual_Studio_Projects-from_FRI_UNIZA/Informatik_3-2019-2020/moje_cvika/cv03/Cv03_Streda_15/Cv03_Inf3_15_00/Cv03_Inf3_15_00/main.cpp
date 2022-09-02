#include <cstdint>
#include <iostream>
#include <string>

#define MAX_NUM 123

class Student {
private:
	char meno[20]; 
	char priezvisko[60]; 
	uint8_t rocnik;

public:
	uint8_t getRocnik() const;
};

void foo(const uint64_t*);

int main() {
	int number = 0;
	uint32_t x = 1;

	/*std::cout << "o\\p" << std::endl;
	std::cout << "e\nf" << std::endl;
	std::cout << "a\tb" << std::endl;*/

	const unsigned long long int longInt = 50;

	uint64_t int1 = 100;
	//foo(&int1);

	int anotherNumber{}; // anotherNumber = 0;
	int nextNumber{5};

	//std::cout << anotherNumber << std::endl;
	//std::cout << nextNumber << std::endl;

	uint16_t pocetRokov[3] {22, 33, 44};
	uint16_t* pocetRokovPtr = pocetRokov;
	std::cout << *pocetRokovPtr << std::endl;

	uint16_t temp = *pocetRokovPtr;
	++temp;

	std::cout << temp << std::endl;
	std::cout << ++(*pocetRokovPtr) << std::endl;
	std::cout << *(++pocetRokovPtr) << std::endl;
	std::cout << *(pocetRokovPtr++) << std::endl;
	std::cout << *pocetRokovPtr << std::endl;

	std::string text{"foo bar"};
	const char* c_style_string = text.c_str();
	std::string baz;
	baz = text;
}

void foo(const uint64_t* a) {
	std::cout << *a << std::endl;
}
