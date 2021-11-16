#include <iostream>
#include <memory>

// Polymorphic clones in modern C++: Clearing the ambiguity: https://www.fluentcpp.com/2017/09/08/make-polymorphic-copy-modern-cpp/

class Interface1 {
public:
//    virtual std::unique_ptr<Interface1> clone() const = 0;    // error: invalid covariant return type for ‘virtual std::unique_ptr<Interface1> Implementation::clone() const’

    virtual std::unique_ptr<Interface1> cloneInterface1() const = 0;

    virtual void doSomething() const = 0;

    virtual ~Interface1() = default;
};

class Interface2 {
public:
//    virtual std::unique_ptr<Interface2> clone() const = 0;    // error: invalid covariant return type for ‘virtual std::unique_ptr<Interface1> Implementation::clone() const’

    virtual std::unique_ptr<Interface2> cloneInterface2() const = 0;

    virtual void doSomethingElse() const = 0;

    virtual ~Interface2() = default;
};

class Implementation : public Interface1, public Interface2 {
public:
//    std::unique_ptr<Interface1> clone() const override {    // error: invalid covariant return type for ‘virtual std::unique_ptr<Interface1> Implementation::clone() const’
//        return std::make_unique<Implementation>();
//    }

    std::unique_ptr<Interface1> cloneInterface1() const override {
        return std::make_unique<Implementation>();
    }

    std::unique_ptr<Interface2> cloneInterface2() const override {
        return std::make_unique<Implementation>();
    }

    void doSomething() const override {
        std::cout << "Doin' something..." << std::endl;
    }

    void doSomethingElse() const override {
        std::cout << "Doin' something else..." << std::endl;
    }
};

int main() {
    std::unique_ptr<Interface1> x1 = std::make_unique<Implementation>();
    std::unique_ptr<Interface1> y1 = x1->cloneInterface1();

    std::unique_ptr<Interface2> x2 = std::make_unique<Implementation>();
    std::unique_ptr<Interface2> y2 = x2->cloneInterface2();

    return 0;
}