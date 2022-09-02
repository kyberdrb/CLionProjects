#include "Matica.h"
#include <stdlib.h>

const int Matica::hodnota = 1;

Matica::Matica() :
	m_sirka(5), m_vyska(5), m_data(new int* [m_vyska])
{
	for (int i = 0; i < m_vyska; ++i)
		m_data[i] = new int[m_sirka];

	int pole[5][5] =
	{
		{5,5,5,5,5},
		{5,5,5,5,5},
		{5,5,5,5,5},
		{5,5,5,5,5},
		{5,5,5,5,5},
	};

	for (int i = 0; i < m_vyska; ++i)
		for (int k = 0; k < m_sirka; ++k)
			m_data[i][k] = pole[i][k];
}

Matica::Matica(int sirka, int vyska) :
	m_sirka(sirka), m_vyska(vyska), m_data(new int*[m_vyska])
{
	for (int i = 0; i < m_vyska; ++i)
		m_data[i] = new int[m_sirka];

	for (int i = 0; i < m_vyska; ++i)
	{
		for (int k = 0; k < m_sirka; ++k)
		{
			m_data[i][k] = rand() % 20;
		}
	}
}

Matica::Matica(int sirka, int vyska, int** pole) : 
	m_sirka(sirka), m_vyska(vyska), m_data(pole)
{

}

Matica::~Matica()
{
	for (int i = 0; i < m_vyska; ++i)
		delete[]m_data[i];
	delete[]m_data;
}

std::string Matica::to_string()
{
	std::string output = "";
	for (int i = 0; i < m_vyska; ++i)
	{
		for (int k = 0; k < m_sirka; ++k)
		{
			output += std::to_string(m_data[i][k]) + " ";
		}
		output += "\n";
	}

	return output;
}

void Matica::Add(int value)
{
	for (int i = 0; i < m_vyska; ++i)
		for (int k = 0; k < m_sirka; ++k)
			m_data[i][k] += value;
}

void Matica::Add(Matica const& mat)
{
	for (int i = 0; i < m_vyska; ++i)
		for (int k = 0; k < m_sirka; ++k)
			m_data[i][k] += mat.m_data[i][k];
}

void Matica::Subtract(int value)
{
	for (int i = 0; i < m_vyska; ++i)
		for (int k = 0; k < m_sirka; ++k)
			m_data[i][k] -= value;
}

void Matica::Subtract(Matica const& mat)
{
	for (int i = 0; i < m_vyska; ++i)
		for (int k = 0; k < m_sirka; ++k)
			m_data[i][k] -= mat.m_data[i][k];
}

void Matica::Multiply(int value)
{
	for (int i = 0; i < m_vyska; ++i)
		for (int k = 0; k < m_sirka; ++k)
			m_data[i][k] *= value;
}

void Matica::Multiply(Matica const& mat)
{
	if (m_sirka != mat.m_vyska)
		return;
	int** noveData = new int* [m_vyska];
	for (int i = 0; i < m_vyska; ++i)
		noveData[i] = new int[mat.m_sirka];
	for (int i = 0; i < m_vyska; ++i)
	{
		for (int k = 0; k < mat.m_sirka; ++k)
		{
			int value = 0;
			for (int l = 0; l < m_sirka; ++l)
				value += m_data[i][l] * mat.m_data[l][k];
			noveData[i][k] = value;
		}
	}
	for (int i = 0; i < m_vyska; ++i)
		delete[]m_data[i];
	delete[]m_data;
	m_sirka = mat.m_sirka;
	m_data = noveData;
}

void Matica::Clear()
{
	for (int i = 0; i < m_vyska; ++i)
		for (int k = 0; k < m_sirka; ++k)
			m_data[i][k] = 0;
}
