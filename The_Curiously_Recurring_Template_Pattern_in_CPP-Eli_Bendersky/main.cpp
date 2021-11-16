#include <iostream>

// The Curiously Recurring Template Pattern in C++: https://eli.thegreenplace.net/2011/05/17/the-curiously-recurring-template-pattern-in-c/

template <typename Child>
class Base {
public:
    void interface() {
        static_cast<Child*>(this)->implementation();
    }
};

class Derived : public Base<Derived> {
public:
    void implementation() {
        std::cout << "Derived implementation" << std::endl;
    }
};

int main() {
    Derived d;
    d.interface();
    return 0;
}
