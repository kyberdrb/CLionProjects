//
// Created by laptop on 4/7/23.
//

#include "Published.h"

namespace production {
    void Published::publish() {
        State::_document.changeState(std::make_unique<Published>(State::_document));
        State::_document.setTransitionType("publish");
    }
    
    void Published::returnDocAfterReview() {
        State::_document.changeState(std::make_unique<Published>(State::_document));
        State::_document.setTransitionType("returnDocAfterReview");
    }
    
    void Published::expire() {
        State::_document.changeState(std::make_unique<Draft>(State::_document));
        State::_document.setTransitionType("ехpire");
    }
    
    void Published::streamOutputOperator(std::ostream& out) const {
        out << "published";
    }
}
