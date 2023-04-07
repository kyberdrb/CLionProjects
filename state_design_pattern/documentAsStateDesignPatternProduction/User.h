//
// Created by AndrejŠišila on 3/30/2023.
//

#pragma once

#include "UserRole.h"

#include <iostream>

namespace production {
    class User {
    public:
        explicit User(UserRole userRole) :
                _role(userRole)
        {}

        bool isAdmin() const;

        friend std::ostream& operator<<(std::ostream& out, const User& user) {
            if (user._role == UserRole::USER) {
                out << "user";
            }
            else if (user._role == UserRole::ADMIN) {
                out << "admin";
            }

            return out;
        }

    private:
        UserRole _role;
    };
}
