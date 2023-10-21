#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    // Insert a value into the binary tree
    void insert(int value) {
        root = insertRecursive(root, value);
    }

//    void insert(int value) {
//        if (this->root == nullptr) {
//            this->root = new TreeNode(value);
//            return;
//        }
//
//        insertRecursive(&root, value);
//    }

//    void insert(int value) {
//        auto insertedNode = new TreeNode(value);
//
//        if(this->root == nullptr) {
//            this->root = insertedNode;
//            return;
//        }
//
//        root = insertRecursive(root, value);
//    }

    // In-order traversal of the binary tree
    void inorderTraversal() {
        inorderRecursive(root);
    }

    // Destructor to release memory
    ~BinaryTree() {
        postOrderRecursive(root);
    }

private:
    TreeNode* root;

    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

//    void insertRecursive(TreeNode** node, int value) {
//        if (*node == nullptr) {
//            *node = new TreeNode(value);
//            return;
//        }
//
//        if (value < (*node)->data) {
//            *node = (*node)->left;
//        } else if (value > (*node)->data) {
//            *node = (*node)->right;
//        }
//
//        insertRecursive(node, value);
//    }

    void inorderRecursive(TreeNode* node) {
        if (node != nullptr) {
            inorderRecursive(node->left);
            std::cout << node->data << " ";
            inorderRecursive(node->right);
        }
    }

    void postOrderRecursive(TreeNode* node) {
        if (node != nullptr) {
            postOrderRecursive(node->left);
            postOrderRecursive(node->right);
            delete node;
        }
    }
};

int main() {
    BinaryTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    std::cout << "In-order traversal: ";
    tree.inorderTraversal();
    std::cout << std::endl;

    return 0;
}
