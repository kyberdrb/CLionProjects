#include <iostream>
#include <memory>

// How to Return a Smart Pointer AND Use Covariance: Multiple Inheritance: Variadic templates to the rescue: https://www.fluentcpp.com/2017/09/12/how-to-return-a-smart-pointer-and-use-covariance/

class foo {
public:
    virtual ~foo() = default;

    std::unique_ptr<foo> clone() const {
        return std::unique_ptr<foo>(this->clone_impl());
    }

private:
    virtual foo* clone_impl() const = 0;
};

class bar {
public:
    virtual ~bar() = default;

    std::unique_ptr<bar> clone() const {
        return std::unique_ptr<bar>(this->clone_impl());
    }

private:
    virtual bar* clone_impl() const = 0;
};

template <typename Derived, typename... Bases>
class clone_inherit : public Bases... {
public:
    std::unique_ptr<Derived> clone() const {
        return std::unique_ptr<Derived>(static_cast<Derived*>(this->clone_impl()));
    }

private:
    clone_inherit* clone_impl() const override {
        return new Derived(static_cast<const Derived &>(*this));
    }
};

class concrete : public clone_inherit<concrete, foo, bar> {};

int main() {
    std::unique_ptr<concrete> c = std::make_unique<concrete>();
    std::unique_ptr<concrete> cc = c->clone();

    foo* f = c.get();
    std::unique_ptr<foo> ff = f->clone();

    bar* b = c.get();
    std::unique_ptr<bar> bb = b->clone();

    return 0;
}