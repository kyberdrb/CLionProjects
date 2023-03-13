//
// Created by laptop on 3/12/23.
//

#pragma once

#include "State.h"

class Moderation : public State {
public:
    explicit Moderation(Document& document) :
        State(document)
    {}

    void publish() override;

    ~Moderation() override = default;

protected:
    void streamOutputOperator(std::ostream& out) const override;
};
