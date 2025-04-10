//
// Created by AndrejŠišila on 3/30/2023.
//

#pragma once

#include "TransitionType.h"

#include <iosfwd>

namespace production {
    class Document;

    class State {
    public:
        explicit State(Document& document) :
                _document(document),
                transitionType(TransitionType::NONE)
        {}

        void publish();
        void returnDocAfterReview();
        void expire();

        TransitionType getTransitionType() const {
            return this->transitionType;
        }

        virtual ~State() = default;

        friend std::ostream& operator<<(std::ostream& out, const State& state);

    protected:
        virtual void streamOutputOperator(std::ostream& out) const = 0;

        Document& _document;

    private:
        TransitionType transitionType;

        virtual void publishImplementation() = 0;
        virtual void returnDocAfterReviewImplementation() = 0;
        virtual void expireImplementation() = 0;
    };

    inline std::ostream& operator<<(std::ostream& out, const State& state) {
        state.streamOutputOperator(out);
        return out;
    }
}
