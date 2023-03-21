//
// Created by AndrejŠišila on 3/9/2023.
//

#pragma once

#include "State.h"

// The 'ConcreteState1' class equivalent in the reference State design pattern UML class diagram
class Draft : public State {
public:
    explicit Draft(Document& document) :
        State(document)
    {}

    void publish() override;
    void returnDocAfterReview() override;
    void expire() override;

    ~Draft() override = default;

protected:
    void streamOutputOperator(std::ostream& out) const override;
};
