//
// Created by AndrejŠišila on 3/30/2023.
//

#ifndef STATE_DESIGN_PATTERN_USER_H
#define STATE_DESIGN_PATTERN_USER_H

#include "UserRole.h"

namespace production {
    class User {
    public:
        explicit User(UserRole userRole) :
                _role(userRole)
        {}

    private:
        UserRole _role;
    };

} // production

#endif //STATE_DESIGN_PATTERN_USER_H
