#include <stdio.h>
#include <stdlib.h>

typedef unsigned int MUINT;
typedef unsigned short BOOL;

struct Zreb {
	MUINT cislo;
	char kod;
};

MUINT PocetZrebov;

void Tah(MUINT pocetLosovanychZrebov);

// UML vyplynie z logickej sudrznosti
int main(int argc, char* argv[])
{
	/*PocetZrebov = atoi(argv[1]);
	printf("%d\n", PocetZrebov);*/

	PocetZrebov = atoi(argv[1]);
	Tah(atoi(argv[2]));
	
	return 0;
}

struct Zreb* zreby;

void PripravZreby();
// implicitny `this` nahradime explicitnym parametrom na struct.
//  tak sa vieme vyhnut globalnym premennym - vyuzijeme zapuzdrenie
//void PripravZreby(struct Zreb* zreby);
void Losuj(MUINT pocetLosovanychZrebov);
void Vypis(MUINT pocetLosovanychZrebov);
void ZrusZreby();

void Tah(MUINT pocetLosovanychZrebov)
{
	if (pocetLosovanychZrebov > PocetZrebov)
		pocetLosovanychZrebov = PocetZrebov;
	PripravZreby();
	Losuj(pocetLosovanychZrebov);
	Vypis(pocetLosovanychZrebov);
	ZrusZreby();
}

void PripravZreby()
{
	if (PocetZrebov > 0)
	{
		zreby = malloc(PocetZrebov * sizeof(struct Zreb)); // malloc vs calloc 
		for (MUINT i = 0; i < PocetZrebov; i++)
		{
			zreby[i].cislo = i + 1;
			zreby[i].kod = 'A' + (i % 26);
		}
	}
}

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

void Vymen(MUINT index, MUINT i)
{
	struct Zreb pom;
	pom = zreby[index];
	zreby[index] = zreby[i];
	zreby[i] = pom;
}

void Vymen1(MUINT index, MUINT i)
{
	struct Zreb pom;

	pom.cislo = zreby[index].cislo;
	zreby[index].cislo = zreby[i].cislo;
	zreby[i].cislo = pom.cislo;
}

void Vypis(MUINT pocetLosovanychZrebov)
{
	printf("\nVYSLEDOK ZREBOVANIA\n----------------------------\n");
	for (MUINT i = 0; i < pocetLosovanychZrebov && i < PocetZrebov; i++)
	{
		printf("%3u. poradie:\t%c %010u\n",
			i + 1,
			zreby[i].kod, zreby[i].cislo);
	}
	printf("----------------------------\nKONIEC\n");
}

void ZrusZreby()
{
	if (zreby != NULL)
		free(zreby);
	zreby = NULL;
}
