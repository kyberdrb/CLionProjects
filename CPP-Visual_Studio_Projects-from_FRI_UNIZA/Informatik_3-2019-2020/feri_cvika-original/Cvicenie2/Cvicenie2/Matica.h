#pragma once
#include <string>

enum Temp
{
	NAHODNA_CISELNA_HODNOTA=1,
};

#define HODNOTA 5

const int hodnota = 5;

class Matica
{
public:
	Matica();
	Matica(int sirka, int vyska);
	// pole je nasledne pouzite vnutorne
	Matica(int sirka, int vyska, int** pole);
	~Matica();

	static const int hodnota;

	std::string to_string();
	void Add(int value);
	void Add(Matica const& mat);

	void Subtract(int value);
	void Subtract(Matica const& mat);

	void Multiply(int value);
	void Multiply(Matica const& mat);

	void Clear();

	// odcitanie - maticove a konstanta
	// nasobenie - konstanta a maticove (dodrzat rozmery)
	// podmienky na rozmery
	// transponovanie
	// inverzna matica
	// vynulovanie
private:
	int m_sirka;
	int m_vyska;
	int** m_data;
};

