#include "PersonAddressBuilder.h"

PersonAddressBuilder::PersonAddressBuilder(Person &person) : PersonBuilderBase(person) {}

typedef PersonAddressBuilder Self;

Self& PersonAddressBuilder::at(const std::string& street) {
    person.street_address = street;
    return *this;
}

Self& PersonAddressBuilder::with_postcode(const std::string& post_code) {
    person.post_code = post_code;
    return *this;
}

Self& PersonAddressBuilder::in(const std::string& city) {
    person.city = city;
    return *this;
}
