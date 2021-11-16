#include <iostream>
#include <memory>

// How to Return a Smart Pointer AND Use Covariance: Polymorphic clones in modern C++: A modern solution: https://www.fluentcpp.com/2017/09/08/make-polymorphic-copy-modern-cpp/

class Interface {
public:
    virtual std::unique_ptr<Interface> clone() const = 0;

    virtual void doSomething() const = 0;

    virtual ~Interface() = default;
};

class Implementation : public Interface{
public:
    std::unique_ptr<Interface> clone() const override {
        return std::make_unique<Implementation>(*this);
    }

    void doSomething() const override {
        std::cout << "Doing something..." << std::endl;
    }
};

int main() {
    std::unique_ptr<Interface> x = std::make_unique<Implementation>();
    std::cout << "x:\t";
    x->doSomething();

    std::unique_ptr<Interface> y = x->clone();
    std::cout << "y:\t";
    y->doSomething();
    return 0;
}