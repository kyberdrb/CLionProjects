#ifndef BUILDER_FACETS_CREATING_ONE_OBJECT_WITH_MULTIPLE_BUILDERS_PERSONJOBBUILDER_H
#define BUILDER_FACETS_CREATING_ONE_OBJECT_WITH_MULTIPLE_BUILDERS_PERSONJOBBUILDER_H


#include "PersonBuilder.h"

class PersonJobBuilder : public PersonBuilderBase {
public:
    explicit PersonJobBuilder(Person& person);

    typedef PersonJobBuilder Self;
    Self& at(const std::string&);
    Self& as_a(const std::string&);
    Self& earning(uint_fast32_t);
};


#endif //BUILDER_FACETS_CREATING_ONE_OBJECT_WITH_MULTIPLE_BUILDERS_PERSONJOBBUILDER_H
