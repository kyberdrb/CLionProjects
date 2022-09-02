// allows for using "scanf"
#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"

#include "HelloWorld.h"

void say_in_c();
int changeVariableByValue(int);
int changeVariableByPointer(int*);
int changeVariableByReference(int&);

int main() {
	/*say_in_c();

	HelloWorld helloWorld;
	helloWorld.say_in_cpp();*/

	int age = 20;
	printf("%d\n", age);
	changeVariableByValue(age);
	printf("%d\n\n", age);

	printf("%d\n", age);
	changeVariableByPointer(&age);
	printf("%d\n\n", age);

	printf("%d\n", age);
	changeVariableByReference(age);
	printf("%d\n\n", age);

	return 0;
}

#include "stdio.h"
void say_in_c() {
	printf("%s\n", "Enter your name");

	char name[50];
	int load_status = scanf("%s", name);
	printf("%s, %s\n", "Hello", name);
	printf("%d", load_status);
	printf("\n");
}


int changeVariableByValue(int number) {
	number += 10;
	printf("%d\n", number);
	return number;
}

int changeVariableByPointer(int* number) {
	*number += 10;
	printf("%d\n", *number);
	return *number;
}

int changeVariableByReference(int& number) {
	number += 10;
	printf("%d\n", number);
	return number;
}