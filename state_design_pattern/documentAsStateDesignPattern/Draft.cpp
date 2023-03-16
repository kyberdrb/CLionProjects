//
// Created by AndrejŠišila on 3/9/2023.
//

#include "Draft.h"

#include "Document.h"
#include "Moderation.h"
#include "Published.h"

#include <ostream>

void Draft::publish() {
    if (State::_document.getCurrentUser().isAdmin()) {
        State::_document.changeState(std::make_unique<Published>(State::_document));
        return;
    }
    // We need to '#include "Document.h"' in order to call the 'changeState' function
    //  because we're dereferencing a forward declared type 'Document', which is incomplete
    //  and produces following errors:
    //    error: invalid use of incomplete type ‘class Document’
    //    note: forward declaration of ‘class Document’
    State::_document.changeState(std::make_unique<Moderation>(State::_document));

    // Accessing the '_document' attribute in the parent/base class via 'this' pointer is working equivalently:
//    this->_document.changeState(std::make_unique<Moderation>());
}

void Draft::returnDocAfterReview() {
    State::_document.changeState(std::make_unique<Draft>(State::_document));
}

void Draft::expire() {
    State::_document.changeState(std::make_unique<Draft>(State::_document));
}

void Draft::streamOutputOperator(std::ostream& out) const {
    out << "draft";
}