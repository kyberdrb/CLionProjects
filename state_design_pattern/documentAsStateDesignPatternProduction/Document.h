//
// Created by AndrejŠišila on 3/30/2023.
//

#pragma once

#include "User.h"
//#include "Draft.h"
//#include "InitialState.h"
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
//                , _currentState(std::make_unique<Draft>(*this))
                , _currentState(states->getDraftState())
//                , _currentState(States::getDraftState())

//                , _previousState(std::make_unique<InitialState>(*this))
                , _previousState(states->getInitialState())
        {}

        void publish();
        void returnDocAfterReview();
        void expire();

        States& getStates();

//        void changeStateTo(std::unique_ptr<State> state);
        void changeStateTo(State& state);

        const User& getCurrentUser() const;
        void changeUser(const User& otherUser);

        std::string dividerBeforeChangingPublisher() const;
        std::string whoIsPublishingDocument() const;

        // Reports starting state after creating the state machine
        std::string getInitialState() const;

        std::string getTransitionDetails() const;

//        Document& operator=(const Document&);

    private:
        User& _currentUser;
        std::unique_ptr<States> states;
//        std::unique_ptr<State> _currentState;
//        State& _currentState;
        std::reference_wrapper<State> _currentState;
//        std::unique_ptr<State> _previousState;
//        State& _previousState;
        std::reference_wrapper<State> _previousState;
        std::unique_ptr<Transition> transition;
    };
}
