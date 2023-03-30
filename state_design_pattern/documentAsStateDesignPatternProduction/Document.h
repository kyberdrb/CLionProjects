//
// Created by AndrejŠišila on 3/30/2023.
//

#pragma once

#include "User.h"
#include "Draft.h"

#include <memory>

namespace production {
    class State;

    class Document {
    public:
        explicit Document(User& currentUser) :
                _currentUser(currentUser)
                ,_state(std::make_unique<Draft>(*this))
        {}

        void publish();
        void returnDocAfterReview();
        void expire();

        void changeState(std::unique_ptr<State> state);

        const User& getCurrentUser() const;
        void changeUser(const User& otherUser);

        const State& getCurrentState() const;

    private:
        User& _currentUser;
        std::unique_ptr<State> _state;
    };
}
