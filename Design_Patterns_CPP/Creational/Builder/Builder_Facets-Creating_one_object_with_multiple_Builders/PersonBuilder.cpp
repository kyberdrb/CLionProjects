//
// Created by laptop on 8/3/19.
//

#include "PersonBuilder.h"
#include "PersonJobBuilder.h"

PersonBuilderBase::PersonBuilderBase(Person &person) : person(person) {}

PersonBuilder::PersonBuilder() : PersonBuilderBase(p) {}

PersonAddressBuilder PersonBuilderBase::lives() const {
    return PersonAddressBuilder{person};
}

PersonJobBuilder PersonBuilderBase::works() const {
    return PersonJobBuilder(person);
}
