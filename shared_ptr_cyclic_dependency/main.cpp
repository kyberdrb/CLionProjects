#include <iostream>
#include <memory>

// What is the cyclic dependency issue with shared_ptr?: https://stackoverflow.com/questions/22185896/what-is-the-cyclic-dependency-issue-with-shared-ptr/51806930#51806930
// The Problem

class B;

class A {
public:
    A() {
        std::cout << "A()" << std::endl;
    }

    ~A() {
        std::cout << "~A()" << std::endl;
    }

    void setDependency(std::shared_ptr<B> dependency) {
        dependencyForB = dependency;    // std::move doesn't help, even when used in both classes
    }

    std::shared_ptr<B> getDependency() const {
        return dependencyForB;
    }

private:
    std::shared_ptr<B> dependencyForB;
};

class B {
public:
    B() {
        std::cout << "B()" << std::endl;
    }

    ~B() {
        std::cout << "~B()" << std::endl;
    }

    void setDependency(std::shared_ptr<A> dependency) {
        dependencyForA = dependency;
    }

    std::shared_ptr<A> getDependency() const {
        return dependencyForA;
    }

private:
    std::shared_ptr<A> dependencyForA;
};

int main() {
    std::cout << std::endl;

    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    std::cout << std::endl;

    std::cout   << "std::shared_ptr<A> a = std::make_shared<A>();\n"
                   "std::shared_ptr<B> b = std::make_shared<B>();"
                << std::endl;
    std::cout << "\ta: ref count:\t" << a.use_count() << std::endl;
    std::cout << "\tb: ref count:\t" << b.use_count() << std::endl;
    std::cout << std::endl;

    a->setDependency(b);

    std::cout << "a->setDependency(b);" << std::endl;
    std::cout << "\ta: ref count:\t" << a.use_count() << std::endl;
    std::cout << "\tb: ref count:\t" << b.use_count() << std::endl;
    std::cout << std::endl;

    b->setDependency(a);

    std::cout << "b->setDependency(a);" << std::endl;
    std::cout << "\ta: ref count:\t" << a.use_count() << std::endl;
    std::cout << "\tb: ref count:\t" << b.use_count() << std::endl;
    std::cout << std::endl;

    a->getDependency().reset();
    a->getDependency().reset();
    a->getDependency().reset(); // even calling reset() multiple times doesn't deallocate the B dependency

    std::cout << "a->getDependency().reset();" << std::endl;
    std::cout << "\ta: ref count:\t" << a.use_count() << std::endl;
    std::cout << "\tb: ref count:\t" << b.use_count() << std::endl;
    std::cout << std::endl;

    b->getDependency().reset();

    std::cout << "b->getDependency().reset();" << std::endl;
    std::cout << "\ta: ref count:\t" << a.use_count() << std::endl;
    std::cout << "\tb: ref count:\t" << b.use_count() << std::endl;
    std::cout << std::endl;

    a.reset();

    std::cout << std::endl;
    std::cout << "a.reset();" << std::endl;
    std::cout << "\ta: ref count:\t" << a.use_count() << std::endl;
    std::cout << "\tb: ref count:\t" << b.use_count() << std::endl;
    std::cout << std::endl;

    b.reset();
    b.reset();
    b.reset();    // even calling reset() multiple times doesn't deallocate the B dependency

    std::cout << std::endl;
    std::cout << "b.reset();" << std::endl;
    std::cout << "\ta: ref count:\t" << a.use_count() << std::endl;
    std::cout << "\tb: ref count:\t" << b.use_count() << std::endl;
    std::cout << std::endl;

    return 0;
}
