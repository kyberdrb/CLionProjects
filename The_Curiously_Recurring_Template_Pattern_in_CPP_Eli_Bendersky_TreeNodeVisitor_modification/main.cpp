#include <iostream>
#include <cassert>
#include <queue>

// The Curiously Recurring Template Pattern in C++ - The following example: https://eli.thegreenplace.net/2011/05/17/the-curiously-recurring-template-pattern-in-c/

enum class BinaryTreeNodeKind {
    RED,
    BLUE
};

struct BinaryTreeNode {
    BinaryTreeNodeKind kind;
    BinaryTreeNode* left{};
    BinaryTreeNode* right{};


    explicit BinaryTreeNode(BinaryTreeNodeKind kind, BinaryTreeNode* left = nullptr, BinaryTreeNode* right = nullptr) :
            kind(kind), left(left), right(right) {}

    void recursively_destroy_subtree(BinaryTreeNode* node) {
        if (node) {
            recursively_destroy_subtree(node->left);
            recursively_destroy_subtree(node->right);
            delete node;
        }
    }

    ~BinaryTreeNode() {
//        std::queue<BinaryTreeNode*> children;
//
//        if (this->left) {
//            children.push(this->left);
//        }
//
//        if (this->right) {
//            children.push(this->right);
//        }
//
//        BinaryTreeNode* tempNode{};
//        tempNode = children.front();
//        delete tempNode;
//        children.pop();
//
//        tempNode = children.front();
//        delete tempNode;
//        children.pop();

        recursively_destroy_subtree(this);
    }
};

template <typename Derived>
class GenericNodeVisitor {
    void dispatch_node(BinaryTreeNode* node) {
        switch(node->kind) {
            case(BinaryTreeNodeKind::RED): {
                derived().handle_RED(node);
                break;
            }
            case(BinaryTreeNodeKind::BLUE): {
                derived().handle_BLUE(node);
                break;
            }
            default:
                assert(0);
        }
    }

    Derived& derived() {
        return *static_cast<Derived*>(this);
    }

    GenericNodeVisitor() = default;
    friend Derived;

public:
    void handle_RED(BinaryTreeNode* node) {
        std::cout << "Generic handling for RED node " << std::endl;
    }

    void handle_BLUE(BinaryTreeNode* node) {
        std::cout << "Generic handling for BLUE node " << std::endl;
    }

    void visit_preorder(BinaryTreeNode* node) {
        if (node) {
            dispatch_node(node);
            visit_preorder(node->left);
            visit_preorder(node->right);
        }
    }

    void visit_inorder(BinaryTreeNode* node) {
        if (node) {
            visit_inorder(node->left);
            dispatch_node(node);
            visit_inorder(node->right);
        }
    }

    void visit_postorder(BinaryTreeNode* node) {
        if (node) {
            visit_postorder(node->left);
            visit_postorder(node->right);
            dispatch_node(node);
        }
    }
};

class SpecialVisitor : public GenericNodeVisitor<SpecialVisitor> {
public:
    void handle_RED(BinaryTreeNode* node) {
        std::cout << "Special handling for RED node " << std::endl;
    }
};

int main() {
    //auto root = new BinaryTreeNode(BinaryTreeNodeKind::RED);
    BinaryTreeNode root(BinaryTreeNodeKind::RED);
    root.left = new BinaryTreeNode(BinaryTreeNodeKind::BLUE);
    root.right = new BinaryTreeNode(BinaryTreeNodeKind::RED);

    SpecialVisitor specialVisitor;
    specialVisitor.visit_inorder(&root);
    std::cout << std::endl;
    specialVisitor.visit_preorder(&root);
    std::cout << std::endl;
    specialVisitor.visit_postorder(&root);

//    delete root->left;
//    delete root->right;
//    delete root;

    return 0;
}
