#pragma once

typedef int TYPHODNOTA;

const TYPHODNOTA NEPLATNA_HODNOTA = 0;

int Porovnaj(void* cislo1ptr, void* cislo2ptr);

class Uzol
{
private:
	Uzol* aDalsi = nullptr;

public:
	Uzol(TYPHODNOTA phodnota, Uzol* pdalsi);
	TYPHODNOTA hodnota;

	Uzol* dalsi() { return aDalsi; }
	void dalsi(Uzol* pdalsi) { aDalsi = pdalsi; }
};
