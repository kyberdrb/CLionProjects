//
// Created by laptop on 6/13/23.
//

#pragma once

#include "StateType.h"

#include <memory>
#include <map>

//#include "State.h"
namespace production {
    class State;
    class Document;

    class States {
    public:


        //State& getState(StateType stateType);

        State& getPublishedState();

    private:
        States(Document& document);
//        States& createInstance();
//
        Document& _document;
        static std::unique_ptr<States> _statesSingleton;
        std::map<StateType, std::unique_ptr<State>> states;
    };
}
