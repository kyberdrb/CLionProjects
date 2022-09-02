#pragma once
#include <cstdint>

class ShallowCopyClass
{
public:
	int x;
	uint32_t y;	// types from 'cstdint' library are also primitive
	
	//ShallowCopyClass(const ShallowCopyClass&);
	ShallowCopyClass(int, uint32_t);
};

