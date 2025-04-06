#pragma once

#include <format>
#include <iosfwd>
#include <memory>
#include <string>

class FluentBuilder {
public:
    static FluentBuilder create();
    // static constexpr FluentBuilder create(); // TODO make create() constexpr to construct Builder at compile time

    FluentBuilder& withNumber(int32_t something);
    FluentBuilder& withText(std::string somethingElse);
    
    static std::unique_ptr<FluentBuilder> createUnique();
    FluentBuilder& withUniqueNumber(int32_t something);
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

    // TODO make constructor constexpr for constexpr create()
    // constexpr FluentBuilder() :
    //     _something(0),
    //     _somethingElse(std::string{})
    // {};

    int32_t _something;
    std::string _somethingElse;
};
