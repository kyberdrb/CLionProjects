//
// Created by laptop on 4/7/23.
//

#include "Published.h"

namespace production {
    void Published::publishImplementation() {
        State::_document.changeStateTo(std::make_unique<Published>(State::_document));
    }
    
    void Published::returnDocAfterReviewImplementation() {
        State::_document.changeStateTo(std::make_unique<Published>(State::_document));
    }
    
    void Published::expireImplementation() {
        State::_document.changeStateTo(std::make_unique<Draft>(State::_document));
    }
    
    void Published::streamOutputOperator(std::ostream& out) const {
        out << "published";
    }
}
