//
// Created by AndrejŠišila on 3/9/2023.
//

#pragma once

#include "State.h"

class Draft : public State {
public:
    explicit Draft(Document& document) :
        State(document)
    {}

    void publish() override;

    ~Draft() override = default;

protected:
    void streamOutputOperator(std::ostream& out) const override;
};
