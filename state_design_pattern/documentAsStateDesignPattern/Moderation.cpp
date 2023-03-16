//
// Created by laptop on 3/12/23.
//

#include "Moderation.h"

#include "Document.h"
#include "Published.h"

#include <ostream>

void Moderation::publish() {
    State::_document.changeState(std::make_unique<Published>(State::_document));
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
