#pragma once

#include <iostream>
#include <cstdint>

class Matica {
private:
	double** pole2d;
	uint32_t pocetRiadkov;
	uint32_t pocetStlpcov;

	double getPrvok(uint32_t riadok, uint32_t stlpec) const;
	void setPrvok(uint32_t riadok, uint32_t stlpec, double hodnota);

public:
	Matica(uint32_t riadky = 0, uint32_t stlpce = 0);
	Matica(const Matica&);
	Matica& operator=(const Matica&);
	~Matica();

	// V Jave je kazdy objektovy typ v parametri alebo navratovej hodnote metody
	//  predany ako referencia. Tak mozeme upravovat ten isty objekt.
	//  V C++ je referencna premenna oznacena znakom '&' za jeho typom,
	//  napr. 'Matica&'.
	//  Referencia je sucastou typu, rovnako ako smernik '*' alebo 'const'.
	Matica& operator*=(double skalar);
	friend Matica& operator-(const Matica& prvaMatica, const Matica& druhaMatica);

	friend std::istream& operator>>(std::istream& in, Matica& alokovanaMatica);
	friend std::ostream& operator<<(std::ostream& out, const Matica& matica);

	uint32_t getPocetRiadkov() const;
	uint32_t getPocetStlpcov() const;

	friend bool majuMaticeRozneRozmery(const Matica& prvaMatica, const Matica& druhaMatica);
	friend bool majuMaticeRoznyPocetRiadkov(const Matica& prvaMatica, const Matica& druhaMatica);
	friend bool majuMaticeRoznyPocetStlpcov(const Matica& prvaMatica, const Matica& druhaMatica);

	// Test 2 - zadanie
	Matica& operator/=(double skalar);
	friend Matica& operator+(const Matica& prvaMatica, const Matica& druhaMatica);

	/*
	double* operator[](uint32_t);

	friend Matica* operator*(const Matica&, const Matica&);

	bool operator<(const Matica&) const;
	bool operator>(const Matica&) const;
	bool operator<=(const Matica&) const;
	bool operator>=(const Matica&) const;
	bool operator==(const Matica&) const;
	bool operator!=(const Matica&) const;

	void vyplnMaticuHodnotou(double);
	void vyplnMaticuNahodnymiParnymiHodnotami(uint32_t);
	double sucetPrvkov() const;

	inline double getPocetRiadkov() const { return this->pocetRiadkov; }
	inline double getPocetStlpcov() const { return this->pocetStlpcov; }
	inline double** getMatica() const { return this->matica; }
	inline double* getIndex(uint32_t riadok, uint32_t stlpec) { return &this->matica[riadok][stlpec]; }

	inline bool jeStvorcova() const
	{
		return (this->pocetRiadkov == this->pocetStlpcov);
	}
	*/
};
