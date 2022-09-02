#include "DeepCopyClass.h"

DeepCopyClass::DeepCopyClass(int x, uint32_t y, int value)
{
	this->x = x;
	this->y = y;
	this->p = new int(value);
}

DeepCopyClass::~DeepCopyClass()
{
	delete p;
	p = nullptr;
}

// We need to define a copy constructor for this class
//  in order to make a deep copy of this instance
//  beacuse it has a attribute of a pointer type.
//  In a shallow copy we would only copy the pointer address.
//  In a deep copy we look what are the data behind the address
//  and copy the data instead of the address.
DeepCopyClass::DeepCopyClass(const DeepCopyClass& obj)
{
	this->x = obj.x;
	this->y = obj.y;
	
	//this->p = new int(*(obj.p));
	this->p = new int(obj.getP());
}

DeepCopyClass& DeepCopyClass::operator=(const DeepCopyClass& deepInstance)
{
	// check for self-assignment
	if (this == &deepInstance) return *this;

	// delete resources allocated for this instance
	//  just like in the destructor
	delete this->p;
	p = nullptr;

	// do the exact same steps as in the copy constructor
	this->x = deepInstance.x;
	this->y = deepInstance.y;
	this->p = new int(deepInstance.getP());		//deep copy
	//this->p = deepInstance.p;					//shallow copy
	
	return *this;
}