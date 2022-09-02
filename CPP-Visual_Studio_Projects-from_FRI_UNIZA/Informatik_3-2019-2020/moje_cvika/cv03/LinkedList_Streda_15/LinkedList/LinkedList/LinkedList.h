#pragma once

#include "Node.h"

class LinkedList
{
private:
	Node* head = nullptr;
	Node* tail = nullptr;

public:
	LinkedList();

	void add(int value);
	void removeByValue(int value);
	void showElementsValue();

	~LinkedList();
};

