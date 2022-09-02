#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "Losovanie.h"

void Vymen(MUINT index, MUINT i);
void Vymen1(MUINT index, MUINT i);

void Losuj(MUINT pocetLosovanychZrebov)
{
	srand((unsigned int)time(NULL));
	for (MUINT i = 0; i < pocetLosovanychZrebov && i < PocetZrebov; i++)
	{
		MUINT index = rand() % (PocetZrebov - i) + i;
		Vymen(index, i);
	}
}


void Vymen1(MUINT index, MUINT i)
{
	struct Zreb pom;

	pom.cislo = zreby[index].cislo;
	zreby[index].cislo = zreby[i].cislo;
	zreby[i].cislo = pom.cislo;
}

void Vymen(MUINT index, MUINT i)
{
	struct Zreb pom;
	pom = zreby[index];
	zreby[index] = zreby[i];
	zreby[i] = pom;
}
