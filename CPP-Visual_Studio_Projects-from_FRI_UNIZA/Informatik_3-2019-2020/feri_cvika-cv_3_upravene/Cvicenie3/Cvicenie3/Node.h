#pragma once

class Node {
public:
	Node(int value, Node* right = nullptr) :
		nodeValue(value), rightNeighbor(right) {}

	int getValue() const { 
		return nodeValue;
	}

	void setValue(int value) {
		nodeValue = value;
	}

	Node* getRightNeighbor() const {
		return rightNeighbor;
	}

	void setRightNeighbor(Node* right) {
		rightNeighbor = right; 
	}

private:
	int nodeValue;
	Node* rightNeighbor;
};
