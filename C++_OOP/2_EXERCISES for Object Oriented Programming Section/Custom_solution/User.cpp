//
// Created by laptop on 7/10/19.
//

#include "User.h"

const std::string &User::getName() const {
    return name;
}

const std::string &User::getLastName() const {
    return lastName;
}

User::User(
        const std::string &name, 
        const std::string &lastName) 
        : 
        name(name), 
        lastName(lastName) {}

User::~User() {

}
