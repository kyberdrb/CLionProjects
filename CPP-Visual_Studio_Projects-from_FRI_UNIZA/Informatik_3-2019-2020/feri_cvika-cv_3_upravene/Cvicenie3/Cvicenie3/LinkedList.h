#pragma once

#include "Node.h"

class LinkedList {
public:
	LinkedList();
	~LinkedList();

	void add(int value);
	void removeNodeWithValue(int value);
	void showElementsValue() const;

private:
	Node* head{};
	Node* tail{};
};

