#include <iostream>
#include <memory>
#include <cassert>
#include <vector>

#include "Member.h"

struct Something {
    Member foo;     // Composition - when Something is destroyed everything it contains is destroyed at the same time

    Something() :
        foo(5, 6.7)
    {}

    Something(const Something& source) :
        foo(source.foo)
    {
        std::cout << "Something: Copy constructor" << std::endl;
    }

    Something& operator=(const Something& source) {
        std::cout << "Something: Copy assignment operator" << std::endl;

        if(&source == this) return *this;

        this->foo = source.foo;

        return *this;
    }

    Something(Something&& source) :
        foo(std::move(source.foo))
    {}

    Something& operator=(Something&& source) {
        this->foo = std::move(source.foo);
        return *this;
    }

    Something getThis() const {
        return *this;
    }

    Something getSomething() const {
        return Something();
    };

    ~Something() {
        std::cout << "Something: Destructor" << std::endl;
    }
};

int main() {
    std::unique_ptr<Something> bar = std::make_unique<Something>();
    std::cout << "bar" << std::endl;
    std::cout << &bar->foo << std::endl;
    std::cout << bar->foo.number << "\t" << &bar->foo.number << std::endl;
    std::cout << bar->foo.otherNumber << "\t" << &bar->foo.otherNumber << std::endl;

    std::cout << std::endl;

    Something baz;
    std::cout << "baz" << std::endl;
    std::cout << &baz.foo << std::endl;
    std::cout << baz.foo.number << "\t" << &baz.foo.number << std::endl;
    std::cout << baz.foo.otherNumber << "\t" << &baz.foo.otherNumber << std::endl;

    std::cout << std::endl;

    Something qux = baz;
    std::cout << "qux: Copied from 'baz' by copy constructor" << std::endl;
    std::cout << &qux.foo << std::endl;
    std::cout << qux.foo.number << "\t" << &qux.foo.number << std::endl;
    std::cout << qux.foo.otherNumber << "\t" << &qux.foo.otherNumber << std::endl;
    assert(qux.foo.number == baz.foo.number);
    assert(qux.foo.otherNumber == baz.foo.otherNumber);

    std::cout << std::endl;

    std::cout << "baz" << std::endl;
    baz.foo.number = 10;
    baz.foo.otherNumber = 2.3;
    std::cout << baz.foo.number << std::endl;
    std::cout << baz.foo.otherNumber << std::endl;
    std::cout << "qux" << std::endl;
    std::cout << qux.foo.number << std::endl;
    std::cout << qux.foo.otherNumber << std::endl;
    assert(qux.foo.number != baz.foo.number);
    assert(qux.foo.otherNumber != baz.foo.otherNumber);

    std::cout << std::endl;

    Something quux;
    quux = baz;
    std::cout << "quux: Copied from 'baz' by copy assignment operator" << std::endl;
    std::cout << &quux.foo << std::endl;
    std::cout << quux.foo.number << "\t" << &quux.foo.number << std::endl;
    std::cout << quux.foo.otherNumber << "\t" << &quux.foo.otherNumber << std::endl;
    assert(quux.foo.number == baz.foo.number);
    assert(quux.foo.otherNumber == baz.foo.otherNumber);

    std::cout << std::endl;

    quux.foo = quux.foo;
    std::cout << "quux: Self-assignment" << std::endl;
    std::cout << &quux.foo << std::endl;
    std::cout << quux.foo.number << "\t" << &quux.foo.number << std::endl;
    std::cout << quux.foo.otherNumber << "\t" << &quux.foo.otherNumber << std::endl;

    std::cout << std::endl;

    std::cout << "Copy existing instance to a value var of type Something" << std::endl;
    Something something(std::move(bar->getThis()));
    assert(something.foo.number == bar->foo.number);

    std::cout << std::endl;

    std::cout << "Move an instance to a value var of type Something" << std::endl;
    Something something1(std::move(bar->getSomething()));
    assert(something1.foo.number == 5);
    assert(something1.foo.otherNumber == 6.7);

    std::cout << std::endl;

    std::vector<std::unique_ptr<Member>> members;
    members.emplace_back(std::make_unique<Member>(2, 3.6));

    for (auto&& member : members) {
        std::cout << member->number << "\t" << member->otherNumber << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
