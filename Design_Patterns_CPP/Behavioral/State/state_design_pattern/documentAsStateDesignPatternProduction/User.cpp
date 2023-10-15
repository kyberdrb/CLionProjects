//
// Created by AndrejŠišila on 3/30/2023.
//

#include "User.h"

namespace production {
    bool User::isAdmin() const {
        return this->_role == UserRole::ADMIN;
    }
}