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
                const State& sourceState,
                const State& destinationState)
        :
            _sourceState(sourceState),
            _destinationState(destinationState)
        {}

        friend std::ostream& operator<<(std::ostream& out, const Transition& transition) {
            out
                << "State change:\t\t\t"
                << transition._sourceState
                << " -> "
                << transition._destinationState
                << '\n';

            return out;
        }

    private:
        const State& _sourceState;
        const State& _destinationState;
    };
}
