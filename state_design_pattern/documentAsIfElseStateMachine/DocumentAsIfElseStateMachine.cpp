#include "DocumentAsIfElseStateMachine.h"

using namespace ifElseStateMachine;

void DocumentAsIfElseStateMachine::publish() {
    if (this->state == "draft") {
        if (this->_currentUser.role == "admin") {
            state = "published";
            return;
        }

        state = "moderation";
        return;
    }

    if (this->state == "moderation") {
        if (this->_currentUser.role == "admin") {
            state = "published";
            return;
        }

        if (this->returnedFromReview) {
            state = "draft";
            return;
        }
    }

    if (this->state == "published") {
        if (this->expired) {
            state = "draft";
            return;
        }
    }
}

void DocumentAsIfElseStateMachine::resetSpecialAttributes() {
    this->returnedFromReview = false;
    this->expired = false;
}
