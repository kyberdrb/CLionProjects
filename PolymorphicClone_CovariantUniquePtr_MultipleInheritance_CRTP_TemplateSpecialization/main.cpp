#include <iostream>
#include <memory>

// How to Return a Smart Pointer AND Use Covariance: Multiple Inheritance v2: Specialization to the rescue: https://www.fluentcpp.com/2017/09/12/how-to-return-a-smart-pointer-and-use-covariance/

template <typename Derived, typename... Bases>
class clone_inherit : public Bases...   // forgot to write the inheritance from Bases. Got an error message: error: cannot convert ‘std::unique_ptr<concrete, std::default_delete<concrete> >::pointer’ {aka ‘concrete*’} to ‘foo*’ in initialization
{                                       // Beacuse I forgot to add the inheritance part, the class is not polymorphic, thus I can't assign an instance of a concrete type to a class of its base type
public:
    ~clone_inherit() override = default;

    std::unique_ptr<Derived> clone() const
    {
        return std::unique_ptr<Derived>(static_cast<Derived*>(this->clone_impl()));
    }

private:
    clone_inherit* clone_impl() const override
    {
        return new Derived(static_cast<const Derived&>(*this));
    }
};

template <typename Derived>
class clone_inherit<Derived> {
public:
    virtual ~clone_inherit() = default;

    std::unique_ptr<Derived> clone() const {
        return std::unique_ptr<Derived>(static_cast<Derived*>(this->clone_impl()));
    }

private:
    virtual clone_inherit* clone_impl() const = 0;
};

class foo : public clone_inherit<foo> {};

class bar : public clone_inherit<bar> {};

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