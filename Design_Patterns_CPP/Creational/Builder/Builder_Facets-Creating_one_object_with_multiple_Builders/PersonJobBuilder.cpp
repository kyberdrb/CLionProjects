#include "PersonJobBuilder.h"

PersonJobBuilder::PersonJobBuilder(Person &person) : PersonBuilderBase(person) {}

typedef PersonJobBuilder Self;

Self& PersonJobBuilder::at(const std::string& company_name) {
    person.company_name = company_name;
    return *this;
}

Self& PersonJobBuilder::as_a(const std::string& position) {
    person.position = position;
    return *this;
}

Self& PersonJobBuilder::earning(uint_fast32_t annual_income){
    person.annual_income = annual_income;
    return *this;
}
