#include <iostream>
#include <memory>
#include <vector>
#include <cassert>

// Sharing with temporary ownership (std::weak_ptr): https://riptutorial.com/cplusplus/example/1673/sharing-with-temporary-ownership--std--weak-ptr-

// Run with Valgrind.

struct TreeNode {
    std::weak_ptr<TreeNode> parent;
    std::vector<std::shared_ptr<TreeNode>> children;
};

int main() {
    std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>();

    for (int i = 0; i < 100; ++i) {
        std::cout << "root: ref count:\t" << root.use_count() << std::endl;
        std::shared_ptr<TreeNode> child = std::make_shared<TreeNode>();
        std::cout << "root: ref count:\t" << root.use_count() << std::endl;
        child->parent = root;
        std::cout << "root: ref count:\t" << root.use_count() << std::endl << std::endl;
//      root->children.emplace_back(child);
//      assert(child.use_count() == 2);
        root->children.emplace_back(std::move(child));
        assert(root->children[i].use_count() == 1);
        std::cout << "root: ref count:\t" << root.use_count() << std::endl;
    }

    std::cout << std::endl;

    for (const auto& child : root->children) {
        std::cout << child.use_count() << std::endl;
    }

    std::cout << "root: ref count:\t" << root.use_count() << std::endl;
    std::cout << "root: children.size():\t" << root->children.size() << std::endl;

    root.reset();

    std::cout << "root.reset(): ref count:\t" << root.use_count() << std::endl;

    return 0;
}
