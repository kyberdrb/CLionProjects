#include <iostream>

// Polymorphic clones in modern C++: The classical problem: https://www.fluentcpp.com/2017/09/08/make-polymorphic-copy-modern-cpp/

class Interface {
public:
    virtual void doSomething() const = 0;
    virtual ~Interface() = default;
};

class Implementation : public Interface {
    void doSomething() const override {
        std::cout << "Implementation is doing something..." << std::endl;
    }
};

int main() {
    Implementation x;
    Implementation y = x;

    Interface& xx = x;
    Interface& yy = y;

    return 0;
}