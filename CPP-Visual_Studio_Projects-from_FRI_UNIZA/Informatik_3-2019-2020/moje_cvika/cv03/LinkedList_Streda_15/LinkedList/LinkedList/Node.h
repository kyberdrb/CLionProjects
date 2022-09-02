#pragma once

class Node {
private:
	int nodeValue = 0;
	Node* rightNeighbor = nullptr;

public:
	Node(int value, Node* right = nullptr)
		: nodeValue(value),
		rightNeighbor(right) {}

	int getNodeValue() {
		return nodeValue;
	}

	void setNodeValue(int newValue) {
		nodeValue = newValue;
	}

	Node* getRightNeighbor() {
		return rightNeighbor;
	}

	void setRightNeighbor(Node* newRightNeighbor) {
		rightNeighbor = newRightNeighbor;
	}
};