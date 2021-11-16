//
// Created by laptop on 7/21/19.
//

#include "Test.h"

Test::Test(const Test &otherTest) {
    std::cout << "Copy constructor 'Test' called" << std::endl << std::flush;
    this->id = otherTest.id;
    this->name = otherTest.name;
}

const Test& Test::operator=(const Test& otherTest) {
    std::cout << "Assignment operator '=' called" << std::endl << std::flush;
    this->id = otherTest.id;
    this->name = otherTest.name;
    return *this;
}

void Test::print() const {
    std::cout << this->id << ": " << this->name << std::endl << std::flush;
}

std::ostream& operator<<(std::ostream& out, const Test& test) {
    out << test.id << "; " << test.name;
    return out;
}
