#pragma once
#include "Uzol.h"

typedef int(*PorovnajPtr)(void* uzol1, void* uzol2);

class Zoznam
{
private:
	Uzol* start = nullptr;
public:

	void Sort(const char* menoSuboru, PorovnajPtr compareFun);
	void Uloz(const char* menoSuboru);

	~Zoznam();

	void Vymaz(Uzol* node);
};

