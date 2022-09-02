#include <stdio.h>
#include "Vystup.h"

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
