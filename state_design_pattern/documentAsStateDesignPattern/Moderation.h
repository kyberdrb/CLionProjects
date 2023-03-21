//
// Created by laptop on 3/12/23.
//

#pragma once

#include "State.h"

// The 'ConcreteState2' class equivalent in the reference State design pattern UML class diagram
class Moderation : public State {
public:
    explicit Moderation(Document& document) :
        State(document)
    {}

    void publish() override;
    void returnDocAfterReview() override;
    void expire() override;

    ~Moderation() override = default;

protected:
    void streamOutputOperator(std::ostream& out) const override;
};
