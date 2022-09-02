#pragma once
#include <stdio.h>

class Vystup
{
private:
	FILE* fhandle = nullptr;
public:
	Vystup(const char* menosuboru);
	~Vystup();

	void ZapisCislo(int cislo);
};

