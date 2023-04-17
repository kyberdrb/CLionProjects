//
// Created by laptop on 4/17/23.
//

#pragma once

#include <ostream>
#include "State.h"

namespace production {
    class Transition {
    public:
        Transition(
                const State& sourceState,
                const State& destinationState)
        :
            _sourceState(sourceState),
            _destinationState(destinationState)
        {}

        void setTransitionType(const std::string transitionType) {
            this->_transitionType = transitionType;
        }

        friend std::ostream& operator<<(std::ostream& out, const Transition& transition) {
            out
                << "Transition type: "
                << transition._transitionType
                << '\n'

                << "State change:\t\t\t"
                << transition._sourceState
                << " -> "
                << transition._destinationState
                << '\n';

            return out;
        }

    private:
        std::string _transitionType;
        const State& _sourceState;
        const State& _destinationState;
    };
}
