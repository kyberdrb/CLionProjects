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
//        friend std::unique_ptr<States> std::make_unique<States>();

        State& getDraftState();
        State& getModerationState();
        State& getPublishedState();

    public:
        States(Document& document);
    private:
//        static States& createInstance();

        Document& _document;
        static std::unique_ptr<States> _statesSingleton;
        std::map<StateType, std::unique_ptr<State>> states;
    };
}
