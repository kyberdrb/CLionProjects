//
// Created by laptop on 4/6/23.
//

#include "Moderation.h"

#include "Document.h"
#include "Published.h"
#include "TransitionType.h"

#include <iostream>

namespace production {
    void Moderation::publishImplementation() {
        if (State::_document.getCurrentUser().isAdmin()) {
            State::_document.changeState(std::make_unique<Published>(State::_document));
            return;
        }

        State::_document.changeState(std::make_unique<Moderation>(State::_document));
    }

    void Moderation::returnDocAfterReviewImplementation() {
        State::_document.changeState(std::make_unique<Draft>(State::_document));
    }

    void Moderation::expireImplementation() {
        State::_document.changeState(std::make_unique<Moderation>(State::_document));
    }

    void Moderation::streamOutputOperator(std::ostream& out) const {
        out << "moderation";
    }
}
