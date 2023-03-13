//
// Created by AndrejŠišila on 3/9/2023.
//

#include "Draft.h"

#include "Document.h"
#include "Moderation.h"

#include <ostream>

void Draft::publish() {
    // We need to '#include "Document.h"' in order to call the 'changeState' function
    //  because we're dereferencing a forward declared type 'Document', which is incomplete
    //  and produces following errors:
    //    error: invalid use of incomplete type ‘class Document’
    //    note: forward declaration of ‘class Document’
//    this->_document.changeState();
    State::_document.changeState(std::make_unique<Moderation>(State::_document));

//    this->_document.changeState(std::make_unique<Moderation>());
}

void Draft::streamOutputOperator(std::ostream& out) const {
    out << "draft";
}