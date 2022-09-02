#include <list>
#include <memory>

#include "LinkedList.h"

int main(int argc, char* argv)
{
	//std::list<int> linkedList;

	//LinkedList list;
	std::unique_ptr<LinkedList> list(new LinkedList);

	list->add(3);
	list->showElementsValue();

	list->add(5);
	list->showElementsValue();

	list->add(8);
	list->showElementsValue();

	list->removeNodeWithValue(5);
	list->showElementsValue();

	list->removeNodeWithValue(8);
	list->showElementsValue();

	list->removeNodeWithValue(3);
	list->showElementsValue();

	return 0;
}