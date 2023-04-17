//
// Created by AndrejŠišila on 3/30/2023.
//

#include "Document.h"

#include <sstream>

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

    void Document::changeState(std::unique_ptr<State> state, std::string transitionType) {
        this->_previousState = std::move(this->_currentState);
        this->_currentState = std::move(state);
        this->transition = std::make_unique<Transition>(transitionType, *(this->_previousState), *(this->_currentState));
    }

    const User& Document::getCurrentUser() const {
        return this->_currentUser;
    }

    void Document::changeUser(const User& otherUser) {
        this->_currentUser = otherUser;
    }

    std::string Document::dividerBeforeChangingPublisher() const {
        return "...\n";
    }

    std::string Document::whoIsPublishingDocument() const {
        std::stringstream message;
        message
                << this->getCurrentUser()
                << " is publishing a document"
                << '\n';

        return message.str();
    }

    std::string Document::getInitialState() const {
        std::stringstream message;
        message << "Initial state:\t\t\t" << *(this->_currentState) << '\n';
        return message.str();
    }

    std::string Document::getTransitionDetails() const {
        std::stringstream message;
        message << *(this->transition);
        return message.str();
    }
}
