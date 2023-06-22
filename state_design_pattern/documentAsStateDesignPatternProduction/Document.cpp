//
// Created by AndrejŠišila on 3/30/2023.
//

#include "Document.h"

#include <sstream>

namespace production {
    void Document::publish() {
        this->_currentState.get().publish();
    }

    void Document::returnDocAfterReview() {
        this->_currentState.get().returnDocAfterReview();
    }

    void Document::expire() {
        this->_currentState.get().expire();
    }

    States& Document::getStates() {
        return *(this->states);
    }

    void Document::changeStateTo(State& state) {
        this->_previousState = this->_currentState;
        this->_currentState = state;
        this->transition = std::make_unique<Transition>(this->_previousState, this->_currentState);
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

    std::string Document::getTransitionDetails() const {
        std::stringstream out;

        out << "Transition type: ";

        if (this->_previousState.get().getTransitionType() == TransitionType::NONE) {
            out << "initialization";
        }
        if (this->_previousState.get().getTransitionType() == TransitionType::PUBLISH) {
            out << "publish";
        }
        else if (this->_previousState.get().getTransitionType() == TransitionType::RETURN_DOC_AFTER_REVIEW) {
            out << "returnDocAfterReview";
        }
        else if (this->_previousState.get().getTransitionType() == TransitionType::EXPIRE) {
            out << "expire";
        }

        out << '\n';

        out << *(this->transition);

        return out.str();
    }
}
