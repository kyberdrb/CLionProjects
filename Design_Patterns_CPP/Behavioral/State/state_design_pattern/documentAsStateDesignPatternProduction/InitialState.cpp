//
// Created by admin on 21. 6. 2023.
//

#include "InitialState.h"

#include "Document.h"

namespace production {
    void InitialState::publishImplementation() {
        State::_document.changeStateTo(State::_document.getStates().getInitialState());
    }

    void InitialState::returnDocAfterReviewImplementation() {
        State::_document.changeStateTo(State::_document.getStates().getInitialState());
    }

    void InitialState::expireImplementation() {
        State::_document.changeStateTo(State::_document.getStates().getInitialState());
    }

    void InitialState::streamOutputOperator(std::ostream& out) const {
        out << "init";
    }
}
