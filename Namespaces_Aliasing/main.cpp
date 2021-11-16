#include <iostream>

// Name visibility: Namespace aliasing: http://www.cplusplus.com/doc/tutorial/namespaces/

namespace namespaceName {
    int x = 5;
}

// namespace newNamespaceName = someNamespace; // error: ‘someNamespace’ is not a namespace-name
namespace newNamespaceName = namespaceName;

int main() {
    std::cout << namespaceName::x << std::endl;
    std::cout << newNamespaceName::x << std::endl;
    return 0;
}
