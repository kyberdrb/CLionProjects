//
// Created by AndrejŠišila on 3/30/2023.
//

#include "Draft.h"

#include "Document.h"

namespace production {
    void Draft::publishImplementation() {
        if (State::_document.getCurrentUser().isAdmin()) {
            State::_document.changeStateTo(State::_document.getStates().getPublishedState());
            return;
        }

        // We need to '#include "Document.h"' in order to call the 'changeStateTo' function
        //  because we're dereferencing a forward declared type 'Document', which is incomplete
        //  and produces following errors:
        //    error: invalid use of incomplete type ‘class Document’
        //    note: forward declaration of ‘class Document’
        State::_document.changeStateTo(State::_document.getStates().getModerationState());

        // Accessing the '_document' attribute in the parent/base class via 'this' pointer is working equivalently:
//        this->_document.changeStateTo(State::_document.getStates().getModerationState());
    }

    void Draft::returnDocAfterReviewImplementation() {
        State::_document.changeStateTo(State::_document.getStates().getDraftState());
    }

    void Draft::expireImplementation() {
        State::_document.changeStateTo(State::_document.getStates().getDraftState());
    }

    void Draft::streamOutputOperator(std::ostream& out) const {
        out << "draft";
    }
}
