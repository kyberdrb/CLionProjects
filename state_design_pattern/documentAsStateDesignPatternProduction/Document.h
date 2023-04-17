//
// Created by AndrejŠišila on 3/30/2023.
//

#pragma once

#include "User.h"
#include "Draft.h"
#include "Transition.h"

#include <memory>

namespace production {
    class State;

    class Document {
    public:
        explicit Document(User& currentUser) :
                _currentUser(currentUser)
                , _currentState(std::make_unique<Draft>(*this))
        {}

        void publish();
        void returnDocAfterReview();
        void expire();

        void changeState(std::unique_ptr<State> state, std::string transitionType);

        const User& getCurrentUser() const;
        void changeUser(const User& otherUser);

        std::string dividerBeforeChangingPublisher() const;
        std::string whoIsPublishingDocument() const;

        // Reports starting state after creating the state machine
        std::string getInitialState() const;

        std::string getTransitionDetails() const;

    private:
        User& _currentUser;
        std::unique_ptr<State> _currentState;
        std::unique_ptr<State> _previousState;
        std::unique_ptr<Transition> transition;
    };
}
