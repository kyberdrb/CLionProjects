#include "Test.h"
#include "Loteria.h"

BOOL Testuj()
{
	PripravZreby();
	if (zreby[6].cislo != 7)
		return FALSE;
	Tah(3);

	return FALSE;
}
