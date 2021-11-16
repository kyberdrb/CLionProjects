#include <iostream>

// Name visibility: The std namespace: http://www.cplusplus.com/doc/tutorial/namespaces/

using namespace std;

int main() {
    cout << "Hello, World! without namespace qualifiers." << endl;
    std::cout << "Hello, World! with namespace qualifiers works as well, although we imported the "
                 "entire standard (std) namespace." << std::endl;
    return 0;
}
