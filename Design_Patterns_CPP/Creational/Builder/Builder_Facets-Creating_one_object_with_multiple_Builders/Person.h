//
// Created by laptop on 8/3/19.
//

#ifndef BUILDER_FACETS_CREATING_ONE_OBJECT_WITH_MULTIPLE_BUILDERS_PERSON_H
#define BUILDER_FACETS_CREATING_ONE_OBJECT_WITH_MULTIPLE_BUILDERS_PERSON_H


#include <string>
#include <ostream>

class PersonBuilder;

class Person {
    std::string street_address, post_code, city;

    std::string company_name, position;
    uint_fast32_t annual_income;

public:
    static PersonBuilder create();

    friend std::ostream &operator<<(std::ostream &os, const Person &person);

    friend class PersonBuilder;
    friend class PersonAddressBuilder;
    friend class PersonJobBuilder;
};


#endif //BUILDER_FACETS_CREATING_ONE_OBJECT_WITH_MULTIPLE_BUILDERS_PERSON_H
