#include <iostream>

#include "LinkedList.h"

LinkedList::LinkedList() {}

void LinkedList::add(int value) {
	if (head == nullptr) {
		head = new Node(value);
		tail = head;
	} else {
		Node* newNode = new Node(value);
		tail->setRightNeighbor(newNode);
		tail = tail->getRightNeighbor();
	}
}

void LinkedList::removeNodeWithValue(int value) {
	if (head == nullptr) {
		return;
	}

	Node* currentNode = head;
	Node* previousNode{};
	while (currentNode != nullptr) {
		if (currentNode->getValue() == value) {
			break;
		}

		previousNode = currentNode;
		currentNode = currentNode->getRightNeighbor();
	}

	if (currentNode != nullptr)	{
		if (currentNode == head) {
			head = head->getRightNeighbor();
		} else {
			previousNode->setRightNeighbor(currentNode->getRightNeighbor());
		}

		if (currentNode == tail) {
			tail = previousNode;
		}

		delete currentNode;
		currentNode = nullptr;
	}
}

void LinkedList::showElementsValue() const {
	Node* currerntNode = head;
	while (currerntNode != nullptr) {
		std::cout << currerntNode->getValue() << std::endl;
		currerntNode = currerntNode->getRightNeighbor();
	}

	std::cout << std::endl;
}

LinkedList::~LinkedList() {
	Node* currentNode = head;
	while (currentNode) {
		Node* tempNode = currentNode;
		currentNode = currentNode->getRightNeighbor();
		delete tempNode;
	}
}
