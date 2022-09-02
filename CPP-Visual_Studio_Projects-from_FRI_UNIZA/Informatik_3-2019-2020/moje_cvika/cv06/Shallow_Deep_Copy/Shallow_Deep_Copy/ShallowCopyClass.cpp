#include "ShallowCopyClass.h"

ShallowCopyClass::ShallowCopyClass(int x, uint32_t y)
{
	this->x = x;
	this->y = y;
}

// Explicitly defined copy constructor doesn't even need to exist
//  in order to make a deep copy of this instance.
//  Since the class has only primitive attributes,
//  the implicit copy constructor copies them automatically.
//  Try to remove it or comment it out, and see
//  that the copy initialization is still functional.
//  The same is true for the copy assignment operator.
//  The implicit one is sufficient for the deep copy of the instance,
//  beacuse the class contains only primitive types.
//ShallowCopyClass::ShallowCopyClass(const ShallowCopyClass& obj)
//{
//	this->x = obj.x;
//	this->y = obj.y;
//}
