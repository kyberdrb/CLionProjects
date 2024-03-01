#include <iostream>
#include <stack>
#include <vector>

// Custom data structure
class MyContainer {
private:
    std::vector<int> data;

public:
    // Constructor
    MyContainer(std::initializer_list<int> values) : data(values) {}

    // Iterator class
    class Iterator {
    private:
        std::vector<int>::iterator current;

    public:
        Iterator(std::vector<int>::iterator ptr) : current(ptr) {}

        // Dereference operator
        int& operator*() {
            return *current;
        }

        // Increment operator
        Iterator& operator++() {
            ++current;
            return *this;
        }

        // Not equal operator
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    // Begin function (returns iterator to start)
    Iterator begin() {
        return Iterator(data.begin());
    }

    // End function (returns iterator to end)
    Iterator end() {
        return Iterator(data.end());
    }
};

// ==============================================================

// Iterator Design Pattern for custom Binary Tree
//  Inspired by OpenAI ChatGPT

// Custom binary tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Iterator for binary tree
class TreeIterator {
private:
    std::stack<TreeNode*> stack;

public:
    TreeIterator(TreeNode* root) {
        pushLeftNodes(root);
    }

    int operator*() const {
        return stack.top()->value;
    }

    TreeIterator& operator++() {
        TreeNode* node = stack.top();
        stack.pop();
        if (node->right) {
            pushLeftNodes(node->right);
        }
        return *this;
    }

    bool operator!=(const TreeIterator& other) const {
        return !stack.empty() || !other.stack.empty();
    }

private:
    void pushLeftNodes(TreeNode* node) {
        while (node) {
            stack.push(node);
            node = node->left;
        }
    }
};

// Custom binary tree class
class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertHelper(root, value);
    }

    TreeIterator begin() {
        return TreeIterator(root);
    }

    TreeIterator end() {
        return TreeIterator(nullptr);
    }

private:
    TreeNode* insertHelper(TreeNode* node, int value) {
        if (!node) {
            return new TreeNode(value);
        }
        if (value < node->value) {
            node->left = insertHelper(node->left, value);
        } else if (value > node->value) {
            node->right = insertHelper(node->right, value);
        }
        return node;
    }
};

int main() {
    std::cout << "for-each iteration through custom STL based data structure - implicit or explicit data structure" << std::endl;
    MyContainer container = {1, 2, 3, 4, 5};

    // Using range-based for loop to iterate over elements
    for (int value : container) {
        std::cout << value << " ";
    }

    std::cout << "\n\n" << std::flush;
    std::cout << "for-each iteration through custom binary tree - explicit data structure" << std::endl;

    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    // Using range-based for loop to iterate over elements of binary tree
    for (int value : tree) {
        std::cout << value << " ";
    }

    return 0;
}
