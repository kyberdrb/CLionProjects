//
// Created by laptop on 4/7/23.
//

#include "Published.h"
#include "TransitionType.h"

namespace production {
    void Published::publish() {
        State::_document.changeState(std::make_unique<Published>(State::_document), TransitionType::PUBLISH);
    }
    
    void Published::returnDocAfterReview() {
        State::_document.changeState(std::make_unique<Published>(State::_document), TransitionType::RETURN_DOC_AFTER_REVIEW);
    }
    
    void Published::expire() {
        State::_document.changeState(std::make_unique<Draft>(State::_document), TransitionType::EXPIRE);
    }
    
    void Published::streamOutputOperator(std::ostream& out) const {
        out << "published";
    }
}
