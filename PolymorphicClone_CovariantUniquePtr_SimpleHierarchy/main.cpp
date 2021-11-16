#include <iostream>
#include <memory>

// How to Return a Smart Pointer AND Use Covariance: Simple Hierarchy: Covariance + Name hiding: https://www.fluentcpp.com/2017/09/12/how-to-return-a-smart-pointer-and-use-covariance/

class clonable {
public:
    virtual ~clonable() = default;

    std::unique_ptr<clonable> clone() const {
        std::cout << "cloning clonable" << std::endl;
        return std::unique_ptr<clonable>(this->clone_impl());
    }

private:
    virtual clonable* clone_impl() const = 0;
};

class concrete : public clonable {
public:
    std::unique_ptr<concrete> clone() const {
        std::cout << "cloning concrete" << std::endl;
        return std::unique_ptr<concrete>(this->clone_impl());
    }

private:
    concrete* clone_impl() const override { // the return type needs to be of type "concrete*", not "clonable*", in order to use convariance
        std::cout << "cloning concrete for real now" << std::endl;
        return new concrete(*this);
    }
};

int main() {
    std::unique_ptr<concrete> c = std::make_unique<concrete>();
    std::unique_ptr<concrete> cc = c->clone();

    std::cout << std::endl;

    clonable* p = c.get();
    std::unique_ptr<clonable> pp = p->clone();
    return 0;
}