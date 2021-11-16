#include <iostream>
#include <memory>

// How to Return a Smart Pointer AND Use Covariance: Simple Hierarchy, v2: Enter the CRTP: https://www.fluentcpp.com/2017/09/12/how-to-return-a-smart-pointer-and-use-covariance/

template <typename Derived, typename Base>
class clone_inherit : public Base {
public:
    std::unique_ptr<Derived> clone() const {
        return std::unique_ptr<Derived>(static_cast<Derived*>(this->clone_impl()));
    }

private:
    clone_inherit* clone_impl() const {
        return new Derived(static_cast<const Derived&>(*this));
    }
};

class cloneable {
public:
    virtual ~cloneable() = default;

    std::unique_ptr<cloneable> clone() const {
        return std::unique_ptr<cloneable>(this->clone_impl());
    }

private:
    virtual cloneable* clone_impl() const = 0;
};

class concrete : public clone_inherit<concrete, cloneable> {};

int main()
{
    std::unique_ptr<concrete> c = std::make_unique<concrete>(); // create unique ptr concrete
    std::unique_ptr<concrete> cc = c->clone();  // copy construct another concrete unique ptr from the previous one

    cloneable* f = c.get();   // create a raw pointer of a polymorphic type cloneable and initialize it with the pointer value of the first created unique ptr
    std::unique_ptr<cloneable> ff = f->clone();   // clone the instance from the polymorphic raw pointer into a polymorphic unique ptr
    std::unique_ptr<cloneable> fff = c->clone();  // clone the instance from the first concrete unique ptr into another polymorphic unique ptr
}
