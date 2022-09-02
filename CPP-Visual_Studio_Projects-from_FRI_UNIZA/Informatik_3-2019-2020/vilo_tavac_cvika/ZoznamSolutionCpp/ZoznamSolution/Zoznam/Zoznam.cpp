#include <stdlib.h>

#include "Zoznam.h"
#include "Vstup.h"
#include "Vystup.h"

void Zoznam::Sort(const char * menoSuboru, PorovnajPtr compareFun)
{
	if (menoSuboru != nullptr && *menoSuboru != 0)
	{
		Vstup citac(menoSuboru);

		Uzol *uzol, *predchadzajuci;
		int cislo = citac.CitajCislo();
		while (cislo != NEPLATNA_HODNOTA)
		{
			if (start == nullptr)
				start = new Uzol(cislo, nullptr);
			else
			{
				predchadzajuci = nullptr;
				uzol = start;
				while (uzol != nullptr && compareFun(&cislo, &uzol->hodnota) > 0)
				{
					predchadzajuci = uzol;
					uzol = uzol->dalsi();
				}
				uzol = new Uzol(cislo, uzol);
				if (predchadzajuci == nullptr)
					start = uzol;
				else
					predchadzajuci->dalsi(uzol);
			}
			cislo = citac.CitajCislo();
		}
	}
}

void Zoznam::Uloz(const char * menoSuboru)
{
	Uzol *uzol = start;
	Vystup vystup(menoSuboru);
	while (uzol != nullptr)
	{
		vystup.ZapisCislo(uzol->hodnota);
		uzol = uzol->dalsi();
	}
}

Zoznam::~Zoznam()
{
	Vymaz(start);
}

void Zoznam::Vymaz(Uzol * node)
{
	if (node->dalsi() != nullptr)
		Vymaz(node->dalsi());
	delete node;
}
