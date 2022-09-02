#include <iostream>

#include "Triangle.h"

int main()
{
	Triangle* t1 = new Triangle();
	std::cout << "t1:\t" << t1->printSides() << t1->isConstructible() << std::endl;
	delete t1;

	std::cout << std::endl;
	
	Triangle* t2 = new Triangle(2, 4, 5);
	std::cout << "t2:\t" << t2->printSides() << t2->isConstructible() << std::endl;
	delete t2;

	std::cout << std::endl;
	
	Triangle* t3 = new Triangle(5, 1, 1);
	std::cout << "t3:\t" << t3->printSides() << t3->isConstructible() << std::endl;
	delete t3;

	std::cout << std::endl;
	
	// copy constructor on stack
	Triangle t4(2, 3, 4);
	Triangle t5 = t4;
	std::cout << "t4:\t" << t4.printSides() << t4.isConstructible() << std::endl;
	std::cout << "t5:\t" << t5.printSides() << t5.isConstructible() << std::endl;

	std::cout << std::endl;
	
	// copy constructor on heap
	Triangle* t6 = new Triangle(4, 5, 6);
	Triangle* t7 = new Triangle(*t6);
	std::cout << "t6:\t" << t6->printSides() << t6->isConstructible() << std::endl;
	std::cout << "t7:\t" << t7->printSides() << t7->isConstructible() << std::endl;
	delete t6;
	delete t7;

	std::cout << std::endl;
	
	// copy assignment operator on stack
	Triangle t8(2, 3, 4);
	Triangle t9(5, 6, 7);
	std::cout << "t8:\t" << t8.printSides() << t8.isConstructible() << std::endl;
	std::cout << "t9:\t" << t9.printSides() << t9.isConstructible() << std::endl;
	t9 = t8;
	std::cout << "t8:\t" << t8.printSides() << t8.isConstructible() << std::endl;
	std::cout << "t9:\t" << t9.printSides() << t9.isConstructible() << std::endl;

	std::cout << std::endl;
	
	// copy assignment operator on heap
	Triangle* t10 = new Triangle(4, 5, 6);
	Triangle* t11 = new Triangle(7, 8, 9);
	std::cout << "t10:\t" << t10->printSides() << t10->isConstructible() << std::endl;
	std::cout << "t11:\t" << t11->printSides() << t11->isConstructible() << std::endl;
	*t10 = *t11;
	//t10->operator=(*t11);
	std::cout << "t10:\t" << t10->printSides() << t10->isConstructible() << std::endl;
	std::cout << "t11:\t" << t11->printSides() << t11->isConstructible() << std::endl;
	delete t10;
	delete t11;

	std::cout << std::endl;
	
	// stream insertion operator overload
	Triangle* t12 = new Triangle(4, 4, 3);
	std::cout << "t12:\t" << *t12 << std::endl;
	delete t12;

	
	
	std::unique_ptr<Triangle> t13(std::make_unique<Triangle>(5,7,9));
	std::cout << "t13:\t" << *t13 << std::endl;

	std::cout << std::endl;
}
