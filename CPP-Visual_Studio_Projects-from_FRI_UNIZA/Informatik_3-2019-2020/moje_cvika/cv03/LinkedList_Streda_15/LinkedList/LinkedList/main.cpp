#include "LinkedList.h"

int main() {
	LinkedList list;

	list.add(3);
	list.showElementsValue();

	list.add(5);
	list.showElementsValue();

	list.add(8);
	list.showElementsValue();

	list.removeByValue(5);
	list.showElementsValue();

	list.removeByValue(8);
	list.showElementsValue();

	list.removeByValue(3);
	list.showElementsValue();

	return 0;
}