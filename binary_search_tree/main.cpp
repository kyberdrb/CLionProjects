#include <iostream>

#include <sstream>
#include <stack>
#include <vector>
#include <unordered_set>

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
    void inOrderTraversalRecursive() {
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
//    std::string inOrderTraversalRecursive() {
//        std::stringstream sequence;
//        inorderRecursive(root, sequence); // crash
//        return sequence.str();
//    }

    void postOrderTraversalRecursive() const {
        postOrderRecursive(root);
    }

    void postOrderTraversalIterative_twoStack() const {
        //postOrderIterative_1_MY_BROKEN_IMPLEMENTATION(root);
        postOrderIterative_twoStack(root);
    }

    void postOrderTraversalIterative_singleStack_1() const {
        postOrderIterative_singleStack_1(root);
    }

    std::vector<std::reference_wrapper<int>> postOrderTraversalIterative_singleStack_1_vector() const {
        return postOrderIterative_singleStack_1_vector(root);
    }

    void postOrderTraversalIterative_singleStack_2() const {
        postOrderIterative_singleStack_2(root);
    }

    std::vector<std::reference_wrapper<const int>> postOrderTraversalIterative_singleStack_2_vector() const {
        return postOrderIterative_singleStack_2_vector(root);
    }

    void preOrderTraversalIterative_singleStack_1() const {
        preOrderIterative_singleStack_1(root);
    }

    void preOrderTraversalIterative_singleStack_1_withoutDuplicates() const {
        preOrderIterative_singleStack_1_withoutDuplicates(root);
    }

    void preOrderTraversalIterative_singleStack_1_doubleLoop() const {
        preOrderTraversalIterative_singleStack_1_withoutDuplicates_doubleLoopOnly(root);
    }

    std::vector<std::reference_wrapper<int>> preOrderTraversalIterative_singleStack_1_doubleLoop_vector() const {
        return preOrderTraversalIterative_singleStack_1_withoutDuplicates_doubleLoopOnly_vector(root);
    }

    // Destructor to release memory
    ~BinaryTree() {
        postOrderRecursiveNoOutput(root);
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

    void postOrderRecursiveNoOutput(TreeNode* node) {
        if (node != nullptr) {
            postOrderRecursiveNoOutput(node->left);  // process left node (child)
            postOrderRecursiveNoOutput(node->right); // process right node (child)
            delete node;                          // process parent node
        }
    }

    void postOrderRecursive(TreeNode* node) const {
        if (node != nullptr) {
            postOrderRecursive(node->left);
            postOrderRecursive(node->right);
            std::cout << *node << " ";
        }
    }

    void postOrderIterative_1_MY_BROKEN_IMPLEMENTATION(TreeNode* node) const {
        if (node == nullptr) {
            return;
        }

        std::stack<TreeNode*> nodes;
        nodes.push(node);

        while (!nodes.empty() ) {
            TreeNode* currentlyProcessedNode = nodes.top();

            while (currentlyProcessedNode->left != nullptr) {
                nodes.push(currentlyProcessedNode->left);
                currentlyProcessedNode = currentlyProcessedNode->left;
            }

            if (currentlyProcessedNode->right != nullptr) {
                nodes.push(currentlyProcessedNode->right);
                continue;
            }

            std::cout << currentlyProcessedNode->data << " " << std::flush;
            nodes.pop();
            currentlyProcessedNode = nodes.top();
            std::cout << currentlyProcessedNode->data << " " << std::flush;
            nodes.pop();
        }

        /*
         * if the node doesn't have a left child and a right child and is a left child
         *     process node
         *     pop it from the stack
         *
         * if the node doesn't have a left child and a right child and is a right child
         *     process node
         *     pop it from the stack
         *     process node again - its parent
         *     pop it from the stack
         */
    }

    // https://www.enjoyalgorithms.com/blog/iterative-binary-tree-traversals-using-stack
    void postOrderIterative_twoStack(TreeNode* node) const {
        if (node == nullptr) {
            return;
        }

        std::stack<TreeNode*> nodes;
        std::stack<TreeNode*> rightChildren;
        TreeNode* currentlyProcessedNode = node;

        while (!(nodes.empty()) || currentlyProcessedNode != nullptr) {
            // pushing
            if (currentlyProcessedNode != nullptr) {
                if (currentlyProcessedNode->right != nullptr) {
                    rightChildren.push(currentlyProcessedNode->right);
                }

                nodes.push(currentlyProcessedNode); // might be before
                currentlyProcessedNode = currentlyProcessedNode->left;
            }
            // backtracking
            else {
                currentlyProcessedNode = nodes.top();

                if ( !(rightChildren.empty() ) && (currentlyProcessedNode->right == rightChildren.top() ) ) {
                    currentlyProcessedNode = rightChildren.top();
                    rightChildren.pop();
                }
                else {
                    std::cout << currentlyProcessedNode->data << " " << std::flush;
                    nodes.pop();
                    currentlyProcessedNode = nullptr;
                }
            }
        }
    }

    // https://www.enjoyalgorithms.com/blog/iterative-binary-tree-traversals-using-stack
    void postOrderIterative_singleStack_1(TreeNode* node) const {
        if (node == nullptr) { // condition can be ommitted because the condition in while loop contains the check for nullptr
            return;
        }

        std::stack<TreeNode*> nodes;
        TreeNode* previousNode = nullptr;

        while ( (node != nullptr) || !(nodes.empty() ) ) {
            // pushing
            if (node != nullptr) {
                nodes.push(node); // might be before
                node = node->left;
            }

            // backtracking
            else {
                TreeNode* currentlyProcessedNode = nodes.top();
                // traverse right subtree
                //  when the right child of current node exists - to prevent unnecessary operation
                //  AND
                //  when the right child of current node is different from the previous node - to prevent infinite loop of pushing the leaf right child with each backtracking
                if ( (currentlyProcessedNode->right != nullptr) && (currentlyProcessedNode->right != previousNode) ) {
                    node = currentlyProcessedNode->right;
                }
                // process node
                else {
                    std::cout << currentlyProcessedNode->data << " " << std::flush;
                    previousNode = currentlyProcessedNode;
                    nodes.pop();
                }
            }
        }
    }

    std::vector<std::reference_wrapper<int>> postOrderIterative_singleStack_1_vector(const TreeNode* const node) const {
        std::vector<std::reference_wrapper<int>> outputNodes;

        std::stack<TreeNode*> nodes;
        TreeNode* previousNode = nullptr;
        auto assignableNode = const_cast<TreeNode*>(node);

        bool doesNodeExist = (node != nullptr);
        bool areNodesLeftToProcessing = !(nodes.empty() );
        while (doesNodeExist || areNodesLeftToProcessing) {
            // pushing
            if (doesNodeExist) {
                nodes.push(const_cast<TreeNode*>(assignableNode) ); // might be before
                assignableNode = assignableNode->left;
                updateConditionVariables(assignableNode, nodes, doesNodeExist, areNodesLeftToProcessing);
                continue;
            }

            // backtracking
            TreeNode* currentlyProcessedNode = nodes.top();
            // traverse right subtree
            bool doesRightChildOfCurrentNodeExist = currentlyProcessedNode->right != nullptr; // to prevent unnecessary operation by
            bool isRightChildOfCurrentNodeDifferentFromPreviousNode = currentlyProcessedNode->right != previousNode; // to prevent infinite loop by pushing the same leaf right child with each backtracking
            if (doesRightChildOfCurrentNodeExist && isRightChildOfCurrentNodeDifferentFromPreviousNode) {
                assignableNode = currentlyProcessedNode->right;
                updateConditionVariables(assignableNode, nodes, doesNodeExist, areNodesLeftToProcessing);
                continue;
            }

            // process node
            outputNodes.push_back(currentlyProcessedNode->data);
            previousNode = currentlyProcessedNode;
            nodes.pop();
            updateConditionVariables(assignableNode, nodes, doesNodeExist, areNodesLeftToProcessing);
        }

        return outputNodes;
    }

    void updateConditionVariables(
            const TreeNode* const& node,
            const std::stack<TreeNode*>& nodes,
            bool& doesNodeExist,
            bool& areNodesLeftToProcessing) const
    {
        doesNodeExist = (node != nullptr);
        areNodesLeftToProcessing = !(nodes.empty() );
    }

    void postOrderIterative_singleStack_2(TreeNode* node) const {
        if (node == nullptr) {
            return;
        }

        std::stack<TreeNode*> nodes;
        std::unordered_set<TreeNode*> visitedNodes;
        TreeNode* currentNode = node;

        while (!nodes.empty() || currentNode != nullptr) {
            // pushing
            if (currentNode != nullptr) {
                if (visitedNodes.count(currentNode) > 0) {
                    std::cout << currentNode->data << " ";
                    currentNode = nullptr;
                }
                else { // pushing
                    nodes.push(currentNode);

                    if (currentNode->right != nullptr) {
                        nodes.push(currentNode->right);
                    }

                    visitedNodes.insert(currentNode);
                    currentNode = currentNode->left;
                }
            }
            // backtracking
            else {
                currentNode = nodes.top();
                nodes.pop();
            }
        }
    }

    std::vector<std::reference_wrapper<const int>> postOrderIterative_singleStack_2_vector(const TreeNode* const node) const {
        std::vector<std::reference_wrapper<const int>> outputVector;
        std::stack<const TreeNode*> nodes;
        std::unordered_set<const TreeNode*> visitedNodes;
        const TreeNode* currentNode = node;

        bool areNodesLeftToProcess = !nodes.empty();
        bool doesNodeExist = currentNode != nullptr;
        while (areNodesLeftToProcess || doesNodeExist) {

            if (currentNode != nullptr) {
                bool wasNodeVisited = visitedNodes.count(currentNode) == 1; // if the node address is present in the 'std::set', it will be
                                                                            // present there in the 'std::set' only once by definition
                if (wasNodeVisited) { // pushing
                    outputVector.push_back(currentNode->data);
                    currentNode = nullptr;
                    updateConditionalVariablesPostOrder_singleStack2(nodes, currentNode, areNodesLeftToProcess, doesNodeExist);
                    continue;
                }

                // pushing
                nodes.push(currentNode);

                if (currentNode->right != nullptr) {
                    nodes.push(currentNode->right);
                }

                visitedNodes.insert(currentNode);
                currentNode = currentNode->left;
                updateConditionalVariablesPostOrder_singleStack2(nodes, currentNode, areNodesLeftToProcess, doesNodeExist);
                continue;
            }

            // backtracking
            currentNode = nodes.top();
            nodes.pop();
            updateConditionalVariablesPostOrder_singleStack2(nodes, currentNode, areNodesLeftToProcess, doesNodeExist);
        }

        return outputVector;
    }

    void updateConditionalVariablesPostOrder_singleStack2(
            const std::stack<const TreeNode*>& nodes,
            const TreeNode*& currentNode,
            bool& areNodesLeftToProcess,
            bool& doesNodeExist) const
    {
        areNodesLeftToProcess = !(nodes.empty() );
        doesNodeExist = currentNode != nullptr;
    }

    void postOrderIterative_singleStack_BROKEN(TreeNode* node) const {
        if (node == nullptr) {
            return;
        }

        std::stack<TreeNode*> nodes;
        std::stack<TreeNode*> rightChildren;
        TreeNode* currentlyProcessedNode = node;

        // pushing
        while (currentlyProcessedNode != nullptr) {
            nodes.push(currentlyProcessedNode);
            currentlyProcessedNode = currentlyProcessedNode->left;
        }

        // backtracking
        TreeNode* previousNode = nullptr;
        bool wasRightChildVisited = false;

        while (!(nodes.empty())) {
            currentlyProcessedNode = nodes.top();

            if (currentlyProcessedNode->right != nullptr && !(wasRightChildVisited)) {
                currentlyProcessedNode = currentlyProcessedNode->left;
                wasRightChildVisited = true;
            } else {
                std::cout << currentlyProcessedNode->data << " " << std::flush;
                nodes.pop();
                wasRightChildVisited = false;
                previousNode = currentlyProcessedNode;
                currentlyProcessedNode = nullptr;
            }
        }
    }

    void preOrderIterative_singleStack_1(TreeNode* node) const {
        std::stack<TreeNode*> nodes;
        TreeNode* currentNode = node;

//        std::cout << currentNode->data << " ";
//        currentNode = currentNode->left;
//        std::cout << currentNode->data << " ";
//        currentNode = currentNode->left;
//        std::cout << currentNode->data << " ";
//        currentNode = currentNode->right;
//        std::cout << currentNode->data << " ";
// ... but how do I get back to the right children/nodes?

        while (currentNode != nullptr) {
            std::cout << currentNode->data << " " << std::flush;

            if (currentNode->right != nullptr) {
                nodes.push(currentNode->right);
            }

            currentNode = currentNode->left;
        }

        while (!nodes.empty()) {
            currentNode = nodes.top();
            nodes.pop();
            while (currentNode != nullptr) {
                std::cout << currentNode->data << " " << std::flush;

                if (currentNode->right != nullptr) {
                    nodes.push(currentNode->right);
                }

                currentNode = currentNode->left;
            }
        }
    }

    void preOrderIterative_singleStack_1_withoutDuplicates(TreeNode* node) const {
        std::stack<TreeNode*> nodes;
        TreeNode* currentNode = node;

        processLeftSubtree_preorderTraversal(currentNode, nodes);

        bool areNodesLeftToProcess = !nodes.empty();
        while (areNodesLeftToProcess) {
            currentNode = nodes.top();
            nodes.pop();
            processLeftSubtree_preorderTraversal(currentNode, nodes);
            areNodesLeftToProcess = !nodes.empty();
        }
    }

    void processLeftSubtree_preorderTraversal(const TreeNode* const currentNode, std::stack<TreeNode*>& nodes) const {
        TreeNode* mutableNode = const_cast<TreeNode* const>(currentNode);
        bool doesCurrentNodeExist = mutableNode != nullptr;
        while (doesCurrentNodeExist) {
            std::cout << mutableNode->data << " " << std::flush;

            bool doesRightChildOfCurrentNodeExist = mutableNode->right != nullptr;
            if (doesRightChildOfCurrentNodeExist) {
                nodes.push(mutableNode->right);
            }

            mutableNode = mutableNode->left;
            doesCurrentNodeExist = mutableNode != nullptr;
        }
    }

    void preOrderTraversalIterative_singleStack_1_withoutDuplicates_doubleLoopOnly(const TreeNode* const node) const {
        std::stack<TreeNode*> nodes;

        nodes.push(const_cast<TreeNode*>(node));

        bool areNodesLeftToProcess = !nodes.empty();
        while (areNodesLeftToProcess) {
            const TreeNode* const currentNode = nodes.top();
            nodes.pop();
            processLeftSubtree_preorderTraversal(currentNode, nodes);
            areNodesLeftToProcess = !nodes.empty();
        }
    }

    std::vector<std::reference_wrapper<int>> preOrderTraversalIterative_singleStack_1_withoutDuplicates_doubleLoopOnly_vector(const TreeNode* const node) const {
        std::stack<const TreeNode*> nodes;
        std::vector<std::reference_wrapper<int>> output;

        nodes.push(const_cast<TreeNode*>(node));

        bool areNodesLeftToProcess = !nodes.empty();
        while (areNodesLeftToProcess) {
            const TreeNode* const currentNode = nodes.top();
            nodes.pop();
            processLeftSubtree_preorderTraversal(currentNode, nodes, output);
            areNodesLeftToProcess = !nodes.empty();
        }

        return output;
    }

    void processLeftSubtree_preorderTraversal(const TreeNode* const currentNode, std::stack<const TreeNode*>& nodes, std::vector<std::reference_wrapper<int>>& output) const {
        TreeNode* mutableNode = const_cast<TreeNode* const>(currentNode);
        bool doesCurrentNodeExist = mutableNode != nullptr;
        while (doesCurrentNodeExist) {
            output.push_back(mutableNode->data);

            bool doesRightChildOfCurrentNodeExist = mutableNode->right != nullptr;
            if (doesRightChildOfCurrentNodeExist) {
                nodes.push(mutableNode->right);
            }

            mutableNode = mutableNode->left;
            doesCurrentNodeExist = mutableNode != nullptr;
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
    tree.inOrderTraversalRecursive();
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

    std::cout << '\n';
    std::cout << "Post-order traversal: ";
    std::cout << '\n';
    tree.postOrderTraversalRecursive();
    std::cout << std::endl;

    tree.postOrderTraversalIterative_twoStack();
    std::cout << std::endl;

    tree.postOrderTraversalIterative_singleStack_1();
    std::cout << std::endl;

    const std::vector<std::reference_wrapper<int>>& postOrderVector_1 = tree.postOrderTraversalIterative_singleStack_1_vector();
    for (const int& element : postOrderVector_1) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    tree.postOrderTraversalIterative_singleStack_2();
    std::cout << std::endl;

    auto postOrderVector_2 = tree.postOrderTraversalIterative_singleStack_2_vector();
    for (const int& element : postOrderVector_2) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    std::cout << "\nPre-Order traversal" << "\n";
    tree.preOrderTraversalIterative_singleStack_1();
    std::cout << std::endl;
    tree.preOrderTraversalIterative_singleStack_1_withoutDuplicates();
    std::cout << std::endl;
    tree.preOrderTraversalIterative_singleStack_1_doubleLoop();

    std::cout << std::endl;
    auto preOrderVector_1 = tree.preOrderTraversalIterative_singleStack_1_doubleLoop_vector();
    for (const int& element : preOrderVector_1) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
