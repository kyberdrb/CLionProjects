#define TESTY
#include <stdio.h>

#ifdef TESTY
#include "Test.h"
#endif

int main()
{
	bool ok = true;
#ifdef TESTY
	ok = Testuj();
#endif
	if (ok == true)
		;
	else
		printf("CHYBA");
	return 0;
}