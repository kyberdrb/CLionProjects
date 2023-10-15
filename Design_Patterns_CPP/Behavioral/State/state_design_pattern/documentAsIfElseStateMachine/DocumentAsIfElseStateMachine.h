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
                _currentUser(currentUser),
                returnedFromReview(false),
                expired(false)
            {}

        void publish();
        void resetSpecialAttributes();

        std::string state;
        User _currentUser;

        bool returnedFromReview;
        bool expired;
    };
}