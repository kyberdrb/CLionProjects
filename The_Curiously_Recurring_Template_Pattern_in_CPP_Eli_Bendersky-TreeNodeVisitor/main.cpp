#include <iostream>
#include <cassert>

// The Curiously Recurring Template Pattern in C++ - The following example: https://eli.thegreenplace.net/2011/05/17/the-curiously-recurring-template-pattern-in-c/

struct TreeNode {
    enum class Kind {
        RED,
        BLUE
    };

    Kind kind;
    TreeNode* left{};
    TreeNode* right{};


    explicit TreeNode(Kind kind, TreeNode* left = nullptr, TreeNode* right = nullptr) :
        kind(kind), left(left), right(right) {}
};

template <typename Derived>
class GenericVisitor {
    void dispatch_node(TreeNode* node) {
        switch(node->kind) {
            case(TreeNode::Kind::RED): {
                derived().handle_RED(node);
                break;
            }
            case(TreeNode::Kind::BLUE): {
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

    GenericVisitor() = default;
    friend Derived;

public:
    void handle_RED(TreeNode* node) {
        std::cout << "Generic handling for RED node " << std::endl;
    }

    void handle_BLUE(TreeNode* node) {
        std::cout << "Generic handling for BLUE node " << std::endl;
    }

    void visit_preorder(TreeNode* node) {
        if (node) {
            dispatch_node(node);
            visit_preorder(node->left);
            visit_preorder(node->right);
        }
    }

    void visit_inorder(TreeNode* node) {
        if (node) {
            visit_inorder(node->left);
            dispatch_node(node);
            visit_inorder(node->right);
        }
    }

    void visit_postorder(TreeNode* node) {
        if (node) {
            visit_postorder(node->left);
            visit_postorder(node->right);
            dispatch_node(node);
        }
    }
};

class SpecialVisitor : public GenericVisitor<SpecialVisitor> {
public:
    void handle_RED(TreeNode* node) {
        std::cout << "Special handling for RED node " << std::endl;
    }
};

int main() {
    auto root = new TreeNode(TreeNode::Kind::RED);
    root->left = new TreeNode(TreeNode::Kind::BLUE);
    root->right = new TreeNode(TreeNode::Kind::RED);

    SpecialVisitor specialVisitor;
    specialVisitor.visit_inorder(root);
    std::cout << std::endl;
    specialVisitor.visit_preorder(root);
    std::cout << std::endl;
    specialVisitor.visit_postorder(root);

    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
