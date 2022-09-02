#include "Matica.h"

Matica::Matica(uint32_t riadky, uint32_t stlpce)
{
	this->pocetRiadkov = riadky;
	this->pocetStlpcov = stlpce;

	this->pole2d = new double* [riadky];	// aky vyznam ma hviezdicka '*' v tomto pripade?
	// Rozdiel medzi 'riadok++' a '++riadok'
	for (uint32_t riadok = 0; riadok < riadky; ++riadok)
	{
		this->pole2d[riadok] = new double[stlpce] {0};
	}
}

Matica::Matica(const Matica& vzorovaMatica)
{
	this->pocetRiadkov = vzorovaMatica.pocetRiadkov;
	this->pocetStlpcov = vzorovaMatica.pocetStlpcov;

	this->pole2d = new double* [vzorovaMatica.pocetRiadkov];
	for (uint32_t riadok = 0; riadok < vzorovaMatica.pocetRiadkov; ++riadok)
	{
		this->pole2d[riadok] = new double[vzorovaMatica.pocetStlpcov];
		for (uint32_t stlpec = 0; stlpec < vzorovaMatica.pocetStlpcov; ++stlpec)
		{
			setPrvok(riadok, stlpec, vzorovaMatica.pole2d[riadok][stlpec]);
		}
	}
}

Matica& Matica::operator=(const Matica& vzorovaMatica) {
	if (this == &vzorovaMatica) {
		return *this;
	}

	for (uint32_t riadok = 0; riadok < this->pocetRiadkov; ++riadok) {
		delete[] this->pole2d[riadok];
		this->pole2d[riadok] = nullptr;
	}

	delete[] this->pole2d;
	this->pole2d = nullptr;

	this->pocetRiadkov = vzorovaMatica.pocetRiadkov;
	this->pocetStlpcov = vzorovaMatica.pocetStlpcov;

	this->pole2d = new double* [this->pocetRiadkov];
	for (uint32_t riadok = 0; riadok < this->pocetRiadkov; ++riadok) {
		this->pole2d[riadok] = new double[this->pocetStlpcov];
		for (uint32_t stlpec = 0; stlpec < this->pocetStlpcov; ++stlpec) {
			setPrvok(riadok, stlpec, vzorovaMatica.pole2d[riadok][stlpec]);
		}
	}
	return *this;
}

Matica::~Matica()
{
	for (uint32_t riadok = 0; riadok < this->pocetRiadkov; ++riadok)
	{
		delete[] this->pole2d[riadok];
		// nastavenim smernika na 'nullptr' osetrime tzv. visiaci smernik - dangling pointer
		this->pole2d[riadok] = nullptr;
	}

	delete[] this->pole2d;
	this->pole2d = nullptr;
}

Matica& operator-(const Matica& prvaMatica, const Matica& druhaMatica)
{
	Matica* const rozdielovaMatica = new Matica(prvaMatica.pocetRiadkov, prvaMatica.pocetStlpcov);
	Matica& nulovaMatica = *rozdielovaMatica;

	if (majuMaticeRozneRozmery(prvaMatica, druhaMatica))
	{
		return nulovaMatica;
	}

	for (uint32_t riadok = 0; riadok < prvaMatica.pocetRiadkov; ++riadok)
	{
		for (uint32_t stlpec = 0; stlpec < prvaMatica.pocetStlpcov; ++stlpec)
		{
			double rozdiel =
				prvaMatica.getPrvok(riadok, stlpec) - druhaMatica.getPrvok(riadok, stlpec);
			rozdielovaMatica->setPrvok(riadok, stlpec, rozdiel);
		}
	}

	return *rozdielovaMatica;
}

bool majuMaticeRozneRozmery(const Matica& prvaMatica, const Matica& druhaMatica)
{
	return
		majuMaticeRoznyPocetRiadkov(prvaMatica, druhaMatica) ||
		majuMaticeRoznyPocetStlpcov(prvaMatica, druhaMatica);
}

bool majuMaticeRoznyPocetRiadkov(const Matica& prvaMatica, const Matica& druhaMatica)
{
	return prvaMatica.getPocetRiadkov() != druhaMatica.getPocetRiadkov();
}

bool majuMaticeRoznyPocetStlpcov(const Matica& prvaMatica, const Matica& druhaMatica)
{
	return prvaMatica.getPocetStlpcov() != druhaMatica.getPocetStlpcov();
}

uint32_t Matica::getPocetRiadkov() const
{
	return pocetRiadkov;
}

uint32_t Matica::getPocetStlpcov() const
{
	return pocetStlpcov;
}

Matica& Matica::operator*=(double skalar)
{
	for (uint32_t riadok = 0; riadok < this->pocetRiadkov; ++riadok)
	{
		for (uint32_t stlpec = 0; stlpec < this->pocetStlpcov; ++stlpec)
		{
			double sucin = this->getPrvok(riadok, stlpec) * skalar;
			this->setPrvok(riadok, stlpec, sucin);
		}
	}
	return *this;
}

double Matica::getPrvok(uint32_t riadok, uint32_t stlpec) const
{
	return this->pole2d[riadok][stlpec];
}

void Matica::setPrvok(uint32_t riadok, uint32_t stlpec, double hodnota)
{
	this->pole2d[riadok][stlpec] = hodnota;
}

// Test 2 - zadanie

Matica& operator+(const Matica& prvaMatica, const Matica& druhaMatica)
{
	Matica* const scitanaMatica = new Matica(prvaMatica.pocetRiadkov, prvaMatica.pocetStlpcov);
	Matica& nulovaMatica = *scitanaMatica;

	if (majuMaticeRozneRozmery(prvaMatica, druhaMatica))
	{
		return nulovaMatica;
	}

	for (uint32_t riadok = 0; riadok < prvaMatica.pocetRiadkov; ++riadok)
	{
		for (uint32_t stlpec = 0; stlpec < prvaMatica.pocetStlpcov; ++stlpec)
		{
			double sucetPrvkov =
				prvaMatica.getPrvok(riadok, stlpec) +
				druhaMatica.getPrvok(riadok, stlpec);
			scitanaMatica->setPrvok(riadok, stlpec, sucetPrvkov);
		}
	}

	return *scitanaMatica;
}

Matica& Matica::operator/=(double skalar)
{
	for (uint32_t riadok = 0; riadok < this->pocetRiadkov; ++riadok)
	{
		for (uint32_t stlpec = 0; stlpec < this->pocetStlpcov; ++stlpec)
		{
			this->pole2d[riadok][stlpec] /= skalar;
		}
	}
	return *this;
}

std::istream& operator>>(std::istream& in, Matica& alokovanaMatica)
{
	for (uint32_t riadok = 0; riadok < alokovanaMatica.pocetRiadkov; ++riadok)
	{
		for (uint32_t stlpec = 0; stlpec < alokovanaMatica.pocetStlpcov; ++stlpec)
		{
			double prvok{};
			in >> prvok;
			alokovanaMatica.setPrvok(riadok, stlpec, prvok);
			in >> std::ws;
		}
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Matica& matica)
{
	out << matica.pocetRiadkov << "\n";
	out << matica.pocetStlpcov << "\n";
	for (uint32_t riadok = 0; riadok < matica.pocetRiadkov; ++riadok)
	{
		for (uint32_t stlpec = 0; stlpec < matica.pocetStlpcov; ++stlpec)
		{
			out << matica.getPrvok(riadok, stlpec) << " ";
		}
		out << "\n";
	}
	return out;
}

/*
Matica& Matica::operator+(double x) {
	for (uint32_t i = 0; i < this->pocetRiadkov; i++) {
		for (uint32_t j = 0; j < this->pocetStlpcov; j++) {
			this->pole2d[i][j] += x;
		}
	}
	return *this;
}

double* Matica::operator[](uint32_t riadok) {
	if (riadok >= this->pocetRiadkov) {
		throw std::out_of_range("Mimo rozsahu!!!");
	}
	return this->pole2d[riadok];
}

bool Matica::operator<(const Matica& second) const {
	return (this->sucetPrvkov() < second.sucetPrvkov());
}

bool Matica::operator>(const Matica& second) const {
	return (this->sucetPrvkov() > second.sucetPrvkov());
}

bool Matica::operator<=(const Matica& second) const {
	return (this->sucetPrvkov() <= second.sucetPrvkov());
}

bool Matica::operator>=(const Matica& second) const {
	return (this->sucetPrvkov() >= second.sucetPrvkov());
}

bool Matica::operator==(const Matica& second) const {
	if ((this->pocetRiadkov != second.pocetRiadkov) || (this->pocetStlpcov != second.pocetStlpcov)) {
		return false;
	}
	for (uint32_t i = 0; i < this->pocetRiadkov; i++) {
		for (uint32_t j = 0; j < this->pocetStlpcov; j++) {
			if (this->pole2d[i][j] != second.pole2d[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool Matica::operator!=(const Matica& second) const {
	return !(this->operator==(second));
}

Matica* operator*(const Matica& first, const Matica& second) {
	if (first.pocetRiadkov != second.pocetStlpcov) {
		std::cout << "Nie je mozne nasobit matice..." << std::endl;
		return nullptr;
	}
	Matica* vysledna = new Matica(first.pocetRiadkov, second.pocetStlpcov, 0);
	for (uint32_t i = 0; i < vysledna->pocetRiadkov; i++) {
		for (uint32_t j = 0; j < vysledna->pocetStlpcov; j++) {
			for (uint32_t k = 0; k < first.pocetStlpcov; k++) {
				vysledna->matica[i][j] += (first.pole2d[i][k] * second.pole2d[k][j]);
			}
		}
	}
	return vysledna;
}

void Matica::vyplnMaticuHodnotou(double hodnota) {
	for (uint32_t i = 0; i < this->pocetRiadkov; i++) {
		for (uint32_t j = 0; j < this->pocetStlpcov; j++) {
			this->pole2d[i][j] = hodnota;
		}
	}
}

#include <ctime>

void Matica::vyplnMaticuNahodnymiParnymiHodnotami(uint32_t range) {
	std::srand(static_cast<unsigned int>(time(nullptr)));
	for (uint32_t i = 0; i < this->pocetRiadkov; i++) {
		for (uint32_t j = 0; j < this->pocetStlpcov; j++) {
			this->pole2d[i][j] = (std::rand() % (range + 1)) * 2;
		}
	}
}

double Matica::sucetPrvkov() const {
	double sucet{};
	for (unsigned int i = 0; i < this->pocetRiadkov; ++i) {
		for (unsigned int j = 0; j < this->pocetStlpcov; ++j) {
			sucet += this->pole2d[i][j];
		}
	}
	return sucet;
}

Matica& Matica::operator*(double number) {
	for (uint32_t i = 0; i < this->pocetRiadkov; i++) {
		for (uint32_t j = 0; j < this->pocetStlpcov; j++) {
			this->pole2d[i][j] *= number;
		}
	}
	return *this;
}
*/
