#include "Derived.h"

#include <cassert>
#include <iostream>
#include <memory>

int main() {
    std::cout << "State Design Pattern\n\n";

    int wholeNumber = 1;
    std::unique_ptr<Base> derived = std::make_unique<Derived>(wholeNumber);

    std::cout << "Is reference variable inside an abstract class 'Base' initialized via its derived class 'Derived'?\n";
    std::cout << "derived->_numberReference = " << derived->_numberReference << '\n';
    assert(derived->_numberReference == 1);
    std::cout << "The variable inside the abstract class 'Base' had been correctly initialized via its derived class 'Derived'.\n";

    std::cout << "\n";

    derived->modifyReferenceInternalState();

    std::cout << "\n\n";

    std::cout << "Has the value of reference variable inside the abstract class changed by the message from derived class 'Derived'?\n";
    std::cout << "derived->_numberReference = " << derived->_numberReference << '\n';
    assert(derived->_numberReference != 1);
    std::cout << "The value of reference variable inside the abstract class had changed by the message from derived class 'Derived'.\n";

    std::cout << "\n";
    return 0;
}
