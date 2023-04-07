//
// Created by laptop on 4/6/23.
//

#include "Moderation.h"

#include "Document.h"
#include "Published.h"

#include <iostream>

namespace production {
    void Moderation::publish() {
        if (State::_document.getCurrentUser().isAdmin()) {
            State::_document.changeState(std::make_unique<Published>(State::_document));
            return;
        }

        State::_document.changeState(std::make_unique<Moderation>(State::_document));
    }

    void Moderation::returnDocAfterReview() {
        State::_document.changeState(std::make_unique<Draft>(State::_document));
    }

    void Moderation::expire() {
        State::_document.changeState(std::make_unique<Moderation>(State::_document));
    }

    void Moderation::streamOutputOperator(std::ostream& out) const {
        out << "moderation";
    }
}
