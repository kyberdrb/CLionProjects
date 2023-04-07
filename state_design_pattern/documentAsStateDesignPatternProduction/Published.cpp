//
// Created by laptop on 4/7/23.
//

#include "Published.h"

namespace production {
    void Published::publish() {
        State::_document.changeState(std::make_unique<Published>(State::_document));
    }
    
    void Published::returnDocAfterReview() {
        State::_document.changeState(std::make_unique<Published>(State::_document));
    }
    
    void Published::expire() {
        State::_document.changeState(std::make_unique<Draft>(State::_document));
    }
    
    void Published::streamOutputOperator(std::ostream& out) const {
        out << "published";
    }
}
