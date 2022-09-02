#include <iostream>

#include "Triangle.h"
#include <vector>
#include <memory>

int main()
{
	Triangle* t1 = new Triangle();
	Triangle* t2 = new Triangle(2, 4, 5);
	Triangle* t3 = new Triangle(5, 1, 1);

	std::vector<Triangle*> triangles;
	triangles.emplace_back(t1);
	triangles.emplace_back(t2);
	triangles.emplace_back(t3);

	std::cout << "number of triangles: " << triangles.size() << std::endl;

	std::cout << std::endl;

	for (int i = 0; i < triangles.size(); i++)
	{
		std::cout << "triangle:\t" << *triangles[i] << std::endl;
	}

	std::cout << std::endl;
	
	// Iterator stores an address the of the container's element
	//  which is in our case, by the generic parameter,
	//  the pointer (or an address) to Triangle 'Triangle*'
	//  therefore we need to dereference the iterating variable 'triangle' twice.
	for (
			std::vector<Triangle*>::iterator triangle = triangles.begin(); 
			triangle != triangles.end(); 
			++triangle)
	{
		std::cout << "triangle:\t" << **triangle << std::endl;
	}

	std::cout << std::endl;

	for (
		auto triangle = triangles.begin();
		triangle != triangles.end();
		++triangle)
	{
		std::cout << "triangle:\t" << **triangle << std::endl;
	}

	std::cout << std::endl;

	for (auto triangle : triangles)
	{
		std::cout << "triangle:\t" << *triangle << std::endl;
	}

	std::cout << std::endl;

	for (auto const triangle : triangles)
	{
		std::cout << "triangle:\t" << *triangle << std::endl;
	}

	for (auto triangle : triangles)
	{
		delete triangle;
		triangle = nullptr;
	}

	std::cout << std::endl;
	
	std::unique_ptr<Triangle> t13(std::make_unique<Triangle>(5, 7, 9));
	std::unique_ptr<Triangle> t14(std::make_unique<Triangle>(6, 8, 10));
	std::unique_ptr<Triangle> t15(std::make_unique<Triangle>(7, 9, 11));

	// We need to move the unique pointers
	//  beacuse copying the unique pointer is forbidden.
	//  If we copied a unique pointer, it would no longer be unique.
	std::vector<std::unique_ptr<Triangle>> unique_triangles;
	unique_triangles.emplace_back(std::move(t13));
	unique_triangles.emplace_back(std::move(t14));
	unique_triangles.emplace_back(std::move(t15));

	// `auto&` means that we don't want to copy
	//  the iterated element.
	//  We can work with the original element by accessing it by reference.
	//  When we access the element as a reference,
	//  only one copy of the element is present in the memory.
	for (auto& triangle : unique_triangles)
	{
		std::cout << "triangle:\t" << *triangle << std::endl;
	}

	std::cout << std::endl;

	// Iterate through the container by using rvalue references
	for (auto&& triangle : unique_triangles)
	{
		std::cout << "triangle:\t" << *triangle << std::endl;
	}

	// We don't need to manually delete the unique pointer.
	//  Unique pointers conform to the RAII principle.
	//  Therefore they will deallocate at the end of the scope.
	//  No memory leaks ;)

	std::cout << std::endl;
}
