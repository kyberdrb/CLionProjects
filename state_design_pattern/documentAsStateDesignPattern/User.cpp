//
// Created by AndrejŠišila on 3/9/2023.
//

#include "User.h"

bool User::isAdmin() const {
    return this->role == "admin";
}
