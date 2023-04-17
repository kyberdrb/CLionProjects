//
// Created by laptop on 4/17/23.
//

#pragma once

#include "State.h"
#include "TransitionType.h"

#include <ostream>

namespace production {
    class Transition {
    public:
        Transition(
                TransitionType transitionType,
                const State& sourceState,
                const State& destinationState)
        :
            _transitionType(transitionType),
            _sourceState(sourceState),
            _destinationState(destinationState)
        {}

        friend std::ostream& operator<<(std::ostream& out, const Transition& transition) {
            out << "Transition type: ";

            if (transition._transitionType == TransitionType::PUBLISH) {
                out << "publish";
            }
            else if (transition._transitionType == TransitionType::RETURN_DOC_AFTER_REVIEW) {
                out << "returnDocAfterReview";
            }
            else if (transition._transitionType == TransitionType::EXPIRE) {
                out << "expire";
            }

            out << '\n';

            out
                << "State change:\t\t\t"
                << transition._sourceState
                << " -> "
                << transition._destinationState
                << '\n';

            return out;
        }

    private:
        TransitionType _transitionType;
        const State& _sourceState;
        const State& _destinationState;
    };
}
