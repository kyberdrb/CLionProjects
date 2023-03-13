#pragma once

#include <string>

namespace ifElseStateMachine {
    class User {
    public:
        std::string role;

        friend std::ostream &operator<<(std::ostream &out, const User &user);
    };

    inline std::ostream &operator<<(std::ostream &out, const User &user) {
        out << user.role;
        return out;
    }

    class DocumentAsIfElseStateMachine {
    public:
        DocumentAsIfElseStateMachine(User currentUser) :
                state("draft"),
                _currentUser(currentUser) {}

        void publish();

        void switchCurrentUser(User user);

        std::string state;
        User _currentUser;
    };
}