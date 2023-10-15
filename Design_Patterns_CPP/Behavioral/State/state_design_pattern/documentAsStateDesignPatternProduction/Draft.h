//
// Created by AndrejŠišila on 3/30/2023.
//

#pragma once

#include "State.h"

namespace production {
    class Draft : public State {
    public:
        explicit Draft(Document& document) :
                State(document)
        {}

        void publishImplementation() override;
        void returnDocAfterReviewImplementation() override;
        void expireImplementation() override;

        ~Draft() override = default;

    protected:
        void streamOutputOperator(std::ostream& out) const override;
    };
}