#include "Uzol.h"

int Porovnaj(void * cislo1ptr, void * cislo2ptr)
{
	TYPHODNOTA *p1 = (TYPHODNOTA *)cislo1ptr;
	TYPHODNOTA *p2 = (TYPHODNOTA *)cislo2ptr;

	return *p1 - *p2;
}


Uzol::Uzol(TYPHODNOTA phodnota, Uzol * pdalsi)
{
	hodnota = phodnota;
	aDalsi = pdalsi;
}
