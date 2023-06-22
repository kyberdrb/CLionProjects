//
// Created by AndrejŠišila on 3/30/2023.
//

#pragma once

#include "User.h"
#include "States.h"
#include "Transition.h"

#include <memory>

namespace production {
    class State;

    class Document {
    public:
        explicit Document(User& currentUser) :
                _currentUser(currentUser)
                ,states(std::make_unique<States>(*this))
                ,_currentState(states->getDraftState())
                ,_previousState(states->getInitialState())
                ,transition(std::make_unique<Transition>(this->_previousState, this->_currentState))
        {}

        void publish();
        void returnDocAfterReview();
        void expire();

        States& getStates();

        void changeStateTo(State& state);

        const User& getCurrentUser() const;
        void changeUser(const User& otherUser);

        std::string dividerBeforeChangingPublisher() const;
        std::string whoIsPublishingDocument() const;

        std::string getTransitionDetails() const;

    private:
        User& _currentUser;
        std::unique_ptr<States> states;
        std::reference_wrapper<State> _currentState;
        std::reference_wrapper<State> _previousState;
        std::unique_ptr<Transition> transition;
    };
}
