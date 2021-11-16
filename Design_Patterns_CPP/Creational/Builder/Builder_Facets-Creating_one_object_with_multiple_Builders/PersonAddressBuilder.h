#ifndef BUILDER_FACETS_CREATING_ONE_OBJECT_WITH_MULTIPLE_BUILDERS_PERSONADDRESSBUILDER_H
#define BUILDER_FACETS_CREATING_ONE_OBJECT_WITH_MULTIPLE_BUILDERS_PERSONADDRESSBUILDER_H


#include "PersonBuilder.h"
#include "Person.h"


class PersonAddressBuilder : public PersonBuilderBase {
public:
    PersonAddressBuilder(Person& person);

    typedef PersonAddressBuilder Self;
    Self& at(const std::string&);
    Self& with_postcode(const std::string&);
    Self& in(const std::string&);
};

PersonBuilder Person::create() {
    return PersonBuilder();
}


#endif //BUILDER_FACETS_CREATING_ONE_OBJECT_WITH_MULTIPLE_BUILDERS_PERSONADDRESSBUILDER_H
