//
// Created by laptop on 8/3/19.
//

#ifndef BUILDER_FACETS_CREATING_ONE_OBJECT_WITH_MULTIPLE_BUILDERS_PERSONBUILDER_H
#define BUILDER_FACETS_CREATING_ONE_OBJECT_WITH_MULTIPLE_BUILDERS_PERSONBUILDER_H


#include "Person.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

class PersonBuilderBase {
protected:
    Person& person;

public:
    PersonBuilderBase(Person& person);

    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;

    operator Person() const {
        return std::move(person);
    }
};

class PersonBuilder : public PersonBuilderBase {
    Person p;

public:
    PersonBuilder();
};


#endif //BUILDER_FACETS_CREATING_ONE_OBJECT_WITH_MULTIPLE_BUILDERS_PERSONBUILDER_H
