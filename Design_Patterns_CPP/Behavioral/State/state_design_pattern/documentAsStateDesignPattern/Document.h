//
// Created by AndrejŠišila on 3/9/2023.
//

#pragma once

#include "User.h"

//#include "State.h"
class State;    // Cyclic/Circular dependency / cyclic header include: Document includes State AND State includes Document
                //  Using forward declaration of 'State' instead of include
                //  Forward declaration breaks the cycle and lets the code compile.

#include "Draft.h"

#include <memory>

// The 'Context' class equivalent in the reference State design pattern UML class diagram
class Document {
public:
    explicit Document(User& currentUser) :
            _currentUser(currentUser),
            _state(std::make_unique<Draft>(*this))
    {}

    void publish();
    void returnDocAfterReview();
    void expire();

    void changeState(std::unique_ptr<State> state);

    const User& getCurrentUser() const;
    const State& getCurrentState() const;

private:
    User& _currentUser;
    std::unique_ptr<State> _state;
};
