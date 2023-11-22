#include <iostream>

#include <sstream>
#include <stack>
#include <vector>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}

    friend std::ostream& operator<<(std::ostream& out, const TreeNode& treeNode);
};

std::ostream& operator<<(std::ostream& out, const TreeNode& treeNode) {
    out << treeNode.data;
    return out;
}

class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    // Insert a value into the binary tree
    //  Original implementation
//    void insert(int value) {
//        root = insertRecursive(root, value);
//    }

    // Custom implementation
    void insert(int value) {
        TreeNode* insertedNode = new TreeNode(value);
        root = insertRecursive(root, &insertedNode);
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

    std::vector<int> inorderTraversal(std::vector<int>& sequence) {
        inorderRecursive(root, sequence);
        return sequence;
    }

    void inOrderTraversalIterative() {
        inorderIterative(root);
    }

    // crashes on 'inorderRecursive' call
//    std::string inorderTraversal() {
//        std::stringstream sequence;
//        inorderRecursive(root, sequence); // crash
//        return sequence.str();
//    }

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

    TreeNode* insertRecursive(TreeNode* node, TreeNode** insertedNode) {
        if (node == nullptr) {
            return *insertedNode;
        }

        if ( (*insertedNode)->data < node->data) {
            node->left = insertRecursive(node->left, insertedNode);
        }
        else if ( (*insertedNode)->data > node->data) {
            node->right = insertRecursive(node->right, insertedNode);
        }

        return node;
    }

    // ill-formed implementation which overwrites the root node
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

    // Traversing the tree in-order produces a sorted sequence
    void inorderRecursive(TreeNode* node) {
        if (node != nullptr) {
            inorderRecursive(node->left);  // process left node (child)
            std::cout << node->data << " ";     // process parent node
            inorderRecursive(node->right); // process right node (child)
        }
    }

    void inorderRecursive(TreeNode* node, std::vector<int>& sequence) {
        if (node != nullptr) {
            inorderRecursive(node->left, sequence);  // process left node (child)
            sequence.emplace_back(node->data);            // process parent node
            inorderRecursive(node->right, sequence); // process right node (child)
        }
    }

//    void inorderRecursive(TreeNode* node, std::stringstream& sequence) {
//        if (node != nullptr) {
//            inorderRecursive(node->left);  // process left node (child)
//            sequence << node->data << " ";     // process parent node
//            inorderRecursive(node->right); // process right node (child)
//        }
//    }

    void inorderIterative(TreeNode* node) {
        bool isNodeEmpty = node == nullptr;
        if (isNodeEmpty) {
            return;
        }

        std::stack<TreeNode*> nodes;
        nodes.push(node);

        // Progression
//        TreeNode* nextLeftNode = node->left;
//        if (nextLeftNode != nullptr) {
//            nodes.push(nextLeftNode);
//            nextLeftNode = nextLeftNode->left;
//        }
//        if (nextLeftNode != nullptr) {
//            nodes.push(nextLeftNode);
//            nextLeftNode = nextLeftNode->left;
//        }
//        if (nextLeftNode != nullptr) {
//            nodes.push(nextLeftNode);
//            nextLeftNode = nextLeftNode->left;
//        }

        bool areNodesPresent = !(nodes.empty() );
        while (areNodesPresent) {
            TreeNode* currentlyProcessedNode = nodes.top();
            TreeNode* nextLeftNode = currentlyProcessedNode->left;
            bool hasCurrentlyProcessedNodeLeftChild = nextLeftNode != nullptr;
            while (hasCurrentlyProcessedNodeLeftChild) {
                nodes.push(nextLeftNode);
                nextLeftNode = nextLeftNode->left;
                hasCurrentlyProcessedNodeLeftChild = nextLeftNode != nullptr;
            }

            // Process left child node
            currentlyProcessedNode = nodes.top();
            std::cout << *currentlyProcessedNode << " " << std::flush;
            nodes.pop();

            // Process parent node
            bool wasRootNodeProcessed = !(nodes.empty() );
            if (wasRootNodeProcessed) {
                currentlyProcessedNode = nodes.top();
                std::cout << *currentlyProcessedNode << " " << std::flush;
                nodes.pop();
            }

            // Process right child
            TreeNode* nextRightNode = currentlyProcessedNode->right;
            bool hasCurrentlyProcessedNodeRightChild = nextRightNode != nullptr;
            if (hasCurrentlyProcessedNodeRightChild) {
                nodes.push(nextRightNode);
            }

            areNodesPresent = !(nodes.empty() );
        }
    }

    void postOrderRecursive(TreeNode* node) {
        if (node != nullptr) {
            postOrderRecursive(node->left);  // process left node (child)
            postOrderRecursive(node->right); // process right node (child)
            delete node;                          // process parent node
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
    std::cout << '\n';
    tree.inorderTraversal();
    std::cout << std::endl;

    std::vector<int> sequence;
    std::vector<int> orderedSequenceByInOrderTraversal = tree.inorderTraversal(sequence);
    for (const int nodeData : orderedSequenceByInOrderTraversal) {
        std::cout << nodeData << ' ';
    }
    std::cout << '\n' << std::flush;

    tree.inOrderTraversalIterative();

    return 0;
}
