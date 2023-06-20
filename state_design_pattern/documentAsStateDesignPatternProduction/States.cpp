//
// Created by laptop on 6/13/23.
//

#include "States.h"

#include "Draft.h"
#include "Moderation.h"
#include "Published.h"

namespace production {
    //std::unique_ptr<States> States::_statesSingleton = std::make_unique<States>();

//    States::States() = default;
    States::States(Document& document)
    :
        _document(document)
    {
        this->states.at(StateType::DRAFT) = std::make_unique<Draft>(this->_document);
        this->states.at(StateType::MODERATION) = std::make_unique<Moderation>(this->_document);
        this->states.at(StateType::PUBLISHED) = std::make_unique<Published>(this->_document);
    }

//    States& States::createInstance() {
//        return *this->_statesSingleton;
//    }

    State& States::getPublishedState() {
        return *(this->states.at(StateType::PUBLISHED));
    }
}
