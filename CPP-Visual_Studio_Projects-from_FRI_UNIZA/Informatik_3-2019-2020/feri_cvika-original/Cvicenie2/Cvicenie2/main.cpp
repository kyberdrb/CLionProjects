#include <array>
#include <vector>
#include "Matica.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char* argv[])
{
	srand(time(nullptr));
	if (argc < 2)
		return -1;

	//if (strcmp(argv[5], "jedendvatri") == 0)
	//	return 0;

	//std::string temp(argv[5]);
	//if (temp == "dalsistring")
	//	return 0;

	int sirka = std::atoi(argv[1]);
	int vyska = std::atoi(argv[2]);
	int** pole = new int*[vyska];
	for (int i = 0; i < vyska; ++i)
	{
		pole[i] = new int[sirka];
		for (int k = 0; k < sirka; ++k)
		{
			int index = i * sirka + k + 3;
			if (argc <= index)
			{
				for (int l = i; l >= 0; --l)
					delete[]pole[l];

				delete[]pole;
				return -1;
			}
			pole[i][k] = std::atoi(argv[index]);
		}
	}
	Matica prva;
	Matica druha(sirka, vyska, pole);
	printf("%s\n", prva.to_string().data());
	printf("%s\n", druha.to_string().data());
	/*Matica matica(5, 10);
	printf("%s\n", matica.to_string().data());
	Matica* matica2 = new Matica(5, 10);
	printf("%s\n", matica2->to_string().data());
	matica.Add(9);
	printf("%s\n", matica.to_string().data());
	matica.Add(*matica2);
	printf("%s\n", matica.to_string().data());
	delete matica2;*/
	//int pole[] = {5,6,8,9,10};
	//int pole5[5];
	//pole5[0] = 5;
	//int* pole2 = new int[5];
	//delete[]pole2;
	//std::array<int, 5> pole3;
	//for (int i = 0; i < 5; ++i)
	//{
	//	printf("%d", i[pole2]/*pole2[i]*/);
	//	printf("%d", pole3[i]);
	//}
	//for (int data : pole3)
	//	printf("%d", data);
	//for (auto itr = pole3.begin(); itr != pole3.end(); ++itr)
	//	printf("%d", (*itr));
	//std::vector<int> pole4(100);
	//pole4[99] = 5;
	//pole4.size();
	//pole4.push_back(5);
	/*
	int* jednorozmerne = new int[100];
	int** dvojrozmerne = new int*[10];
	for (int i = 0; i < 10; ++i)
		dvojrozmerne[i] = new int[10];
	int a = 5;
	int b = 6;
	dvojrozmerne[a][b];
	jednorozmerne[a * 10 + b];
	*/
	return 0;
}