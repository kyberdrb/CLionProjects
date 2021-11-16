//
// Created by laptop on 8/3/19.
//

#include "Person.h"

std::ostream &operator<<(std::ostream &os, const Person &person) {
    os <<
        "street_address: " << person.street_address <<
        " post_code: " << person.post_code <<
        " city: " << person.city <<
        " company_name: " << person.company_name <<
        " position: " << person.position <<
        " annual_income: " << person.annual_income;
    return os;
}
