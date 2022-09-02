#include <malloc.h>
#include "Data.h"

struct Zreb *zreby;
MUINT PocetZrebov;

void PripravZreby()
{
	if (PocetZrebov > 0)
	{
		zreby = malloc(PocetZrebov * sizeof(struct Zreb));
		for (MUINT i = 0; i < PocetZrebov; i++)
		{
			zreby[i].cislo = i + 1;
			zreby[i].kod = 'A' + (i % 26);
		}
	}
}

void ZrusZreby()
{
	if (zreby != NULL)
		free(zreby);
	zreby = NULL;
}
