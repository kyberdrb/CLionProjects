#include <iostream>
#include <memory>
#include <vector>
#include <cassert>

#include "Something.h"

// https://stackoverflow.com/questions/16030081/copy-constructor-for-a-class-with-unique-ptr/43263477#43263477

struct Base {
    auto clone() const {
        return std::unique_ptr<Base>(clone_impl());
    }

    virtual ~Base() = default;

protected:
    virtual Base* clone_impl() const = 0;
};

struct Derived : Base {
    std::unique_ptr<Something> somePtr;

    // error: no matching function for call to ‘std::unique_ptr<Something>::unique_ptr(Something&)’:
    //  - https://stackoverflow.com/questions/9618268/initializing-container-of-unique-ptrs-from-initializer-list-fails-with-gcc-4-7/9618553#9618553
    //  - https://stackoverflow.com/questions/6804216/how-to-initialize-a-container-of-noncopyable-with-initializer-list
//    std::vector<std::unique_ptr<Something>> someThings{ new Something{2}, new Something{4} };

    std::vector<std::unique_ptr<Something>> someThings;

    explicit Derived(double potency) {
        somePtr = std::make_unique<Something>(potency);

        someThings.emplace_back(std::make_unique<Something>(2));
        someThings.emplace_back(std::make_unique<Something>(4));
    };

    Derived(const Derived& source) {
        somePtr = std::make_unique<Something>(*source.somePtr);

        for (const auto& thing : source.someThings) {
            this->someThings.emplace_back(std::make_unique<Something>(*thing));
        }
    };

    ~Derived() override {
        std::cout << "Derived: Destructor" << std::endl;
    }

protected:
    Derived* clone_impl() const override {
        return new Derived(*this);
    }
};

struct Foo {
    std::unique_ptr<Base> ptr;

    explicit Foo(std::unique_ptr<Base> dependency) :
        ptr(std::move(dependency))
    {
        std::cout << "Foo: Constructor" << std::endl;
    };

    Foo(const Foo& source) :
        ptr(source.ptr->clone())
    {};

    Foo(Foo&& source) = default;

    Foo& operator=(const Foo& source) {
        ptr = source.ptr->clone();
        return *this;
    }

    Foo& operator=(Foo&& source) = default;

    ~Foo() = default;
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::unique_ptr<Base> d = std::make_unique<Derived>(5.5);
    Foo foo(std::move(d));
    Foo bar = foo;

    std::cout << std::endl;

    std::cout << d.get() << std::endl;

    if (d != nullptr) {
        std::cout << dynamic_cast<Derived*>(d.get())->somePtr->getPotency() << std::endl;
    }

    if (d == nullptr) {
        std::cout << "The instance has been moved to another owner" << std::endl;
    }

    std::cout << std::endl;

    std::cout << "foo.ptr->somePtr->potency:\t" << dynamic_cast<Derived*>(foo.ptr.get())->somePtr->potency << std::endl;
    std::cout << "foo.ptr->somePtr->potency:\t" << dynamic_cast<Derived*>(bar.ptr.get())->somePtr->potency << std::endl;

    std::cout << std::endl;


    dynamic_cast<Derived*>(foo.ptr.get())->somePtr->potency = 5.3;

    auto& fooThings = dynamic_cast<Derived*>(foo.ptr.get())->someThings;
    dynamic_cast<Derived*>(foo.ptr.get())->someThings.emplace_back(new Something(7));
    auto pt = std::make_unique<Something>(9);
    fooThings.emplace_back(std::move(pt));

    for (const auto& fooThing : fooThings) {
        std::cout << fooThing->getPotency() << std::endl;
    }

    std::cout << std::endl;

    const auto& barThings{dynamic_cast<Derived*>(bar.ptr.get())->someThings};
    for(const auto& barThing : barThings) {
        std::cout << barThing->potency << std::endl;
    }

    std::cout << std::endl;

    std::cout << "foo.ptr->somePtr->potency:\t" << dynamic_cast<Derived*>(foo.ptr.get())->somePtr->potency << std::endl;
    std::cout << "bar.ptr->somePtr->potency:\t" << dynamic_cast<Derived*>(bar.ptr.get())->somePtr->potency << std::endl;

    assert(dynamic_cast<Derived*>(foo.ptr.get())->somePtr->potency == 5.3);
    assert(dynamic_cast<Derived*>(bar.ptr.get())->somePtr->potency == 5.5);

    assert(dynamic_cast<Derived*>(bar.ptr.get())->someThings.size() == 2);
    assert(dynamic_cast<Derived*>(foo.ptr.get())->someThings.size() == 4);

    std::cout << std::endl;

    std::unique_ptr<Something> someThing = std::make_unique<Something>(6.6);    // EXPLORE: use this variable in Derived class in composition
    dynamic_cast<Derived*>(foo.ptr.get())->somePtr = std::move(someThing);

    std::cout << "foo.ptr->somePtr->potency:\t" << dynamic_cast<Derived*>(foo.ptr.get())->somePtr->potency << std::endl;
    std::cout << "bar.ptr->somePtr->potency:\t" << dynamic_cast<Derived*>(bar.ptr.get())->somePtr->potency << std::endl;

    assert(dynamic_cast<Derived*>(foo.ptr.get())->somePtr->potency == 6.6);
    assert(dynamic_cast<Derived*>(bar.ptr.get())->somePtr->potency == 5.5);

    std::cout << std::endl;

    return 0;
}