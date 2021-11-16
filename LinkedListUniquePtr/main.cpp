#include <iostream>
#include <memory>

// https://stackoverflow.com/a/42543929

struct Node {
    std::unique_ptr<Node> next;

    void addNode(std::unique_ptr<Node> node) {
        next = std::move(node);
    }

    //~Node() {
    //    next.release();
    //}
};

int main() {
    std::unique_ptr<Node> list_head;

    //list_head->next = std::make_unique<Node>();
    //std::unique_ptr<Node> node = std::make_unique<Node>();
    //list_head->addNode(std::move(node));

    // I need a custom deleter for this unique_ptr in order to add new nodes to the LinkedList - otherwise it crashes with memory leak

    //list_head->next.release();

    std::cout << std::endl;

    return 0;
}