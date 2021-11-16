#pragma once

class Node
{
public:
    int data;
    Node* next;

    Node(int data, Node* next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};