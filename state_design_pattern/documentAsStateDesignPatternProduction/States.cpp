//
// Created by laptop on 6/13/23.
//

#include "States.h"

#include "InitialState.h"
#include "Draft.h"
#include "Moderation.h"
#include "Published.h"

namespace production {
    // Can't do Singleton like this: _document reference cannot be accessed without an instance,
    //  but static variable cannot have an instance
//    std::unique_ptr<States> States::_statesSingleton = std::make_unique<States>(_document);

//    States::States() = default;
    States::States(Document& document)
    :
        _document(document)
    {
        this->states.emplace(StateType::INIT, std::make_unique<InitialState>(this->_document));

//        this->states[StateType::DRAFT] = std::make_unique<Draft>(this->_document);
        this->states.emplace(StateType::DRAFT, std::make_unique<Draft>(this->_document));

        this->states.emplace(StateType::MODERATION, std::make_unique<Moderation>(this->_document));
        this->states.emplace(StateType::PUBLISHED, std::make_unique<Published>(this->_document));
    }

//    States& States::createInstance() {
//        return *this->_statesSingleton;
//    }

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

//    State& State::operator=(const State& other) noexcept{
//        other._document = this->_document;
//    }
}
