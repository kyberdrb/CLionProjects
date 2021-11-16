#include <iostream>

// Polymorphic clones in modern C++: The classical solution: https://www.fluentcpp.com/2017/09/08/make-polymorphic-copy-modern-cpp/

class Interface {
public:
    virtual Interface* clone() const = 0;

    virtual void doSomething() const = 0;

    virtual ~Interface() = default;
};

class Implementation : public Interface {
    static uint32_t counter;
    uint32_t instanceNumber;

public:
    Implementation() : instanceNumber(counter++) {}

    Implementation* clone() const override {
        // requires implemented copy constructor; not recommended according to 'C.130' in
        // http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c130-for-making-deep-copies-of-polymorphic-classes-prefer-a-virtual-clone-function-instead-of-copy-constructionassignment
        //return new Implementation(*this);

        // relies only on the constructor
        return new Implementation;
    }

    //Implementation(const Implementation& source) : instanceNumber(counter++) {}

    void doSomething() const override {
        std::cout << "Implementation " << instanceNumber << " is doing something..." << std::endl;
    }

    ~Implementation() override = default;
};

uint32_t Implementation::counter = 0;

int main() {
    Interface* x = new Implementation;
    Interface& xx = *x;
    xx.doSomething();
    Interface* y = xx.clone();
    y->doSomething();

    delete y;
    delete x;

    return 0;
}