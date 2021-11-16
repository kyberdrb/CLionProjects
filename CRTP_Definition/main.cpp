#include <iostream>
#include <memory>
// The Curiously Recurring Template Pattern (CRTP) - Definition: https://www.fluentcpp.com/2017/05/12/curiously-recurring-template-pattern/

template <typename Derived>
class Base {
public:
    void doSomething() {
        Derived& derived = static_cast<Derived&>(*this);
        derived.doSomething();
        std::cout << "FooBsr" << std::endl;
    }

private:
    Base() = default;
    friend Derived;
};

class Derived : public Base<Derived> {
public:
    void doSomething() {    // if the Derived class has a function with the same signature as the Base class,
                            // then the Derived class hides this function in the Base class.
                            // Hiding - using function from the Derived class:
                            //  auto d = std::make_unique<Derived>();
                            //  d->doSomething();
                            // Exposing - using function from the Base class
                            //  std::unique_ptr<Base<Derived>> dd = std::make_unique<Derived>();
                            //  dd->doSomething();
        std::cout << "Blable" << std::endl;
    }
};

class Derived_1 : public Base<Derived_1> {

};

class Derived_2 : public Base<Derived_2> {  // Achtung, one derived class inherits from a base class with a template parameter
                                            // of another class, i.e. derived class and class in the template argument of the base class differ
                                            // e.g.:
                                            //      class Derived_2 : Base<Derived_1>
                                            // At instantiation of such class
                                            //  auto d2 = std::make_unique<Derived_2>();
                                            // we'll see an error message
                                            //  error: use of deleted function ‘Derived_2::Derived_2()’
                                            // because the constructor of 'the other' class in the template parameter is used for the original derived class,
                                            // and the constructor for the original derived class is therefore hidden :)
                                            // How to fix it?
                                            //  Replace the class in the template paramenter with the derived class itself.
                                            // How to prevent it?
                                            //  The prevention consists of making the constructor in the Base class private and
                                            // making the derived class from the template argument in the Base class a friend


};

int main() {
    std::cout << "Hello, World!" << std::endl;

    auto d1 = std::make_unique<Derived_1>();
    auto d2 = std::make_unique<Derived_2>();

    auto d = std::make_unique<Derived>();
    d->doSomething();

    std::cout << std::endl;

    std::unique_ptr<Base<Derived>> dd = std::make_unique<Derived>();
    dd->doSomething();
    return 0;
}
