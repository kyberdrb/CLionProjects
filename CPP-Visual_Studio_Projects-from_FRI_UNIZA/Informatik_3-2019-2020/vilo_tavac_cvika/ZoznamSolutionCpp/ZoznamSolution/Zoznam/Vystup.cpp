#include "Vystup.h"

Vystup::Vystup(const char * menosuboru)
{
	if (menosuboru != nullptr && *menosuboru != 0)
	{
		fhandle = fopen(menosuboru, "wt");
	}
}

Vystup::~Vystup()
{
	if (fhandle != nullptr)
		fclose(fhandle);
}

void Vystup::ZapisCislo(int cislo)
{
	if (fhandle != nullptr)
	{
		fprintf(fhandle, "%d\n", cislo);
	}
	else
		printf("%d\n", cislo);
}
