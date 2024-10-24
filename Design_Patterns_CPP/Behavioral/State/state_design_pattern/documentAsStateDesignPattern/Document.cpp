//
// Created by AndrejŠišila on 3/9/2023.
//

#include "Document.h"

void Document::publish() {
    this->_state->publish();
}

void Document::returnDocAfterReview() {
    this->_state->returnDocAfterReview();
}

void Document::expire() {
    this->_state->expire();
}

void Document::changeState(std::unique_ptr<State> state) {
    this->_state = std::move(state);
}

const User& Document::getCurrentUser() const {
    return this->_currentUser;
}

const State& Document::getCurrentState() const {
    return *(this->_state);
}
