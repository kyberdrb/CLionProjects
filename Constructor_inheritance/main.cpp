#include <iostream>
#include <string>

using std::cout;
using std::endl;

// inspired by "~/CLionProjects/Safe_Typecasting_CPP"
// https://stackoverflow.com/questions/9979194/what-is-constructor-inheritance/9979249#9979249

class Base {
public:
    Base(int number) : number(number) {}
    Base (std::string text) : text(std::move(text)) {}

    int getNumber() const {
        return number;
    }

    std::string getText() const {
        return text;
    }

    virtual void doSomething() {};

    virtual ~Base() = default;

private:
    int number;
    std::string text;
};

class Derived : public Base {
    using Base::Base;   // inherit all constructors from Base class
                        // doesn't matter in which section it is; it can be in the private, public or protected section too

public:

    virtual void doSomething() override {
        cout << "derived is doing something" << endl;
    }
};

class DeepDerived : public Derived {
public:
    //using Base::Base;   // Compiler: error: cannot inherit constructors from indirect base ‘Base’
                        // Syntax checker: Base is not a direct base of DeepDerived; cannot inherit constructors

    using Derived::Derived;

    void doSomething() override {
        cout << "deep derived is doing something" << endl;
    }
};

int main() {
//    Base* base = new Base();    // error: invalid new-expression of abstract class type ‘Base’
//    Base* derived = new Derived(); // no default constructor in Base class: error: use of deleted function ‘Derived::Derived()’
//    Base* deepDerived = new DeepDerived;    // error: use of deleted function ‘DeepDerived::DeepDerived()’

    Base* derived = new Derived(5); // works because of 'using' declaration in Derived class which makes the
                                            // constructors in the Base class accessible from the derived classes
    cout << "derived number\t" << derived->getNumber() << endl;
    derived->doSomething();

    cout << endl;

    Base* deepDerived = new DeepDerived("foo"); // error: no matching function for call to ‘DeepDerived::DeepDerived(int)’
    cout << "deep derived text\t" << deepDerived->getText() << endl;
    deepDerived->doSomething();

    delete deepDerived;
    delete derived;

    return 0;
}
