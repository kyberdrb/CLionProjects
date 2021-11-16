#include <iostream>
#include <string>

// Mixin Classes: The Yang of the CRTP - Plugging a generic functionality over your type: https://www.fluentcpp.com/2017/12/12/mixin-classes-yang-crtp/

class Name {
    std::string firstName;
    std::string lastName;

public:
    Name(std::string firstName, std::string lastName) :
        firstName(std::move(firstName)), lastName(std::move(lastName)) {}

    Name(const Name& name) = default;

    void print() const {
        std::cout << this->firstName << " " << this->lastName << "\n";
    }
};

template <typename Printable>
class RepeatPrint : public Printable {
public:
    RepeatPrint(const Printable& printable) :
        Printable(printable) {}                 // creating an anonymous instance of the template type in the initialization list by the copy constructor of the template type?

    void repeat(unsigned int times) const {
        for (int i = 0; i < times; ++i) {
            this->print();
        }
    }
};

template <typename Printable>
RepeatPrint<Printable> repeatPrint(const Printable& printable) {
    return RepeatPrint<Printable>(printable);
}

int main() {
    Name name("Enjoy", "de Play");
    repeatPrint(name).repeat(10);
    return 0;
}
