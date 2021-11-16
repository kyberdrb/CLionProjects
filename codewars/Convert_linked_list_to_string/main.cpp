#include <iostream>
#include "Node.h"

#include <string>
#include <sstream>

std::string stringify(Node* list)
{
    std::stringstream listAsString;
    Node* node = list;

    while (node != nullptr)
    {
        listAsString << node->data << " -> ";
        node = node->next;
    }
    listAsString << "nullptr";
    return listAsString.str();
}

int main() {
    std::cout << stringify(nullptr) << std::endl;
    std::cout << stringify(new Node(1, new Node(2, new Node(3)))) << std::endl;
    return 0;
}