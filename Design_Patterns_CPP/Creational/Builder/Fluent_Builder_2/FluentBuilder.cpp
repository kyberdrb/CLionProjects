#include "FluentBuilder.h"

#include <iostream>

FluentBuilder FluentBuilder::create() {
    return FluentBuilder{};
}

FluentBuilder& FluentBuilder::withNumber(uint32_t something) {
    this->_something = something;
    return *this;
}

FluentBuilder& FluentBuilder::withText(std::string somethingElse) {
    this->_somethingElse = std::move(somethingElse);
    return *this;
}

std::unique_ptr<FluentBuilder> FluentBuilder::createUnique() {
    struct FluentBuilder_make_unique_compatible : FluentBuilder {};
    return std::make_unique<FluentBuilder_make_unique_compatible>();
}

// std::unique_ptr<FluentBuilder> FluentBuilder::addSomethingUnique(uint32_t something) && {
//     this->_something = something;
//     return std::unique_ptr<FluentBuilder>(this);
// }

// std::unique_ptr<FluentBuilder> FluentBuilder::addSomethingElseUnique(std::string somethingElse) && {
//     this->_somethingElse = std::move(somethingElse);
//     return std::unique_ptr<FluentBuilder>(this);
// }

FluentBuilder& FluentBuilder::withUniqueNumber(uint32_t something) {
    this->_something = something;
    return *this;
}

FluentBuilder& FluentBuilder::withUniqueText(std::string somethingElse) {
    this->_somethingElse = std::move(somethingElse);
    return *this;
}

std::string FluentBuilder::str() const {
    return std::format("{}; {}", this->_something, this->_somethingElse);
}

std::ostream& operator<<(std::ostream& out, const FluentBuilder& fooBuilder) {
    out 
        << fooBuilder._something
        << "; "
        << fooBuilder._somethingElse;
    return out;
}
