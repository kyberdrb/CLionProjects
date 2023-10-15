//
// Created by laptop on 4/7/23.
//

#include "Published.h"

namespace production {
    void Published::publishImplementation() {
        State::_document.changeStateTo(State::_document.getStates().getPublishedState());
    }
    
    void Published::returnDocAfterReviewImplementation() {
        State::_document.changeStateTo(State::_document.getStates().getPublishedState());
    }
    
    void Published::expireImplementation() {
        State::_document.changeStateTo(State::_document.getStates().getDraftState());
    }
    
    void Published::streamOutputOperator(std::ostream& out) const {
        out << "published";
    }
}
