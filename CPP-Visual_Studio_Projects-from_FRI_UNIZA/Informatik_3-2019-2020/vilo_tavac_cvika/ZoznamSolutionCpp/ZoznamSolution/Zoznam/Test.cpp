#include "Test.h"
#include "Zoznam.h"
#include "Uzol.h"

bool Testuj()
{
	Zoznam zoznam;

	zoznam.Sort("data.txt", Porovnaj);
	zoznam.Uloz("sorted.txt");
	zoznam.Uloz(nullptr);
	return true;
}