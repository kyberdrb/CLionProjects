#include <iostream>
#include <memory>
#include <cassert>
#include <vector>

class Foo {
public:
    std::unique_ptr<int> number;

    Foo(int number) : number(std::make_unique<int>(number)) {}

    Foo(const Foo& source) : number(new int(*source.number)) {
        std::cout << "Foo: Copy constructor" << std::endl;
    }

    Foo& operator=(const Foo& source) {
        std::cout << "Foo: Copy assignment operator" << std::endl;
        this->number = std::make_unique<int>(*source.number);
        return *this;
    }

    Foo(Foo&& source) : number(std::move(source.number)) {
        std::cout << "Foo: Move constructor" << std::endl;
    }

    Foo& operator=(Foo&& source) {
        std::cout << "Foo: Move assignment operator" << std::endl;
        this->number = std::move(source.number);
        return *this;
    }
};

int main() {
    std::cout << "a1" << std::endl;
    Foo a1{2};
    std::cout << *a1.number << std::endl;

    std::cout << std::endl;

    std::cout << "a2: Copied from a1 by copy constructor" << std::endl;
    Foo a2 = a1;
    std::cout << *a2.number << std::endl;
    assert(*a1.number == *a2.number);

    std::cout << std::endl;

    std::cout << "Change a2" << std::endl;
    *(a2.number) = 5;
    std::cout << "*a1.number" << "\t" << *(a1.number) << std::endl;
    std::cout << "*a2.number" << "\t" << *(a2.number) << std::endl;
    assert(*(a1.number) != *(a2.number));
    std::cout << "a1 and a2 are independent objects" << std::endl;

    std::cout << std::endl;

    std::cout << "a3: Copied from a1 by copy assignment operator" << std::endl;
    Foo a3{4};
    assert(*(a1.number) != *(a3.number));
    a3 = a1;
    std::cout << "*a3.number" << "\t" << *a3.number << std::endl;
    std::cout << "*a1.number" << "\t" << *a1.number << std::endl;
    assert(*(a1.number) == *(a3.number));

    std::cout << std::endl;

    std::cout << "herd: vector of Foo pointers" << std::endl;
    std::vector<Foo*> herd;
    herd.emplace_back(new Foo{6});
    //herd.emplace_back(std::make_unique<Foo>(2).get());  // behaves undefined in vector of pointers
    herd.push_back(new Foo(1));
    herd.emplace_back(new Foo{7});
    herd.emplace_back(new Foo{8});

    for (const Foo* foo : herd) {
        std::cout << *foo->number << std::endl;
    }

    for (const auto& foo : herd) {
        delete foo;
    }

    std::cout << std::endl;

    std::cout << "bunch: vector of Foo unique pointers" << std::endl;
    std::vector<std::unique_ptr<Foo>> bunch;
    bunch.emplace_back(new Foo{6});
    //bunch.emplace_back(std::make_unique<Foo>(5).get());  // behaves undefined in vector of pointers
    bunch.emplace_back(std::make_unique<Foo>(5));
    bunch.push_back(std::make_unique<Foo>(2));
    bunch.emplace_back(new Foo{1});
    bunch.emplace_back(new Foo{7});
    bunch.emplace_back(new Foo{8});

    for (const std::unique_ptr<Foo>& foo : bunch) { // auto is of type 'const std::unique_ptr<Foo>&'
        std::cout << *foo->number << std::endl;
    }

    std::cout << std::endl;

    for (auto&& foo : bunch) {  // auto is of type std::unique_ptr<Foo>&'
        std::cout << *foo->number << std::endl;
    }

    std::cout << std::endl;

    for (const auto& foo : bunch) { // auto is of type 'const std::unique_ptr<Foo>&'
        std::cout << *foo->number << std::endl;
    }

    return 0;
}