//
// Created by laptop on 3/12/23.
//

#include "Published.h"

#include "Document.h"

#include <ostream>

void Published::publish() {
    State::_document.changeState(std::make_unique<Published>(State::_document));
}

void Published::streamOutputOperator(std::ostream& out) const {
    out << "published";
}
