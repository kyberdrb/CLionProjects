#pragma once
#include <cstdio>
using namespace std;

class Vstup
{
private:
	FILE* fhandle;
public:
	Vstup(const char* menosuboru);

	~Vstup();

	int CitajCislo();
};

