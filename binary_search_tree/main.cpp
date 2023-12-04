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
        inorderIterative_1(root);
    }

    // https://www.enjoyalgorithms.com/blog/iterative-binary-tree-traversals-using-stack
    void inOrderTraversalIterative_2_with_continue() {
        inorderIterative_2_with_continue(root);
    }

    // https://www.enjoyalgorithms.com/blog/iterative-binary-tree-traversals-using-stack
    void inOrderTraversalIterative_2_with_else() {
        inorderIterative_2_with_else(root);
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

    void inorderIterative_1(TreeNode* node) {
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

            // Push the right child of the currently removed node to the stack            //  useful when the parent node only has right child
            TreeNode* rightChildOfCurrentlyRemovedNode = currentlyProcessedNode->right;
            bool hasCurrentlyRemovedNodeRightChild = rightChildOfCurrentlyRemovedNode != nullptr;
            if (hasCurrentlyRemovedNodeRightChild) {
                nodes.push(rightChildOfCurrentlyRemovedNode);
                continue;
            }

            // Process parent node
            bool isRootOrParentNodeWaitingForProcessing = !(nodes.empty() );
            if (isRootOrParentNodeWaitingForProcessing) {
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

    // https://www.enjoyalgorithms.com/blog/iterative-binary-tree-traversals-using-stack
    void inorderIterative_2_with_continue(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        std::stack<TreeNode*> nodes;
        TreeNode* currentNode = node;

        while (!(nodes.empty() ) || currentNode != nullptr) {
            if (currentNode != nullptr) {
                nodes.push(currentNode);
                currentNode = currentNode->left;
                continue;
            }

            currentNode = nodes.top();
            nodes.pop();
            std::cout << currentNode->data << " ";
            currentNode = currentNode->right;
        }
    }

    // https://www.enjoyalgorithms.com/blog/iterative-binary-tree-traversals-using-stack
    void inorderIterative_2_with_else(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        std::stack<TreeNode*> nodes;
        TreeNode* currentNode = node;

        while ( !(nodes.empty() ) || currentNode != nullptr ) {
            if (currentNode != nullptr) {
                nodes.push(currentNode);
                currentNode = currentNode->left;
            } else {
                currentNode = nodes.top();
                nodes.pop();
                std::cout << currentNode->data << " ";
                currentNode = currentNode->right;
            }
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

    // Test tree 1
//    tree.insert(10);
//    tree.insert(5);
//    tree.insert(15);
//    tree.insert(3);
//    tree.insert(7);
//             10
//            /  \
//           5    15
//          / \
//         3   7

    // Test tree 2
//    tree.insert(7);
//    tree.insert(3);
//    tree.insert(11);
//    tree.insert(5);
//    tree.insert(9);
//    tree.insert(13);
//             7
//            /  \
//           3    11
//            \   / \
//             5 9   13

    // Test tree 3
//    tree.insert(7);
//    tree.insert(3);
//    tree.insert(11);
//    tree.insert(5);
//    tree.insert(9);
//             7
//            /  \
//           3    11
//            \   /
//             5 9

    // Test tree 4
//    tree.insert(7);
//    tree.insert(3);
//    tree.insert(5);
//    tree.insert(1);
//    tree.insert(0);
//    tree.insert(2);
//    tree.insert(11);
//    tree.insert(9);
//    tree.insert(10);
//    tree.insert(13);
//    tree.insert(15);
//             7
//            /  \
//           3    11
//          / \   / \
//         1   5 9   13
//        / \     \    \
//       0   2     10   15

    // Test tree 5
//    tree.insert(7);
//    tree.insert(3);
//    tree.insert(5);
//    tree.insert(1);
//    tree.insert(0);
//    tree.insert(2);
//    tree.insert(4);
//    tree.insert(6);
//    tree.insert(11);
//    tree.insert(9);
//    tree.insert(10);
//    tree.insert(13);
//    tree.insert(15);
//    tree.insert(8);
//    tree.insert(14);
//               _____7_____
//              /           \
//             3             11
//          /    \        /      \
//         1      5      9        13
//        / \    / \    / \      /  \
//       0   2  4   6  8   10  14    15

    // Test tree 6
    tree.insert(7);
    tree.insert(3);
    tree.insert(5);
    tree.insert(1);
    tree.insert(2);
    tree.insert(6);
    tree.insert(11);
    tree.insert(9);
    tree.insert(10);
    tree.insert(13);
    tree.insert(15);
//               _____7_____
//              /           \
//             3             11
//          /    \        /      \
//         1      5      9        13
//          \      \      \         \
//           2      6      10        15

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
    std::cout << '\n' << std::flush;

    tree.inOrderTraversalIterative_2_with_continue();
    std::cout << '\n' << std::flush;

    tree.inOrderTraversalIterative_2_with_else();
    std::cout << '\n' << std::flush;

    return 0;
}
