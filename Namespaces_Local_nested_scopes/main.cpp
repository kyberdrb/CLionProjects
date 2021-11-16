#include <iostream>

// Name visibility: Scopes: http://www.cplusplus.com/doc/tutorial/namespaces/

int main() {
    int x = 10;
    int y = 20;
    {
        int x;  // Declaration shadows a local variable
        x = 50;
        y = 60;
        std::cout << "inner block:\n";
        std::cout << "x: " << x << '\n';
        std::cout << "y: " << y << '\n';
    }
    std::cout << "outer block:\n";
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
    
    return 0;
}
