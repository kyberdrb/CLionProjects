#pragma once
#include <cstdint>

class DeepCopyClass
{
public:
	int x;
	uint32_t y;
	int* p;
	
	DeepCopyClass(int, uint32_t, int);
	DeepCopyClass(const DeepCopyClass&);
	DeepCopyClass& operator=(const DeepCopyClass&);
	
	int getP() const
	{
		return *p;
	}

	~DeepCopyClass();
};
