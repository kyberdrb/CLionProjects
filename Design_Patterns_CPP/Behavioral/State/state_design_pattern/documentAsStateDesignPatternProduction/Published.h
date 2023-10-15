//
// Created by laptop on 4/7/23.
//

#pragma once

#include "State.h"

#include "Document.h"

namespace production {
    class Published : public State {
    public:
        explicit Published(Document& document) :
            State(document)
        {}
        
        void publishImplementation() override;
        void returnDocAfterReviewImplementation() override;
        void expireImplementation() override;

        ~Published() override = default;

    protected:
        void streamOutputOperator(std::ostream& out) const override;
    };
}
