//
// Created by laptop on 3/12/23.
//

#pragma once

#include "State.h"

// The 'ConcreteState3' class equivalent in the reference State design pattern UML class diagram
class Published : public State {
public:
    explicit Published(Document& document) :
        State(document)
    {}

    void publish() override;
    void returnDocAfterReview() override;
    void expire() override;

    ~Published() override = default;

protected:
    virtual void streamOutputOperator(std::ostream& out) const override;
};
