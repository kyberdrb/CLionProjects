#pragma once
class LinkedList
{
public:
	class Node
	{
	public:
		Node(int value, Node* left = nullptr, Node* right = nullptr) :
			m_value(value), m_left(left), m_right(right) {}
		int GetValue() const { return m_value; }
		void SetValue(int value) { m_value = value; }
		Node* GetLeft() const { return m_left; }
		void SetLeft(Node* left) { m_left = left; }
		Node* GetRight() const { return m_right; }
		void SetRight(Node* right) { m_right = right; }
	private:
		int m_value;
		Node* m_left;
		Node* m_right;
	};
	LinkedList();
	LinkedList(int size);
	~LinkedList();

	void Add(int value);
	void Delete(int value);
private:
	Node* m_head;
	Node* m_tail;
};

