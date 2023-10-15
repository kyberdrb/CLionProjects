//
// Created by AndrejŠišila on 3/30/2023.
//

#include "State.h"

#include "Document.h"

namespace production {
    void State::publish() {
        this->transitionType = TransitionType::PUBLISH;
        this->publishImplementation();
    }

    void State::returnDocAfterReview() {
        this->transitionType = TransitionType::RETURN_DOC_AFTER_REVIEW;
        this->returnDocAfterReviewImplementation();
    }

    void State::expire() {
        this->transitionType = TransitionType::EXPIRE;
        this->expireImplementation();
    }
}
