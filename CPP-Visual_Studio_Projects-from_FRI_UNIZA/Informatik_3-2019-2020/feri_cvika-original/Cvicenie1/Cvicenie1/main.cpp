#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h> //cstring
#include <string>
void funkcia1(int value) // by value
{
	value += 1;
	printf("%d", value); // 1
}
void funkcia2(int& value) // by reference
{
	value += 1;
	printf("%d", value); // 1
}
void funkcia3(int* value) // by pointer
{
	if (value == nullptr)
		return;
	*value += 1;
	printf("%d", *value); // 1
}

int main(int argc, char* argv[])
{
	// int temp;
	//scanf("%d", &temp);
	//printf("%d\n", temp);
	/*std::cin >> temp;
	std::cout << temp << std::endl;*/	
	//for (int i = 0; i < argc; ++i)
	//	printf("%s\n", argv[i]);
	//char pole[] = "BlaBlaBla1";
	//std::string string = "BlaBlaBla2";
	//std::string* string2 = nullptr;
	//// new std::string("BlaBlaBla3")
	//printf("%s\n", pole);
	//printf("%s\n", string.data());
	//std::cout << pole << std::endl;
	//std::cout << string << std::endl;
	//delete string2;
	//string2 = nullptr;
	//delete string2;
	//int a = 5;
	//int* b = &a;
	//printf("%d", *b);
	int first = 0;
	funkcia1(first);
	printf("%d\n", first); // 0
	int second = 0;
	int* test = nullptr;
	funkcia2(second);
	printf("%d\n", second); // 1
	int third = 0;
	funkcia3(&third);
	printf("%d\n", third); // 1
	int* hodnota = new int();
	*hodnota = 5;
	delete hodnota;
	printf("%d", *hodnota);

	return 0;
}