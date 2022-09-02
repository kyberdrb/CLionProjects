#include "LinkedList.h"

LinkedList::LinkedList() : m_head(nullptr), m_tail(nullptr)
{

}

LinkedList::LinkedList(int size)
{

}

LinkedList::~LinkedList()
{
	Node* cur = m_head;
	while (cur)
	{
		Node* temp = cur;
		cur = cur->GetRight();
		delete temp;
	}
}

void LinkedList::Add(int value)
{
	if (m_head == nullptr)
	{
		m_head = new Node(value);
		m_tail = m_head;
	}
	else
	{
		Node* temp = new Node(value, m_tail);
		m_tail->SetRight(temp);
		m_tail = temp;
	}
}

void LinkedList::Delete(int value)
{
	Node* cur = m_head;
	if (!cur)
		return;
	do
	{
		if (cur->GetValue() == value)
			break;
	} while (cur = cur->GetRight());
	if (cur)
	{
		if (cur == m_head)
		{
			m_head = nullptr;
			m_tail = nullptr;
		}
		else if (cur == m_tail)
		{
			cur->GetLeft()->SetRight(nullptr);
			m_tail = cur->GetLeft();
		}
		else
		{
			cur->GetLeft()->SetRight(cur->GetRight());
			cur->GetRight()->SetLeft(cur->GetLeft());
		}
		delete cur;
	}
}
