//
// Created by laptop on 6/13/23.
//

#include "States.h"

#include "InitialState.h"
#include "Draft.h"
#include "Moderation.h"
#include "Published.h"

namespace production {
    States::States(Document& document)
    :
        _document(document)
    {
        // Adding elements to std::map with emplace function
        this->states.emplace(StateType::INIT, std::make_unique<InitialState>(this->_document));

        // Adding elements to std::map with square brackets operator
        this->states[StateType::DRAFT] = std::make_unique<Draft>(this->_document);
//        this->states.emplace(StateType::DRAFT, std::make_unique<Draft>(this->_document));

        this->states.emplace(StateType::MODERATION, std::make_unique<Moderation>(this->_document));
        this->states.emplace(StateType::PUBLISHED, std::make_unique<Published>(this->_document));
    }

    State& States::getInitialState() {
        return *(this->states.at(StateType::INIT));
    }

    State& States::getDraftState() {
        return *(this->states.at(StateType::DRAFT));
    }

    State& States::getModerationState() {
        return *(this->states.at(StateType::MODERATION));
    }

    State& States::getPublishedState() {
        return *(this->states.at(StateType::PUBLISHED));
    }
}
