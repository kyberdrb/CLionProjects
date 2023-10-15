//
// Created by admin on 21. 6. 2023.
//

#pragma once

#include "State.h"

namespace production {

    /// A formal state to initialize the reference member attribute _previousState to a valid value
    class InitialState : public State {
    public:
        explicit InitialState(Document& document) :
            State(document)
        {}

        void publishImplementation() override;
        void returnDocAfterReviewImplementation() override;
        void expireImplementation() override;

        ~InitialState() override = default;

    protected:
        void streamOutputOperator(std::ostream& out) const override;
    };
}
