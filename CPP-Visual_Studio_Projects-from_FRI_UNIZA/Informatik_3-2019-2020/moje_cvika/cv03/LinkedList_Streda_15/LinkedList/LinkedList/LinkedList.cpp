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

void LinkedList::removeByValue(int value) {
	if (head == nullptr) {
		return;
	}

	Node* currentNode = head;
	Node* previousNode{};
	while (currentNode != nullptr) {
		if (currentNode->getNodeValue() == value) {
			break;
		}
		previousNode = currentNode;
		currentNode = currentNode->getRightNeighbor();
	}

	if (currentNode != nullptr) {
		if (currentNode == head) {
			head = head->getRightNeighbor();
		}
		else {
			previousNode->setRightNeighbor(currentNode->getRightNeighbor());
		}

		if (currentNode == tail) {
			tail = previousNode;
		}

		delete currentNode;
		currentNode = nullptr;
	}
}

void LinkedList::showElementsValue() {
	Node* currentNode = head;
	while (currentNode != nullptr) {
		std::cout << currentNode->getNodeValue() << std::endl;
		currentNode = currentNode->getRightNeighbor();
	}
	std::cout << std::endl;
}

LinkedList::~LinkedList() {
	Node* currentNode = head;
	while (currentNode != nullptr) {
		Node* tempNode = currentNode;
		currentNode = tempNode->getRightNeighbor();
		delete tempNode;
	}
}
