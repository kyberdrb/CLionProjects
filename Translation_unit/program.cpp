#include "header.hpp"

int strlen(const char* string)
{
	int length = 0;

	while(string[length]) ++length;

	return length + VALUE;
}
