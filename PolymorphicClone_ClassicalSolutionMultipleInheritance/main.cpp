#include <iostream>

// Polymorphic clones in modern C++: The solution without smart pointers scales effortlessly because the clone method is independent from the interface: https://www.fluentcpp.com/2017/09/08/make-polymorphic-copy-modern-cpp/

class Interface1 {
public:
    virtual Interface1* clone() const = 0;

    virtual void doSomething() const = 0;

    virtual ~Interface1() = default;
};

class Interface2 {
public:
    virtual Interface2* clone() const = 0;

    virtual void doSomethingElse() const = 0;

    virtual ~Interface2() = default;
};

class Implementation : public Interface1, public Interface2 {
public:
    Implementation* clone() const override {    // using covariance to override the 'clone()' function from both interfaces
        return new Implementation(*this);
    }

    void doSomething() const override {
        std::cout << "Doin' something..." << std::endl;
    }

    void doSomethingElse() const override {
        std::cout << "Doin' something else..." << std::endl;
    }
};

int main() {
    Interface1* x1 = new Implementation;
    x1->doSomething();
    Interface1* y1 = x1->clone();

    Interface2* x2 = new Implementation;
    x2->doSomethingElse();
    Interface2* y2 = x2->clone();

    delete y2;
    delete x2;

    delete y1;
    delete x1;

    return 0;
}