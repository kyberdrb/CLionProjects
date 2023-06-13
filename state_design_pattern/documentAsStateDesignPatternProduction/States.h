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

    class States {
    public:
        //States& getInstance();

        //State& getState(StateType stateType);

    private:
        States() = default;

        std::unique_ptr<States> _statesSingleton;
        std::map<StateType, State> states;
    };
}
