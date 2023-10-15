//
// Created by laptop on 4/6/23.
//

#pragma once

#include "State.h"

namespace production {
    class Moderation : public State {
    public:
        explicit Moderation(Document& document)
            : State(document)
        {}

        void publishImplementation() override;
        void returnDocAfterReviewImplementation() override;
        void expireImplementation() override;

        ~Moderation() override = default;

    protected:
        void streamOutputOperator(std::ostream& out) const override;
    };
}
