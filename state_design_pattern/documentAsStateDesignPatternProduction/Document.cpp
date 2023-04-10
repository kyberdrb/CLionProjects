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

    void Document::changeState(std::unique_ptr<State> state) {
        this->_previousState = std::move(this->_currentState);
        this->_currentState = std::move(state);
    }

    std::string Document::getStateChange() const {
        std::stringstream message;
        message << "State change:\t\t\t" << this->getPreviousState() << " -> " << this->getCurrentState() << '\n';
        return message.str();
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
        message << "Initial state:\t\t\t" << this->getCurrentState() << '\n';
        return message.str();
    }

    std::string Document::getTransitionDetailsPublish() const {
        std::stringstream message;
        message << "Transition type: publish" << '\n';
        message << this->getStateChange();
        return message.str();
    }

    std::string Document::getTransitionDetailsExpire() const {
        std::stringstream message;
        message << "Transition type: expire" << '\n';
        message << this->getStateChange();
        return message.str();
    }

    std::string Document::getTransitionDetailsReturnDocAfterReview() const {
        std::stringstream message;
        message << "Transition type: returnDocAfterReview" << '\n';
        message << this->getStateChange();
        return message.str();
    }
}
