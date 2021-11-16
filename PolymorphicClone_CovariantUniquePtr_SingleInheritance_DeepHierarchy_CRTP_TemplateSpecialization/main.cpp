#include <iostream>
#include <memory>

// How to Return a Smart Pointer AND Use Covariance: Deep Hierarchy: Abstracting: https://www.fluentcpp.com/2017/09/12/how-to-return-a-smart-pointer-and-use-covariance/

template <typename T>
class abstract_method {};

  // I can read 'typename...'  as 'typenames' when I substitute the ellipsis '...' with 's' as if it was a plural of 'typename', i.e.
// 'typename...' =
//                  'typename' + '...' =    / substitute '...' for 's' as if it was plural
//                  'typename' + 's' =
//                  'typenames'
// therefore,
// 'typename...' and 'typenames' are equivalent

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
//        return std::unique_ptr<Derived>(this->clone_impl());
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
        return std::unique_ptr<Derived>(static_cast<Derived*>(this->clone_impl()));     // without the static_cast, only with 'this->clone_impl()' I got an error message - error: no matching function for call to ‘std::unique_ptr<clonable, std::default_delete<clonable> >::unique_ptr(clone_inherit<abstract_method<clonable> >*)’
    }

private:
    virtual clone_inherit* clone_impl() const = 0;
};

class clonable : public clone_inherit<abstract_method<clonable>> {};

class abstracted : public clone_inherit<abstract_method<abstracted>, clonable> {};

class concrete : public clone_inherit<concrete, abstracted> {};

int main() {
    std::unique_ptr<concrete> c = std::make_unique<concrete>();
    std::unique_ptr<concrete> cc = c->clone();

    abstracted* a = c.get();
    std::unique_ptr<abstracted> aa = a->clone();

    clonable* x = c.get();
    std::unique_ptr<clonable> xx = x->clone();

    return 0;
}
