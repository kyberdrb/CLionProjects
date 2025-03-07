#pragma once

#include <format>
#include <iosfwd>
#include <memory>
#include <string>
#include <string_view>

class FluentBuilder {
public:
    static FluentBuilder create();
    FluentBuilder& withNumber(uint32_t something);
    FluentBuilder& withText(std::string somethingElse);
    
    static std::unique_ptr<FluentBuilder> createUnique();
    FluentBuilder& withUniqueNumber(uint32_t something);
    FluentBuilder& withUniqueText(std::string somethingElse);

    // std::unique_ptr<FluentBuilder> addSomethingUnique(uint32_t something) &&;
    // std::unique_ptr<FluentBuilder> addSomethingElseUnique(std::string somethingElse) &&;

    std::string str() const; // for std::print("{}", somethingToBuild);
    friend std::ostream& operator<<(std::ostream& out, const FluentBuilder& fooBuilder); // for std::cout << somethingToBuild;

private:
    FluentBuilder() :
        _something(0),
        _somethingElse(std::string{})
    {};

    int _something;
    std::string _somethingElse;
};
