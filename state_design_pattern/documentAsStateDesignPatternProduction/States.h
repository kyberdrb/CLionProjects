//
// Created by laptop on 6/13/23.
//

#pragma once

#include "StateType.h"

#include <memory>
#include <map>

namespace production {
    class State;
    class Document;

    class States {
    public:
        States(Document& document);

        State& getInitialState();
        State& getDraftState();
        State& getModerationState();
        State& getPublishedState();

    private:
        Document& _document;
        std::map<StateType, std::unique_ptr<State>> states;
    };
}
