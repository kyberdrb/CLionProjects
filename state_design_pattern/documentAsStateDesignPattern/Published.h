//
// Created by laptop on 3/12/23.
//

#pragma once

#include "State.h"

class Published : public State {
public:
    explicit Published(Document& document) :
        State(document)
    {}

    virtual void publish() override;

    ~Published() override = default;

protected:
    virtual void streamOutputOperator(std::ostream& out) const override;
};
