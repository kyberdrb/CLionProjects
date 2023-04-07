//
// Created by AndrejŠišila on 3/30/2023.
//

#include "Document.h"

namespace production {
    void Document::publish() {
        this->_currentState->publish();
    }

    void Document::returnDocAfterReview() {
        this->_currentState->returnDocAfterReview();
    }

    void Document::expire() {
        this->_currentState->expire();
    }

    void Document::changeState(std::unique_ptr<State> state) {
        this->_previousState = std::move(this->_currentState);
        this->_currentState = std::move(state);
    }

    void Document::getStateChange() const {
        std::cout << "State change:\t\t\t" << this->getPreviousState() << " -> " << this->getCurrentState() << '\n';
    }

    const User& Document::getCurrentUser() const {
        return this->_currentUser;
    }

    void Document::changeUser(const User& otherUser) {
        this->_currentUser = otherUser;
    }

    const State& Document::getCurrentState() const {
        return *(this->_currentState);
    }

    const State& Document::getPreviousState() const {
        return *(this->_previousState);
    }
}