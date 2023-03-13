#include "DocumentAsIfElseStateMachine.h"

using namespace ifElseStateMachine;

void DocumentAsIfElseStateMachine::publish() {
    if (this->state == "draft") {
        state = "moderation";
    }

    if (this->state == "moderation") {
        if (this->_currentUser.role == "admin") {
            state = "published";
        }
    }

    if (this->state == "published") {
        // Do nothing.
    }
}

void DocumentAsIfElseStateMachine::switchCurrentUser(User user) {
    this->_currentUser = user;
}