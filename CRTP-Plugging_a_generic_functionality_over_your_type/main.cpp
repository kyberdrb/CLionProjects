#include <iostream>
#include <string>

// Mixin Classes: The Yang of the CRTP - The CRTP upside down: ...the whole implementation of the solution using the CRTP.
// https://www.fluentcpp.com/2017/12/12/mixin-classes-yang-crtp/

// The Mixin and CRTP remind me of the Adapter and Decorator design pattern

template <typename Printable>
class RepeatPrint {
public:
    void repeat(unsigned int times) const {
        for (int i = 0; i < times; ++i) {
            static_cast<const Printable&>(*this).print();   // the method is const, therefore the template parameter in the static_cast
                                                            // also needs to be const
        }
    }
};

class Name : public RepeatPrint<Name> {
    std::string firstName;
    std::string lastName;

public:
    Name(std::string firstName,std::string secondName) :
            firstName(std::move(firstName)), lastName(std::move(secondName)) {}

    void print() const {
        std::cout << this->firstName << " " << this->lastName << "\n";
    }
};

int main() {
    Name name("Hey", "You");
    name.repeat(10);
    return 0;
}
