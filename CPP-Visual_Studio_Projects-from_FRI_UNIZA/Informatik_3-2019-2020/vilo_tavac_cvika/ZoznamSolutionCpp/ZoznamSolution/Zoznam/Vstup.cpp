#include "Vstup.h"

Vstup::Vstup(const char * menosuboru)
{
	fhandle = nullptr;
	if (menosuboru != nullptr && *menosuboru != 0)
	{
		fhandle = fopen(menosuboru, "rt");
	}
}

Vstup::~Vstup()
{
	if (fhandle != nullptr)
		fclose(fhandle);
}

int Vstup::CitajCislo()
{
	if (fhandle != nullptr)
	{
		if (!feof(fhandle))
		{
			int cislo;
			fscanf(fhandle, "%d", &cislo);
			return cislo;
		}
	}
	return 0;
}
