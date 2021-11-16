#include <iostream>
#include <memory>

// How to Return a Smart Pointer AND Use Covariance: Diamond Inheritance: Virtual-ing: https://www.fluentcpp.com/2017/09/12/how-to-return-a-smart-pointer-and-use-covariance/

// marking class for uppermost (common) base class in the hierarchy
template <typename T>
class abstract_method {};

// marking class for intermediary base classes inheriting from common base class
template <typename T>
class virtual_inherit_from : virtual public T { // i forgot to inherit from T and got these error messages:
                                                //  error: type ‘clonable’ is not a base type for type ‘virtual_inherit_from<clonable>’
                                                //  error: cannot convert ‘std::unique_ptr<concrete, std::default_delete<concrete> >::pointer’ {aka ‘concrete*’} to ‘clonable*’ in initialization
                                                // yes, it's not convertible when it's not polymorphic
    using T::T;     // works also without the 'using* keyword. Why? Because the 'using' declaration generates the constructors for the derived classes.
                    // It also works without the 'using' declaration because we only use default constructors in derived classes, and fulfil other conditions
                    // written in '~/CLionProjects/CPP_Polymorphic_cloning_and_the_CRTP_Virtual_clone_function_through_CRTP_in_multiple_inheritance'
};

template <typename Derived, typename... Bases>
class clone_inherit : public Bases...{
public:
    virtual ~clone_inherit() = default;

    std::unique_ptr<Derived> clone() const {
        return std::unique_ptr<Derived>(static_cast<Derived*>(this->clone_impl()));
    }

private:
    clone_inherit* clone_impl() const {
        return new Derived(static_cast<const Derived&>(*this));
    }
};

template <typename Derived, typename... Bases>
class clone_inherit<abstract_method<Derived>, Bases...> : public Bases... {
public:
    virtual ~clone_inherit() = default;

    std::unique_ptr<Derived> clone() const {
        return std::unique_ptr<Derived>(static_cast<Derived*>(this->clone_impl()));
    }

private:
    virtual clone_inherit* clone_impl() const = 0;
};

// Unneeded class
//template <typename Derived>
//class clone_inherit<Derived> {
//public:
//    virtual ~clone_inherit() = default;
//
//    std::unique_ptr<Derived> clone() const {
//        return std::unique_ptr<Derived>(static_cast<Derived*>(this->clone_impl()));
//    }
//
//private:
//    clone_inherit* clone_impl() const {
//        return new Derived(static_cast<const Derived&>(*this));
//    }
//};

template <typename Derived>
class clone_inherit<abstract_method<Derived>> {
public:
    virtual ~clone_inherit() = default;

    std::unique_ptr<Derived> clone() const {
        return std::unique_ptr<Derived>(static_cast<Derived*>(this->clone_impl()));
    }

private:
    virtual clone_inherit* clone_impl() const = 0;
};

class clonable : public clone_inherit<abstract_method<clonable>> {};

class foo : public clone_inherit<abstract_method<foo>, virtual_inherit_from<clonable>>{};

class bar : public clone_inherit<abstract_method<bar>, virtual_inherit_from<clonable>> {};

class concrete : public clone_inherit<concrete, foo, bar> {};

int main() {
    auto c = std::make_unique<concrete>();
    std::unique_ptr<concrete> cc = c->clone();

    foo* f = c.get();
    std::unique_ptr<foo> ff = f->clone();

    bar* b = c.get();
    std::unique_ptr<bar> bb = b->clone();

    clonable* p = c.get();
    std::unique_ptr<clonable> pp = p->clone();

    return 0;
}
