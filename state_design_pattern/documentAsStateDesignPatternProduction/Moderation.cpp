//
// Created by laptop on 4/6/23.
//

#include "Moderation.h"

#include "Document.h"
#include "Published.h"
#include "TransitionType.h"

#include <iostream>

namespace production {
    void Moderation::publish() {
        if (State::_document.getCurrentUser().isAdmin()) {
            State::_document.changeState(std::make_unique<Published>(State::_document), TransitionType::PUBLISH);
            return;
        }

        State::_document.changeState(std::make_unique<Moderation>(State::_document), TransitionType::PUBLISH);
    }

    void Moderation::returnDocAfterReview() {
        State::_document.changeState(std::make_unique<Draft>(State::_document), TransitionType::RETURN_DOC_AFTER_REVIEW);
    }

    void Moderation::expire() {
        State::_document.changeState(std::make_unique<Moderation>(State::_document), TransitionType::EXPIRE);
    }

    void Moderation::streamOutputOperator(std::ostream& out) const {
        out << "moderation";
    }
}
