#include <iostream>
#include "Person.h"
#include "PersonBuilder.h"

int main() {
    Person p = Person::create()
        .lives()
            .at("123 London Road")
            .with_postcode("24689")
            .in("London")
        .works()
            .at("PragmaSoft")
            .as_a("Consultant")
            .earning(10e6);

    std::cout << p << std::endl;

    return 0;
}