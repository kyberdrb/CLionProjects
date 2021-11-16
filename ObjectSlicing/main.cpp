#include <iostream>
#include <string>

// https://stackoverflow.com/questions/274626/what-is-object-slicing

class A {
    int foo{3};

public:
    A() = default;

    A(const A& a) {
        assign(a);
    }

    virtual A& operator=(const A& a) {
        assign(a);
        return *this;
    }

    int getFoo() const {
        return foo;
    }

    virtual std::string describe() {
        return "I'm A: a sliced object";
    }

    virtual ~A() = default;

protected:
    virtual void assign(const A& a) {
        this->foo = a.foo;
    }
};

class B : public A {
    int bar{7};

public:
    B() = default;

    B(const B& b) : A() {
        this->bar = b.bar;
    }

    B& operator=(const A& a) override {
        // Both, dynamic and static cast work polymorfically
        //if (const B* b = dynamic_cast<const B*>(&a)) {
        if (const B* b = static_cast<const B*>(&a)) {
            this->bar = b->bar;
        } else {
            throw "Bad cast";
        }
        return *this;
    }

    int getBar() const {
        return bar;
    }

    std::string describe() override {
        return "Imma Be";
    }

    ~B() override = default;

protected:
    void assign(const A& b) override {
        A::assign(b);
    }
};

std::string usePolymorficTypeByValue(A a) {
    return a.describe();
}

std::string usePolymorficTypeReference(A& a) {
    return a.describe();
}

std::string usePolymorficTypeByPointer(A* a) {
    return a->describe();
}

int main() {
    A* ab = new B;
    A* abb = new B;

    *ab = *abb;

    delete ab;
    delete abb;

    // the benign case
    B b;
    A a = b;    // Object slicing:
                //  "Slicing" is where you assign an object of a derived class to an instance of a base class,
                //  thereby losing part of the information - some of it is "sliced" away.

    // the treacherous case
    B b1;
    B b2;
    A& a_ref = b1;
    a_ref = b2;

    B* b3 = new B();
    b3->getBar();
    A* a3 = b3;     // Upcasting
    a3->getFoo();   //  therefore, the extra information from the derived class are sliced away.

    delete b3;      // no virtual destructor needed because the deleted pointer is of the derived type
    b3 = nullptr;
    a3 = nullptr;
    delete a3;      // virtual destructor is necessary, beacuse the pointer is of the base type,
                    //  otherwise a memory leak occurs:
                    //  base class is destroyed, but derived class is still floating in memory

    B b4;
    std::cout << usePolymorficTypeByValue(b4) << std::endl;
    std::cout << usePolymorficTypeReference(b4) << std::endl;
    std::cout << usePolymorficTypeByPointer(&b4) << std::endl;

    return 0;
}