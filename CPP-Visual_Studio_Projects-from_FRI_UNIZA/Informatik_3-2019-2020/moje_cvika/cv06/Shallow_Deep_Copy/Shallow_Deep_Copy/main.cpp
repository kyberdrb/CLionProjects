#include <iostream>
#include "DeepCopyClass.h"
#include "ShallowCopyClass.h"

using namespace std;

void makeShallowCopyWithCopyConstructor();
void makeDeepCopyWithCopyConstructor();
void makeDeepCopyWithCopyAssignmentOperator();

int main()
{
	makeShallowCopyWithCopyConstructor();
	makeDeepCopyWithCopyConstructor();
	makeDeepCopyWithCopyAssignmentOperator();

	return 0;
}

void makeShallowCopyWithCopyConstructor()
{
	cout << "Shallow Copy" << endl;
	ShallowCopyClass* shallowInstance = new ShallowCopyClass(2, 4);
	cout << "x" << "\t" << "y" << endl;
	cout << "----------" << endl;
	cout << shallowInstance->x << "\t" << shallowInstance->y << endl;
	
	// Copy Constructor invocation
	ShallowCopyClass* anotherShallowInstance = new ShallowCopyClass(*shallowInstance);
	cout << anotherShallowInstance->x << "\t" << anotherShallowInstance->y << endl;

	cout << endl;

	anotherShallowInstance->x = 1;
	cout << shallowInstance->x << "\t" << shallowInstance->y << endl;
	cout << anotherShallowInstance->x << "\t" << anotherShallowInstance->y << endl;

	delete shallowInstance;
	shallowInstance = nullptr;

	delete anotherShallowInstance;
	anotherShallowInstance = nullptr;

	cout << endl;
}

void makeDeepCopyWithCopyConstructor()
{
	cout << "Deep Copy - Copy Constructor" << endl;
	DeepCopyClass* deepInstance = new DeepCopyClass(5, 7, 9);
	// Copy Constructor invokation
	//  Copy constructor is necessary in order to make the copy assignment
	DeepCopyClass* anotherDeepInstance = new DeepCopyClass(*deepInstance);

	cout << "x" << "\t" << "y" << "\t" << "p" << "\t\t" << "*p" << endl;
	cout << "----------------------------------" << endl;
	cout << deepInstance->x << "\t" << deepInstance->y << "\t" << deepInstance->p << "\t" << *(deepInstance->p) << endl;
	cout << anotherDeepInstance->x << "\t" << anotherDeepInstance->y << "\t" << anotherDeepInstance->p << "\t" << *(anotherDeepInstance->p) << endl;

	cout << endl;

	deepInstance->x = 4;
	anotherDeepInstance->x = 6;
	cout << deepInstance->x << "\t" << deepInstance->y << "\t" << deepInstance->p << "\t" << *(deepInstance->p) << endl;
	cout << anotherDeepInstance->x << "\t" << anotherDeepInstance->y << "\t" << anotherDeepInstance->p << "\t" << *(anotherDeepInstance->p) << endl;

	cout << endl;
	
	*(deepInstance->p) = 10;
	cout << deepInstance->x << "\t" << deepInstance->y << "\t" << deepInstance->p << "\t" << *(deepInstance->p) << endl;
	cout << anotherDeepInstance->x << "\t" << anotherDeepInstance->y << "\t" << anotherDeepInstance->p << "\t" << *(anotherDeepInstance->p) << endl;

	delete deepInstance;
	deepInstance = nullptr;

	delete anotherDeepInstance;
	anotherDeepInstance = nullptr;

	cout << endl;
}

void makeDeepCopyWithCopyAssignmentOperator()
{
	cout << "Deep Copy - Copy Assignment Operator" << endl;
	DeepCopyClass* firstDeepInstance = new DeepCopyClass(3, 7, 9);
	DeepCopyClass* secondDeepInstance = new DeepCopyClass(1, 2, 3);

	cout << "x" << "\t" << "y" << "\t" << "p" << "\t\t" << "*p" << endl;
	cout << "----------------------------------" << endl;
	cout << firstDeepInstance->x << "\t" << firstDeepInstance->y << "\t" << firstDeepInstance->p << "\t" << *(firstDeepInstance->p) << endl;
	cout << secondDeepInstance->x << "\t" << secondDeepInstance->y << "\t" << secondDeepInstance->p << "\t" << *(secondDeepInstance->p) << endl;

	cout << endl;

	// Copy Assignment Operator '=' invokation
	//  Overloading the copy assignment operator is necessary
	//  in order to make a deep copy, i.e. copy of the data, not the address.
	*secondDeepInstance = *firstDeepInstance;
	
	cout << firstDeepInstance->x << "\t" << firstDeepInstance->y << "\t" << firstDeepInstance->p << "\t" << *(firstDeepInstance->p) << endl;
	cout << secondDeepInstance->x << "\t" << secondDeepInstance->y << "\t" << secondDeepInstance->p << "\t" << *(secondDeepInstance->p) << endl;

	cout << endl;

	secondDeepInstance->x = 6;
	cout << firstDeepInstance->x << "\t" << firstDeepInstance->y << "\t" << firstDeepInstance->p << "\t" << *(firstDeepInstance->p) << endl;
	cout << secondDeepInstance->x << "\t" << secondDeepInstance->y << "\t" << secondDeepInstance->p << "\t" << *(secondDeepInstance->p) << endl;

	cout << endl;

	*(secondDeepInstance->p) = 10;
	cout << firstDeepInstance->x << "\t" << firstDeepInstance->y << "\t" << firstDeepInstance->p << "\t" << *(firstDeepInstance->p) << endl;
	cout << secondDeepInstance->x << "\t" << secondDeepInstance->y << "\t" << secondDeepInstance->p << "\t" << *(secondDeepInstance->p) << endl;

	delete firstDeepInstance;
	firstDeepInstance = nullptr;

	// When doing a shallow copy of the 'DeepCopyClass'
	//  we are referring to the same address of 'p' in both instances.
	//  When we delete 'firstDeepInstance', the 'p' gets deallocated.
	//  When we delete 'secondDeepInstance', the 'p' points to the same address
	//  as 'firstDeepInstance' which is already deallocated.
	//  So when we try to deallocate data under an address which has already been deallocated
	//  we may experience undefined behavior.
	//  Therefore we set the pointer in the 'secondDeepInstance' to 'nullptr',
	//  which can be deallocated safely (from C++11 onwards).
	secondDeepInstance->p = nullptr;
	
	delete secondDeepInstance;
	secondDeepInstance = nullptr;
}
