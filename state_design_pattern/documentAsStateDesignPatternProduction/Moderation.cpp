//
// Created by laptop on 4/6/23.
//

#include "Moderation.h"

#include "Document.h"

#include <iostream>

namespace production {
    void Moderation::publishImplementation() {
        if (State::_document.getCurrentUser().isAdmin()) {
            State::_document.changeStateTo(State::_document.getStates().getPublishedState());
            return;
        }

        State::_document.changeStateTo(State::_document.getStates().getModerationState());
    }

    void Moderation::returnDocAfterReviewImplementation() {
        State::_document.changeStateTo(State::_document.getStates().getDraftState());
    }

    void Moderation::expireImplementation() {
        State::_document.changeStateTo(State::_document.getStates().getModerationState());
    }

    void Moderation::streamOutputOperator(std::ostream& out) const {
        out << "moderation";
    }
}
