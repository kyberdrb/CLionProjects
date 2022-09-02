#include "Loteria.h"
#include "Losovanie.h"
#include "Vystup.h"

void Tah(MUINT pocetLosovanychZrebov)
{
	if (pocetLosovanychZrebov > PocetZrebov)
		pocetLosovanychZrebov = PocetZrebov;
	PripravZreby();
	Losuj(pocetLosovanychZrebov);
	Vypis(pocetLosovanychZrebov);
	ZrusZreby();
}
